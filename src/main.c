#include "marioparty.h"

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))

void* DataRead(s32 dirAndFile);
s16 func_80055810_56410(void*);
void DataClose(void* data);
void HuSprKill(s16);

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
    0x001301B6 //baby bowser item bag
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