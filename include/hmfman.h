#ifndef _HMFMAN_H
#define _HMFMAN_H

#define HU3D_MODEL_MAX 128

#include "ultra64.h"

typedef struct {
    /* 0x00 */ Gfx* unk00;
    /* 0x04 */ Gfx* unk04[3]; // unknown length
    /* 0x10 */ void* unk10;
    /* 0x14 */ void* unk14;
} HmfModelData_Unk64_Unk3C_Struct; // Size unknown

typedef struct {
    /* 0x00 */ u8 unk00;
    /* 0x01 */ char unk01[0x33];
} HmfModelData_Unk64_Unk60_Unk54_Struct; // Size 0x34

typedef struct {
    /* 0x00 */ char unk00[0x22];
    /* 0x22 */ s16 unk22;
    /* 0x24 */ char unk24[4];
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ char unk2C[0x24];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ HmfModelData_Unk64_Unk60_Unk54_Struct* unk54;
    /* 0x58 */ char unk58[0x10];
} HmfModelData_Unk64_Unk60_Struct; // Size 0x68

typedef struct {
    char unk00[0x18];
} HmfModelData_Unk64_Unk8C_Struct; // Size 0x18

typedef struct {
    /* 0x00 */ char unk00[2];
    /* 0x02 */ s16 unk02;
    /* 0x04 */ char unk04[4];
    /* 0x08 */ s32 unk08;
} HmfModelData_Unk64_Unk98_Struct; // Size unknown

typedef struct {
    /* 0x00 */ u8 unk00;
    /* 0x01 */ s8 unk01;
    /* 0x02 */ char unk02[8];
    /* 0x0A */ s8 unk0A;
    /* 0x0B */ s8 unk0B;
    /* 0x0C */ s8 unk0C;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ char unk12[2];
    /* 0x14 */ s16 unk14;
    /* 0x16 */ char unk16[0x22];
    /* 0x38 */ s32 unk38;
    /* 0x3C */ HmfModelData_Unk64_Unk3C_Struct* unk3C;
    /* 0x40 */ char unk40[4];
    /* 0x44 */ Vtx* unk44[1]; // unknown length
    /* 0x48 */ char unk48[8];
    /* 0x50 */ void* unk50;
    /* 0x54 */ char unk54[0xC];
    /* 0x60 */ HmfModelData_Unk64_Unk60_Struct* unk60;
    /* 0x64 */ char unk64[0x20];
    /* 0x84 */ s32 unk84;
    /* 0x88 */ char unk88[4];
    /* 0x8C */ HmfModelData_Unk64_Unk8C_Struct* unk8C;
    /* 0x90 */ HmfModelData_Unk64_Unk8C_Struct* unk90;
    /* 0x94 */ HmfModelData_Unk64_Unk8C_Struct* unk94;
    /* 0x98 */ HmfModelData_Unk64_Unk98_Struct* unk98;
    /* 0x9C */ char unk9C[4];
    /* 0xA0 */ s32 unkA0;
    /* 0xA4 */ f32 unkA4;
    /* 0xA8 */ f32 unkA8;
    /* 0xAC */ f32 unkAC;
    /* 0xB0 */ char unkB0[4];
    /* 0xB4 */ s32 unkB4;
    /* 0xB8 */ char unkB8[0x10];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ char unkCC[4];
    /* 0xD0 */ s32 unkD0;
    /* 0xD4 */ char unk_D4[8];
} HmfData; // sizeof 0xDC

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ char unk02[2];
    /* 0x04 */ u16 unk04;
    /* 0x08 */ char unk08[0x10];
    /* 0x18 */ void (*unk18)(s16);
} HmfModelData_UnkBC_Struct; // Size unknown

typedef struct {
    /* 0x00 */ s8 unk00;
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 unk03;
    /* 0x04 */ u8 unk04;
    /* 0x05 */ u8 unk05;
    /* 0x06 */ u8 unk06;
    /* 0x07 */ s8 unk07;
    /* 0x08 */ u8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 unk0A;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ char unk12[6];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ Vec pos;
    /* 0x28 */ Vec rot;
    /* 0x34 */ Vec scale;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48;
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ f32 unk50;
    /* 0x54 */ f32 unk54;
    /* 0x58 */ f32 unk58;
    /* 0x5C */ f32 unk5C;
    /* 0x60 */ f32 unk60;
    /* 0x64 */ HmfData* hmf;
    /* 0x68 */ char unk68[8]; // 68 => 60 has size 0x68
    /* 0x70 */ void (*unk70)(Gfx**, s32, s32);
    /* 0x74 */ f32 mtx[16];
    /* 0xB4 */ s32 unkB4;
    /* 0xB8 */ char unkB8[4];
    /* 0xBC */ HmfModelData_UnkBC_Struct* unkBC;
} HmfModel; // Size 0xC0

#endif //_HMFMAN_H