#ifndef _MP_H_
#define _MP_H_

#define CUR_PLAYER -1
#define MB_MAX_PLAYERS 4

#include "ultra64.h"
#include "PR/mbi.h"

typedef struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
} Vec;

/* Buttons */

#define CONT_A      0x8000
#define CONT_B      0x4000
#define CONT_G	    0x2000
#define CONT_START  0x1000
#define CONT_UP     0x0800
#define CONT_DOWN   0x0400
#define CONT_LEFT   0x0200
#define CONT_RIGHT  0x0100
#define CONT_L      0x0020
#define CONT_R      0x0010
#define CONT_E      0x0008
#define CONT_D      0x0004
#define CONT_C      0x0002
#define CONT_F      0x0001

/* Nintendo's official button names */

#define A_BUTTON	CONT_A
#define B_BUTTON	CONT_B
#define L_TRIG		CONT_L
#define R_TRIG		CONT_R
#define Z_TRIG		CONT_G
#define START_BUTTON	CONT_START
#define U_JPAD		CONT_UP
#define L_JPAD		CONT_LEFT
#define R_JPAD		CONT_RIGHT
#define D_JPAD		CONT_DOWN
#define U_CBUTTONS	CONT_E
#define L_CBUTTONS	CONT_C
#define R_CBUTTONS	CONT_F
#define D_CBUTTONS	CONT_D

#define OM_GET_WORK_PTR(object, type) ((type *)(&((object)->work[0])))
#define OM_GET_DATA_PTR(object, type) ((type *)(((object)->data)))

struct om_obj_data;
typedef void (*omObjFunc)(struct om_obj_data *);

typedef struct om_obj_data {
/* 0x00 */ u16 stat;
/* 0x02 */ s16 next_idx_alloc;
/* 0x04 */ s16 prio;
/* 0x06 */ s16 prev;
/* 0x08 */ s16 next;
/* 0x0A */ s16 next_idx;
/* 0x0C */ s16 group;
/* 0x0E */ u16 group_idx;
/* 0x10 */ u32 unk10;
/* 0x14 */ omObjFunc func;
/* 0x18 */ Vec trans;
/* 0x24 */ Vec rot;
/* 0x30 */ Vec scale;
/* 0x3C */ u16 mdlcnt;
/* 0x40 */ s16* model;
/* 0x44 */ u16 mtncnt;
/* 0x48 */ s16* motion;
/* 0x4C */ u32 work[4];
/* 0x5C */ void* data;
} omObjData;

typedef struct Object_s {
/* 0x00 */ struct Object_s *prev;
/* 0x04 */ struct Object_s *next;
/* 0x08 */ u8 unk8;
/* 0x09 */ s8 unk9;
/* 0x0A */ u16 flags;
/* 0x0C */ Vec coords;
// Three Vec groups (Scale?, Rotation?, Position?)
/* 0x18 */ Vec unk18;
/* 0x24 */ Vec scale;
/* 0x30 */ Vec unk30;
/* 0x3C */ omObjData* omObj1;
/* 0x40 */ omObjData* omObj2;
/* 0x44 */ s16 unk44;
/* 0x46 */ s16 unk46;
} Object; //sizeof 0x48

typedef struct PartnerStats {
/* 0x2C */ s8 frontPoweredUp;
/* 0x2D */ s8 backPoweredUp;
/* 0x2E */ s8 frontHp;
/* 0x2F */ s8 backHp;
/* 0x30 */ s8 frontCost;
/* 0x31 */ s8 backCost;
/* 0x32 */ s8 frontPower;
/* 0x33 */ s8 backPower;
/* 0x34 */ s8 frontID;
/* 0x35 */ s8 backID;
} PartnerStats;

typedef struct {
/* 0x2C */ s8 hatenaPrize;  // happening-space star
/* 0x2D */ s8 redPrize;
/* 0x2E */ s8 bluePrize;
/* 0x2F */ s8 eventPrize;
/* 0x30 */ s8 kupaPrize;
/* 0x31 */ s8 battlePrize;
/* 0x32 */ s8 itemPrize;
/* 0x33 */ s8 bankPrize;
/* 0x34 */ s8 gamblePrize;
/* 0x35 */ s8 duelNo;
} PrizeStats;

typedef struct GwPlayer_s {
/* 0x00 */ u8 group;
/* 0x01 */ u8 cpu_difficulty;
/* 0x02 */ u8 pad;
/* 0x03 */ u8 chr;
/* 0x04 */ u8 stat;
/* 0x05 */ char unk_05;
/* 0x06 */ s16 gameCoin;
/* 0x08 */ s16 bonusCoin;
/* 0x0A */ s16 coin;
/* 0x0C */ s16 checkCoin;
/* 0x0E */ s8 star;
/* 0x0F */ s8 clink;
/* 0x10 */ s8 cidx;
/* 0x11 */ s8 nlink;
/* 0x12 */ s8 nidx;
/* 0x13 */ s8 nnlink;
/* 0x14 */ s8 nnidx;
/* 0x15 */ s8 blink; //b link
/* 0x16 */ s8 bidx;
/* 0x17 */ u8 rev; //related to reverse mushroom flags
/* 0x18 */ s8 itemNo[3];
/* 0x1B */ s8 itemTurn;
/* 0x1C */ u8 color;
/* 0x1D */ u8 turn;
/* 0x1E */ char unk_1E[2]; //likely padding
/* 0x20 */ void* unk_20;
/* 0x24 */ Object* player_obj;
/* 0x28 */ s16 gamePrize; //minigame star
/* 0x2A */ s16 coinPrize; //coin star
/* 0x2C */ union {
    PrizeStats      prize;
    PartnerStats    partners;
} stats;
/* 0x36 */ char unk_36[2];
} GW_PLAYER; //sizeof 0x38;

extern GW_PLAYER GwPlayer[4];

#endif //_MP_H_