#ifndef FS_MP2_H
#define FS_MP2_H

#include "malloc.h"
#include "decode.h"
#include "data.h"

typedef struct {
    u8*   romBase;       // base pointer of MP2 archive in ROM

    s32   dirCount;
    s32*  dirTable;

    u8*   curDirBase;    // current directory table base
    s32   fileCount;
    s32*  fileTable;

    HuArchive archive;   // local copy of the archive header
} FSContext;

void FS_Init(FSContext* fs, u8* archiveROMPtr);

void FS_DirInit(FSContext* fs, s32 dirIndex);
void FS_Info(FSContext* fs, s32 fileIndex, HuFileInfo* info);

void* FS_Read(FSContext* fs, s32 dirFile);
void* FS_Decode(FSContext* fs, s32 fileIndex);

#endif