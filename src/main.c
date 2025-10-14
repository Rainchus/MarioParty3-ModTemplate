#include "marioparty.h"

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))

void* DataRead(s32 dirAndFile);
s16 func_80055810_56410(void*);
void DataClose(void* data);
void HuSprKill(s16);

GW_PLAYER* MBGetPlayerStruct(s32 playerIndex);
s32 func_800DEB2C_F274C_shared_board(s32);
void func_800EC590_1001B0_shared_board(s32 arg0, s32 arg1);
void func_800DCA64_F0684_shared_board(s32);
void FixUpPlayerItemSlots(s32 arg0);
void func_800DE9AC_F25CC_shared_board(s32, s32);
void func_800FF900_113520_shared_board(s16, s16);
void func_800DC128_EFD48_shared_board(s32);
void HuPrcSleep(s32 time);

//item function definitions
s32 func_800E2974_F6594_shared_board(void);
s32 func_800E29E8_F6608_shared_board(void);
s32 func_800E2B24_F6744_shared_board(void);
s32 func_800E2B4C_F676C_shared_board(void);
s32 func_800E2BCC_F67EC_shared_board(void);
s32 func_800E2C4C_F686C_shared_board(void);
s32 func_800E2E28_F6A48_shared_board(void);
s32 func_800E2CC4_F68E4_shared_board(void);
s32 func_800E2C74_F6894_shared_board(void);
s32 func_800E2CEC_F690C_shared_board(void);
s32 func_800E2C9C_F68BC_shared_board(void);
s32 func_800E2F38_F6B58_shared_board(void);
s32 func_800E3074_F6C94_shared_board(void);
s32 func_800E3158_F6D78_shared_board(void);
s32 func_800E31E4_F6E04_shared_board(void);
s32 func_800E3284_F6EA4_shared_board(void);
s32 func_800E3394_F6FB4_shared_board(void);
s32 func_800E3420_F7040_shared_board(void);
s32 func_800E3448_F7068_shared_board(void);
s32 func_800E3470_F7090_shared_board(void);

enum ITEM_FUNCTIONS {
    IFUNC_BOO = 0,
    IFUNC_MAGIC_LAMP = 1,
    IFUNC_WARP_BLOCK = 2,
    IFUNC_PLUNDER_CHEST = 3,
    IFUNC_BOWSER_SUIT_BEGIN = 4,
    IFUNC_BOWSER_SUIT_END = 5,
    IFUNC_MUSHROOM = 6, //this is really the hand drag event
};

extern void (*MBItemSubFunctions[22])(void);
extern s32 D_80100F90_114BB0_shared_board;

//D_80100D60_114980_shared_board (some kind of attribute related to the die)
s32 newDiceMainFS2[] = {
    0x00130207, //normal dice
    0x00130207, //green die
    0x00130207, //red die (mushroom)
    0x00130207, //cursed die
    0x00130207, //golden die
    0x00130208, //warp block die
    //new dice blocks
    0x00130207, //duplicate of golden die for test
};

//D_80100D78_114998_shared_board
s32 newDiceMainFS[] = {
    0x001300FE, //normal dice
    0x00130206, //green die
    0x001301E7, //red die (mushroom)
    0x00130266, //cursed die
    0x001301E8, //golden die
    0x0013020B, //warp block die
    //new dice blocks
    0x00130263, //duplicate of golden die for test
};

s32 newfunc_800E29E8_F6608_shared_board(void) {
    GW_SYSTEM* system = &GwSystem;
    GW_PLAYER* player = MBGetPlayerStruct(CUR_PLAYER);

    if (func_800DEB2C_F274C_shared_board(system->current_player_index) == 3 && player->rev & 0x80) {
        player->rev &= ~0x80;
        func_800EC590_1001B0_shared_board(-1, 0x3A2B);
    } else {
        if (func_800DEB2C_F274C_shared_board(system->current_player_index) == 3) {
            func_800EC590_1001B0_shared_board(-1, 0x3A27);
        }
        if (player->rev & 0x80) {
            player->rev &= ~0x80;
            func_800EC590_1001B0_shared_board(-1, 0x3A29);
        }        
    }

    func_800DCA64_F0684_shared_board(GwSystem.current_player_index);
    MBItemSubFunctions[IFUNC_MUSHROOM]();
    GwPlayer[GwSystem.current_player_index].itemNo[D_80100F90_114BB0_shared_board] = -1;
    FixUpPlayerItemSlots(GwSystem.current_player_index);
    func_800DE9AC_F25CC_shared_board(GwSystem.current_player_index, 6); //sets 0x8010570E to 6 for sluggish dice
    func_800FF900_113520_shared_board(CUR_PLAYER, 2);
    func_800DC128_EFD48_shared_board(GwSystem.current_player_index);
    HuPrcSleep(15);
    return 1;
}

s32 (*newMBItemFunctions[])(void) = {
    func_800E2974_F6594_shared_board, //No item
    func_800E29E8_F6608_shared_board, //Mushroom
    func_800E2B24_F6744_shared_board,
    func_800E2B4C_F676C_shared_board,
    func_800E2BCC_F67EC_shared_board,
    func_800E2C4C_F686C_shared_board,
    func_800E2E28_F6A48_shared_board,
    func_800E2CC4_F68E4_shared_board,
    func_800E2C74_F6894_shared_board,
    func_800E2CEC_F690C_shared_board,
    func_800E2C9C_F68BC_shared_board,
    func_800E2F38_F6B58_shared_board,
    func_800E3074_F6C94_shared_board,
    func_800E3158_F6D78_shared_board,
    func_800E31E4_F6E04_shared_board,
    func_800E3284_F6EA4_shared_board,
    func_800E3394_F6FB4_shared_board,
    func_800E3420_F7040_shared_board,
    func_800E3448_F7068_shared_board,
    func_800E3470_F7090_shared_board,
    //
    NULL, //toad item bag function
    NULL, //baby bowser item bag function
    //new item functions start here (duplicate of basic mushroom as test)
    newfunc_800E29E8_F6608_shared_board
};

extern s16 newSpriteIDList[];
extern s32 D_80101944_115564_shared_board[];

enum ITEMS {
    ITEMS_NONE = -1,
    ITEM_MUSHROOM = 0,
    ITEM_SKELETON_KEY = 1,
    ITEM_POISON_MUSHROOM = 2,
    ITEM_REVERSE_MUSHROOM = 3,
    ITEM_CELLULAR_SHOPPER = 4,
    ITEM_WARP_BLOCK = 5,
    ITEM_PLUNDER_CHEST = 6,
    ITEM_BOWSER_PHONE = 7,
    ITEM_DUELING_GLOVE = 8,
    ITEM_LUCKY_LAMP = 9,
    ITEM_GOLDEN_MUSHROOM = 10,
    ITEM_BOO_BELL = 11,
    ITEM_BOO_REPELLANT = 12,
    ITEM_BOWSER_SUIT = 13,
    ITEM_MAGIC_LAMP = 14,
    ITEM_KOOPA_KARD = 15,
    ITEM_BARTER_BOX = 16,
    ITEM_LUCKY_CHARM = 17,
    ITEM_WACKY_WATCH = 18,
    ITEM_TOAD_ITEM_BAG = 19,
    ITEM_BABY_BOWSER_ITEM_BAG = 20,
    ITEM_SLUGGISH_SHROOM = 21,
    ITEMS_END
};


//place holder so the DMA for C code size isn't 0
int test(void) {
    return 1;
}

long newD_8010197C_11559C_shared_board[] = {
    0x0013018E,
    0x0013018F,
    0x00130190,
    0x00130191,
    0x00130192,
    0x00130193,
    0x00130194,
    0x00130195,
    0x00130196,
    0x00130197,
    0x00130198,
    0x00130199,
    0x0013019A,
    0x0013019B,
    0x0013019C,
    0x0013019E,
    0x0013019F,
    0x001301A0,
    0x001301A1,
    0x0013019D, //toad item bag
    0x001301B6, //baby bowser item bag
    //new items start here
    0x00130261,
};

long newD_801019D0_1155F0_shared_board[] = {
    0x001301A2,
    0x001301A3,
    0x001301A4,
    0x001301A5,
    0x001301A6,
    0x001301A7,
    0x001301A8,
    0x001301A9,
    0x001301AA,
    0x001301AB,
    0x001301AC,
    0x001301AD,
    0x001301AE,
    0x001301AF,
    0x001301B0,
    0x001301B2,
    0x001301B3,
    0x001301B4,
    0x001301B5,
    0x001301A2, //toad item bag entry missing
    0x001301A2, //baby bowser item bag entry missing
    //new items start here
    0x00130262,
};

//create sprite IDs for hud elements
void newfunc_800F4190_107DB0_shared_board(void) {
    void* temp_v0;
    s32 i;
    s16* spriteIDs;
    s32 sp10[2] = {0x130112, 0x130111};

    spriteIDs = newSpriteIDList;
    //unk sprite id
    temp_v0 = DataRead(0x13010F);
    spriteIDs[0] = func_80055810_56410(temp_v0);
    DataClose(temp_v0);
    
    //create player sprite ids
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        temp_v0 = DataRead(D_80101944_115564_shared_board[GwPlayer[i].chr]);
        spriteIDs[i + 1] = func_80055810_56410(temp_v0);
        DataClose(temp_v0);
    }

    //create coin and star sprite ids
    for (i = 0; i < ARRAY_COUNT(sp10); i++) {
        temp_v0 = DataRead(sp10[i]);
        spriteIDs[i + 5] = func_80055810_56410(temp_v0);
        DataClose(temp_v0);
    }

    //create placement sprite id
    temp_v0 = DataRead(0x130110);
    spriteIDs[8] = func_80055810_56410(temp_v0);
    DataClose(temp_v0);

    //create COM text sprite id
    temp_v0 = DataRead(0x1300D1);
    spriteIDs[9] = func_80055810_56410(temp_v0);
    DataClose(temp_v0);

    //create item sprite ids
    for (i = 0; i < ITEMS_END; i++) {
        temp_v0 = DataRead(newD_801019D0_1155F0_shared_board[i]);
        spriteIDs[i + 10] = func_80055810_56410(temp_v0);
        DataClose(temp_v0);
    }
}

void newfunc_800F4348_107F68_shared_board(void) {
    s32 i;
    s16* spriteIDs = newSpriteIDList;

    HuSprKill(spriteIDs[0]);
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        HuSprKill(spriteIDs[i + 1]);
    }

    for (i = 0; i < 2; i++) {
        HuSprKill(spriteIDs[i + 5]);
    }

    HuSprKill(spriteIDs[8]);
    HuSprKill(spriteIDs[9]);

    for (i = 0; i < ITEMS_END; i++) {
        HuSprKill(spriteIDs[i + 10]);
    }
}