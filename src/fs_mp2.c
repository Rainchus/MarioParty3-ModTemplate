#include "marioparty.h"
#include "fs_mp2.h"

FSContext mp2fs = {0};

extern u8 _mp2_archive_start[];

void InitMp2FS(void) {
    FS_Init(&mp2fs, _mp2_archive_start);
}


// Init MP2 filesystem context
void FS_Init(FSContext* fs, u8* archiveROMPtr)
{
    s32 size;
    void* dirTable;

    fs->romBase = archiveROMPtr;

    // Read archive header
    dmaRead(fs->romBase, (u8*)&fs->archive, 16);

    fs->dirCount = fs->archive.count;
    size = fs->dirCount * 4;

    // Allocate directory table
    dirTable = HuMemMemoryAllocPerm(size);

    //if this is NULL, it's likely mp2 rom is missing
    if (dirTable == NULL) {
        return;
    }
    fs->dirTable = dirTable;
    dmaRead(fs->romBase + 4, (u8*)fs->dirTable, size);

    // Initial directory == top-level
    fs->curDirBase = fs->romBase;
    fs->fileCount  = fs->dirCount;
    fs->fileTable  = fs->dirTable;
}

// Init directory inside archive
void FS_DirInit(FSContext* fs, s32 dirIndex)
{
    s32 size;
    u8* dirPtr = fs->romBase + fs->dirTable[dirIndex];

    if (fs->curDirBase != dirPtr) {
        if (fs->curDirBase != fs->romBase) {
            HuMemMemoryFreePerm(fs->fileTable);
        }

        fs->curDirBase = dirPtr;

        dmaRead(fs->curDirBase, (u8*)&fs->archive, 16);

        fs->fileCount = fs->archive.count;
        size = fs->fileCount * 4;

        fs->fileTable = HuMemMemoryAllocPerm(size);
        dmaRead(fs->curDirBase + 4, (u8*)fs->fileTable, size);
    }
}

// Read file header at fileIndex
void FS_Info(FSContext* fs, s32 fileIndex, HuFileInfo* info)
{
    u8* src = fs->curDirBase + fs->fileTable[fileIndex];

    // Read header
    dmaRead(src, (u8*)&fs->archive, 16);

    info->bytes = src + 8;
    info->size = fs->archive.count;
    info->compType = fs->archive.offsets[0];
}

// Decode file in perm heap
void* FS_Decode(FSContext* fs, s32 fileIndex)
{
    HuFileInfo info;
    void* out;

    FS_Info(fs, fileIndex, &info);

    out = HuMemMemoryAllocPerm((info.size + 1) & -2);
    if (out)
        DecodeData(info.bytes, out, info.size, info.compType);

    return out;
}

// Read by packed dir/file (same format as MP3)
void* FS_Read(FSContext* fs, s32 dirFile)
{
    s32 dir  = dirFile >> 16;
    s32 file = dirFile & 0xFFFF;

    if (dir < fs->dirCount) {
        FS_DirInit(fs, dir);

        if (file < fs->fileCount)
            return FS_Decode(fs, file);
    }

    return NULL;
}