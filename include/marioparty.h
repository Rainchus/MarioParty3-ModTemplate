#ifndef _MP_H_
#define _MP_H_

#define CUR_PLAYER -1
#define MB_MAX_PLAYERS 4

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))

#include "ultra64.h"
#include "PR/mbi.h"

enum SPACE_TYPES {
    SPACE_NONE = 0,
    SPACE_BLUE = 1,
    SPACE_RED = 2,
    SPACE_UNK = 3,
    SPACE_HAPPENING = 4,
    SPACE_CHANCE_TIME = 5,
    SPACE_ITEM = 6,
    SPACE_BANK = 7,
    SPACE_START = 8,
    SPACE_BATTLE = 9,
    SPACE_UNK2 = 10,
    SPACE_UNK3 = 11,
    SPACE_BOWSER = 12,
    SPACE_ARROW = 13,
    SPACE_STAR = 14,
    SPACE_GAME_GUY = 15,
    //custom space type indexes here
    SPACE_MUSHROOM,
    SPACE_TYPES_MAX
};

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

typedef struct GW_SYSTEM {
    /* 0x00 - 800CD058 */ s8 playMode; //0x01 - Lite Play pause screen, 0x04 - Story Play pause screen
    /* 0x01 - 800CD059 */ s8 current_board_index;
    /* 0x02 - 800CD05A */ s8 total_turns;
    /* 0x03 - 800CD05B */ s8 current_turn;
    /* 0x04 - 800CD05C */ s8 current_game_length; // 00=Lite Play,01=Standard Play,02=Full Play,03=Custom Play
    /* 0x05 - 800CD05D */ s8 current_star_spawn; // Index of star space (index into star_spawn_indices)
    /* 0x06 - 800CD05E */ s8 star_spawn_indices[7];
    /* 0x0D - 800CD065 */ s8 unk_0D;
    /* 0x0E - 800CD066 */ s8 unk_0E;
    /* 0x0F - 800CD067 */ s8 current_player_index;
    /* 0x10 - 800CD068 */ s8 minigame_index;
    /* 0x11 - 800CD069 */ s8 current_space_index;
    /* 0x12 - 800CD06A */ s8 save_mode; //00 - Save every turn, 01 - Save this turn, 02 - Don't save
    /* 0x13 - 800CD06B */ s8 show_minigame_explanations; //00 - show, 01 - hide
    /* 0x14 - 800CD06C */ s8 message_speed; //00 - Fast, 01 - Normal, 02 - Slow
    /* 0x15 - 800CD06D */ s8 walk_speed; //00 - Fast, 01 - Normal, 02 - Slow
    /* 0x16 - 800CD06E */ s8 show_com_minigames; //00 - Show COM minigame, 01 - Hide COM minigame
    /* 0x17 - 800CD06F */ char unk_17[0x27]; //unknown
    union {
        /* 0x3E - 800CD096 */ s16 halfWordBytes[9]; //bytes related to storing information for each board
        /* 0x3E - 800CD096 */ s8 bytes[18]; //bytes related to storing information for each board
    } boardData;
    /* 0x50 - 800CD0A8 */ u16 cur_player_used_item; //1 if player already used an item this turn
    /* 0x52 - 800CD0AA */ s16 unk_52;
    /* 0x54 - 800CD0AC */ s16 forceShopHost; //0 is toad, baby bowser is 1
    /* 0x56 - 800CD0AE */ s16 slow_dice_flags;
    /* 0x58 - 800CD0B0 */ s16 unk_58;
    /* 0x5A - 800CD0B2 */ s16 playerIndexVisitingBowser;
    /* 0x5C - 800CD0B4 */ u16 bank_coins;
    /* 0x5E - 800CD0B6 */ u8 data_flags[8]; //unknown what this is, unknown size
    /* 0x66 - 800CD0B8 */ u8 unk_66[0x3E];
} GW_SYSTEM; //sizeof 0xA4

typedef struct SpaceData {
/* 0x00 */ s8 unk_00;
/* 0x01 */ u8 space_type; // enum board_space_type
/* 0x02 */ u16 unk_02;
/* 0x04 */ s32 unk_04;
/* 0x08 */ Vec coords;
/* 0x14 */ Vec rot;
/* 0x20 */ void* event_list;
} SpaceData; //sizeof 0x24

extern s16 D_800CDD58_CE958;
extern s16 D_800CDD64_CE964;
extern Gfx* mp3_gMainGfxPos;
extern GW_SYSTEM GwSystem;
extern GW_PLAYER GwPlayer[4];
extern s8 gCurrentPlayerIndex;
extern u8 D_8010570E_11932E_shared_board;

extern u16 gTotalSpaces;

SpaceData* MBMasuGet(s16 arg0);
void* HuMemMemoryAllocTemp(u32 size);
void HuMemMemoryFreeTemp(void *ptr);
u16 func_8004D6AC_4E2AC(s32, s32, s32);
void func_80012640_13240(s16, Gfx**);
void func_800127C4_133C4(s16, Gfx**);
void func_80089980_8A580(Mtx*, Mtx*);
void func_80017C10_18810(Mtx*, f32, f32, f32);
void func_800185A4_191A4(Mtx*, f32);
void func_80017CD0_188D0(Mtx*, f32, f32, f32);
void func_800898F0_8A4F0(Mtx*, Mtx*);
void func_8004D6E8_4E2E8(s16);
void DataClose(void* data);
void* DataRead(s32 dirAndFile);
GW_PLAYER* MBGetPlayerStruct(s32 playerIndex);
s16 HuAudFXPlay(s16 seId);

#endif //_MP_H_