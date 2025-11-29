// #include "marioparty.h"
// #include <ultra64.h>

// #define SRAM_START_ADDR  0x08000000
// #define SRAM_SIZE        (16 * 1024)

// OSMesgQueue sramMesgQueue = {0};
// OSMesg sramMessages[1] = {0};
// OSPiHandle sramHandle = {0};

// u8 saveData[SRAM_SIZE] __attribute__((aligned(16))) = {0};

// extern OSPiHandle* D_800CDD50_CE950;
// extern OSMesgQueue D_800B29F0_B35F0;
// extern void* D_800B2A08_B3608;
// extern void* D_800CCFA8_CDBA8;
// extern OSMesgQueue D_800D6B28_D7728;

// //custom osEPiLinkHandle
// s32 osEPiLinkHandle(OSPiHandle* EPiHandle) {
// 	u32 saveMask = __osDisableInt();

// 	EPiHandle->next = __osPiTable;
// 	__osPiTable = EPiHandle;

// 	__osRestoreInt(saveMask);
// 	return 0;
// }

// OSPiHandle* syDmaSramPiInit(void)
// {
//     if (sramHandle.baseAddress == PHYS_TO_K1(PI_DOM2_ADDR2))
//     { 
//         return &sramHandle; 
//     }
//     sramHandle.type        = DEVICE_TYPE_SRAM;
//     sramHandle.baseAddress = PHYS_TO_K1(PI_DOM2_ADDR2);
//     sramHandle.latency     = 5;
//     sramHandle.pulse       = 12;
//     sramHandle.pageSize    = 13;
//     sramHandle.relDuration = 2;
//     sramHandle.domain      = PI_DOMAIN2;
//     sramHandle.speed       = 0;
//     _bzero(&sramHandle.transferInfo, sizeof(sramHandle.transferInfo)); //?
//     osEPiLinkHandle(&sramHandle);

//     return &sramHandle;
// }

// void sramInit(void) {
//     syDmaSramPiInit();
//     osCreateMesgQueue(&sramMesgQueue, sramMessages, 1);
// }

// void syDmaCopy(OSPiHandle *handle, u32 phys, u32 virtual, size_t size, u8 direction)
// {
//     OSIoMesg mesg;

//     if (direction == OS_WRITE) {
//         osWritebackDCache((void*)virtual, size);
//     } else {
//         osInvalDCache((void*)virtual, size);
//     }
    
//     mesg.hdr.pri      = OS_MESG_PRI_NORMAL;
//     mesg.hdr.retQueue = &sramMesgQueue;
//     mesg.size         = 0x10000;

//     while (size > 0x10000)
//     {
//         mesg.dramAddr = (void*)virtual;
//         mesg.devAddr  = phys;


//         osEPiStartDma(handle, &mesg, direction);
//         osRecvMesg(&sramMesgQueue, NULL, OS_MESG_BLOCK);
//         size -= 0x10000;
//         phys += 0x10000;
//         virtual += 0x10000;
//     }
//     if (size != 0) 
//     {
//         mesg.dramAddr = (void*)virtual;
//         mesg.devAddr  = phys;
//         mesg.size     = size;

//         osEPiStartDma(handle, &mesg, direction);
//         osRecvMesg(&sramMesgQueue, NULL, OS_MESG_BLOCK);
//     }
// }

// void syDmaReadSram(u32 rom_src, void *ram_dst, size_t size)
// {
//     syDmaCopy(&sramHandle, rom_src, (u32)ram_dst, size, OS_READ);
// }

// void syDmaWriteSram(void *ram_src, u32 rom_dst, size_t size)
// {
//     syDmaCopy(&sramHandle, rom_dst, (u32)ram_src, size, OS_WRITE);
// }


// void sramTestWrite(void) {
//     s32 i;

//     for (i = 0; i < ARRAY_COUNT(saveData); i++) {
//         saveData[i] = i+6;
//     }

//     syDmaWriteSram(saveData, 0, 0x40);
//     syDmaReadSram(0, 0x807FFFC0, 0x40);
// }

// void sramTestRead(void) {
//     syDmaReadSram(0, saveData, SRAM_SIZE);
// }

// void dmaAndSramInit(void) {
//     osCreatePiManager(OS_PRIORITY_PIMGR, &D_800D6B28_D7728, &D_800CCFA8_CDBA8, 0x2A);
//     D_800CDD50_CE950 = osCartRomInit();
//     osCreateMesgQueue(&D_800B29F0_B35F0, &D_800B2A08_B3608, 0xA);
//     sramInit();
// }
