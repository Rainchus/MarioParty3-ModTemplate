#include "marioparty.h"

//TODO: magikoopa wand still needs a way to set the inflict to a chosen player, and also needs code to remove the infliction
void setInfliction(u8 *flags, int inflictor);

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
    IFUNC_DRAG_HAND = 6, //this is really the hand drag event
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
    0x0013026C, //custom cyan sluggish dice
};

typedef struct DiceData {
/* 0x00 */ char unk_00[2];
/* 0x02 */ u8 forcedDiceValue1;
/* 0x03 */ u8 forcedDiceValue2;
/* 0x04 */ u8 forcedDiceValue3;
/* 0x02 */ char unk_05[0x47];
} DiceData; //sizeof 0x4C

extern DiceData D_800CDBD0[4];

u8 numberDisplayTimer = 0;
u8 gCurDisplayNumber = 1;

s32 SluggishNumberFreezeCheck(s32 curDisplayNumber) {
    if (D_8010570E_11932E_shared_board != 6) {
        return curDisplayNumber;
    }

    //is sluggish shroom, increment current timer
    numberDisplayTimer++;
    if (numberDisplayTimer >= 10 * 6) { //wait 10 frames * 6 (this code is ran 6 times per frame for each dice face so [1/3 second])
        gCurDisplayNumber++;
        numberDisplayTimer = 0;
    }

    if (gCurDisplayNumber >= 10) {
        gCurDisplayNumber = 0;
    }

    D_800CDBD0[gCurrentPlayerIndex].forcedDiceValue1 = gCurDisplayNumber + 1;

    return gCurDisplayNumber;

}

s32 newfunc_800E29E8_F6608_shared_board(void) {
    // GW_SYSTEM* system = &GwSystem;
    // GW_PLAYER* player = MBGetPlayerStruct(CUR_PLAYER);

    // if (func_800DEB2C_F274C_shared_board(system->current_player_index) == 3 && player->rev & 0x80) {
    //     player->rev &= ~0x80;
    //     func_800EC590_1001B0_shared_board(-1, 0x3A2B);
    // } else {
    //     if (func_800DEB2C_F274C_shared_board(system->current_player_index) == 3) {
    //         func_800EC590_1001B0_shared_board(-1, 0x3A27);
    //     }
    //     if (player->rev & 0x80) {
    //         player->rev &= ~0x80;
    //         func_800EC590_1001B0_shared_board(-1, 0x3A29);
    //     }        
    // }

    func_800DCA64_F0684_shared_board(GwSystem.current_player_index);
    MBItemSubFunctions[IFUNC_DRAG_HAND]();
    GwPlayer[GwSystem.current_player_index].itemNo[D_80100F90_114BB0_shared_board] = -1;
    FixUpPlayerItemSlots(GwSystem.current_player_index);
    func_800DE9AC_F25CC_shared_board(GwSystem.current_player_index, 6); //sets 0x8010570E to 6 for sluggish dice
    func_800FF900_113520_shared_board(CUR_PLAYER, 2); //vibrate
    func_800DC128_EFD48_shared_board(GwSystem.current_player_index); //spawn dice block for current player
    HuPrcSleep(15);
    return 1;
}

s32 newfunc_800E2B4C_F676C_shared_board(void) {
    u8* inflictedPlayerFlagAddr = &GwPlayer[1].stat;
    s32 inflictedByPlayerNo = 0;

    MBItemSubFunctions[8]();
    GwPlayer[GwSystem.current_player_index].itemNo[D_80100F90_114BB0_shared_board] = -1;
    FixUpPlayerItemSlots(GwSystem.current_player_index);
    setInfliction(inflictedPlayerFlagAddr, inflictedByPlayerNo); //player index 0 inflicts player index 1
    // MBItemSubFunctions[10]();
    return 1;
}

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
    ITEM_MAGIKOOPA_WAND = 22,
    ITEMS_END
};

s32 (*newMBItemFunctions[])(void) = {
    [ITEMS_NONE+1] = func_800E2974_F6594_shared_board, //No item
    [ITEM_MUSHROOM+1] = func_800E29E8_F6608_shared_board, //Mushroom
    [ITEM_SKELETON_KEY+1] = func_800E2B24_F6744_shared_board,
    [ITEM_POISON_MUSHROOM+1] = func_800E2B4C_F676C_shared_board, //poison mushroom
    [ITEM_REVERSE_MUSHROOM+1] = func_800E2BCC_F67EC_shared_board,
    [ITEM_CELLULAR_SHOPPER+1] = func_800E2C4C_F686C_shared_board,
    [ITEM_WARP_BLOCK+1] = func_800E2E28_F6A48_shared_board,
    [ITEM_PLUNDER_CHEST+1] = func_800E2CC4_F68E4_shared_board,
    [ITEM_BOWSER_PHONE+1] = func_800E2C74_F6894_shared_board,
    [ITEM_DUELING_GLOVE+1] = func_800E2CEC_F690C_shared_board,
    [ITEM_LUCKY_LAMP+1] = func_800E2C9C_F68BC_shared_board,
    [ITEM_GOLDEN_MUSHROOM+1] = func_800E2F38_F6B58_shared_board,
    [ITEM_BOO_BELL+1] = func_800E3074_F6C94_shared_board,
    [ITEM_BOO_REPELLANT+1] = func_800E3158_F6D78_shared_board,
    [ITEM_BOWSER_SUIT+1] = func_800E31E4_F6E04_shared_board,
    [ITEM_MAGIC_LAMP+1] = func_800E3284_F6EA4_shared_board,
    [ITEM_KOOPA_KARD+1] = func_800E3394_F6FB4_shared_board,
    [ITEM_BARTER_BOX+1] = func_800E3420_F7040_shared_board,
    [ITEM_LUCKY_CHARM+1] = func_800E3448_F7068_shared_board,
    [ITEM_WACKY_WATCH+1] = func_800E3470_F7090_shared_board,
    //
    [ITEM_TOAD_ITEM_BAG+1] = NULL, //toad item bag function
    [ITEM_BABY_BOWSER_ITEM_BAG+1] = NULL, //baby bowser item bag function
    //new item functions start here (duplicate of basic mushroom as test)
    [ITEM_SLUGGISH_SHROOM+1] = newfunc_800E29E8_F6608_shared_board,
    [ITEM_MAGIKOOPA_WAND+1] = newfunc_800E2B4C_F676C_shared_board
};

extern s16 newSpriteIDList[];
extern s32 D_80101944_115564_shared_board[];

long newD_8010197C_11559C_shared_board[] = {
    [ITEM_MUSHROOM] =               0x0013018E,
    [ITEM_SKELETON_KEY] =           0x0013018F,
    [ITEM_POISON_MUSHROOM] =        0x00130190,
    [ITEM_REVERSE_MUSHROOM] =       0x00130191,
    [ITEM_CELLULAR_SHOPPER] =       0x00130192,
    [ITEM_WARP_BLOCK] =             0x00130193,
    [ITEM_PLUNDER_CHEST] =          0x00130194,
    [ITEM_BOWSER_PHONE] =           0x00130195,
    [ITEM_DUELING_GLOVE] =          0x00130196,
    [ITEM_LUCKY_LAMP] =             0x00130197,
    [ITEM_GOLDEN_MUSHROOM] =        0x00130198,
    [ITEM_BOO_BELL] =               0x00130199,
    [ITEM_BOO_REPELLANT] =          0x0013019A,
    [ITEM_BOWSER_SUIT] =            0x0013019B,
    [ITEM_MAGIC_LAMP] =             0x0013019C,
    [ITEM_KOOPA_KARD] =             0x0013019E,
    [ITEM_BARTER_BOX] =             0x0013019F,
    [ITEM_LUCKY_CHARM] =            0x001301A0,
    [ITEM_WACKY_WATCH] =            0x001301A1,
    [ITEM_TOAD_ITEM_BAG] =          0x0013019D,
    [ITEM_BABY_BOWSER_ITEM_BAG] =   0x001301B6,
    //new items start here
    [ITEM_SLUGGISH_SHROOM] =        0x0013026A,
    [ITEM_MAGIKOOPA_WAND] =         0x0013018E //TODO: place holder mushroom icon
};

long newD_801019D0_1155F0_shared_board[] = {
    [ITEM_MUSHROOM] =               0x001301A2,
    [ITEM_SKELETON_KEY] =           0x001301A3,
    [ITEM_POISON_MUSHROOM] =        0x001301A4,
    [ITEM_REVERSE_MUSHROOM] =       0x001301A5,
    [ITEM_CELLULAR_SHOPPER] =       0x001301A6,
    [ITEM_WARP_BLOCK] =             0x001301A7,
    [ITEM_PLUNDER_CHEST] =          0x001301A8,
    [ITEM_BOWSER_PHONE] =           0x001301A9,
    [ITEM_DUELING_GLOVE] =          0x001301AA,
    [ITEM_LUCKY_LAMP] =             0x001301AB,
    [ITEM_GOLDEN_MUSHROOM] =        0x001301AC,
    [ITEM_BOO_BELL] =               0x001301AD,
    [ITEM_BOO_REPELLANT] =          0x001301AE,
    [ITEM_BOWSER_SUIT] =            0x001301AF,
    [ITEM_MAGIC_LAMP] =             0x001301B0,
    [ITEM_KOOPA_KARD] =             0x001301B2,
    [ITEM_BARTER_BOX] =             0x001301B3,
    [ITEM_LUCKY_CHARM] =            0x001301B4,
    [ITEM_WACKY_WATCH] =            0x001301B5,
    [ITEM_TOAD_ITEM_BAG] =          0x001301A2, //toad item bag entry missing
    [ITEM_BABY_BOWSER_ITEM_BAG] =   0x001301A2, //baby bowser item bag entry missing
    //new items start here
    [ITEM_SLUGGISH_SHROOM] =        0x0013026B,
    [ITEM_MAGIKOOPA_WAND] =         0x001301A2 //TODO: place holder mushroom icon
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