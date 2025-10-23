#include "marioparty.h"
#include "process.h"

#define SPACES_MAX 128

typedef u8 Addr[];

extern u8 (*D_801012C4_114EE4_shared_board)[SPACES_MAX];
extern u8 D_80105268_118E88_shared_board[];
extern Gfx D_801013D8_114FF8_shared_board[];
extern Mtx* D_800D1F68_D2B68;
extern Addr D_101358;
extern Addr D_101398;
extern s16 D_800CCF28_CDB28;

u8 D_80105268_118E88_shared_board[SPACE_TYPES_MAX] = {0};

enum RENDER_TYPES {
    RENDER_32x32 = 0,
    RENDER_16x32 = 1,
    RENDER_16x16 = 2
};

enum TURN_STATUS {
    TURN_STATUS_NONE = 0,
    TURN_STATUS_BLUE = 1,
    TURN_STATUS_RED = 2,
    TURN_STATUS_GREEN = 4,
};

extern f32 D_80105290_118EB0_shared_board[];
extern s32 D_801052B0_118ED0_shared_board;
extern u16 D_80105262_118E82_shared_board;
void func_800E989C_FD4BC_shared_board(void*);

//maybe one of these main fs id array is low res texture and other high res?
static s32 newD_801012C8_114EE8_shared_board[SPACE_TYPES_MAX] = {
    0x00000000,
    0x00130215,
    0x00130216,
    0x00000000,
    0x00130219,
    0x0013021F,
    0x00130218,
    0x0013021D,
    0x00000000,
    0x00130217,
    0x00000000,
    0x00000000,
    0x0013021E,
    0x00130222,
    0x0013021B,
    0x0013021A,
    //extra space mainfs IDs here if using the mainfs
    0x0013021A //game guy placeholder
};

//maybe one of these main fs id array is low res texture and other high res?
static s32 newD_80101318_114F38_shared_board[SPACE_TYPES_MAX] = {
    0x00000000, //0
    0x00130248, //1
    0x00130249, //2
    0x00000000, //3
    0x0013024B, //4
    0x0013024C, //5
    0x00130250, //6
    0x0013024D, //7
    0x00000000, //8
    0x0013024F, //9
    0x00000000, //10
    0x00000000, //11
    0x00130251, //12
    0x0013024E, //13
    0x00130252, //14
    0x0013024A, //15
    //extra space mainfs IDs here if using the mainfs
    0x0013024A //game guy placeholder
};

static u8 newD_80101308_114F28_shared_board[] = {
/* 0 - 3 */ RENDER_32x32, RENDER_16x16, RENDER_16x16, RENDER_32x32,
/* 4 - 7 */ RENDER_32x32, RENDER_16x32, RENDER_16x32, RENDER_16x32,
/* 8 - 11 */ RENDER_32x32, RENDER_16x32, RENDER_32x32, RENDER_32x32,
/* 12 - 15 */ RENDER_16x32, RENDER_16x32, RENDER_16x32, RENDER_16x32,
//extras render types starting here
/* 16 */ RENDER_16x32 //render space type 0x10 as 32x32 image 
};

extern s16 D_80105260_118E80_shared_board;
u8* D_80105220_118E40_shared_board[SPACE_TYPES_MAX] = {0};

void newfunc_800EA5A4_FE1C4_shared_board(void) {
    s32 i;

    for (i = 0; i < SPACE_TYPES_MAX; i++) {
        if (D_80105220_118E40_shared_board[i] != 0) {
            DataClose(D_80105220_118E40_shared_board[i]);
        }
        D_80105220_118E40_shared_board[i] = 0;
    }
}

void newfunc_800EA4F0_FE110_shared_board(s16 arg0) {
    s32* var_s2;
    s32 i;

    D_80105260_118E80_shared_board = arg0;
    
    switch (arg0) {
    case 0:
    default:
        var_s2 = newD_801012C8_114EE8_shared_board;
        break;
    case 1:
        var_s2 = newD_80101318_114F38_shared_board;
        break;
    }
    
    for (i = 0; i < SPACE_TYPES_MAX; i++) {
        if (var_s2[i] != 0) {
            D_80105220_118E40_shared_board[i] = DataRead(var_s2[i]);
        } else {
            D_80105220_118E40_shared_board[i] = NULL;
        }
    }
}

void newfunc_800ECDD4_1009F4_shared_board(s32 arg0, s32 spaceType) {
    GW_PLAYER* player;
    s32 turnStatus;

    player = MBGetPlayerStruct(arg0);
    switch (spaceType) {
    case SPACE_BLUE:
        turnStatus = TURN_STATUS_BLUE;
        break;
    case SPACE_RED:
    case SPACE_BOWSER:
        turnStatus = TURN_STATUS_RED;
        break;
    case SPACE_NONE:
    case SPACE_HAPPENING:
    case SPACE_CHANCE_TIME:
    case SPACE_ITEM:
    case SPACE_BANK:
    case SPACE_BATTLE:
    case SPACE_MUSHROOM: //extra case for new space type
        turnStatus = TURN_STATUS_GREEN;
        break;
    default:
        turnStatus = TURN_STATUS_NONE;
        break;
    }

	player->color = turnStatus;
}

void newfunc_800F95FC_10D21C_shared_board(s16 arg0) {
    switch (arg0) {
    case SPACE_STAR:
        if (gCurrentPlayerIndex != 4) {
            HuAudFXPlay(0x123);
            return;
        }
    case SPACE_BLUE:
    case SPACE_RED:
    case SPACE_HAPPENING:
    case SPACE_CHANCE_TIME:
    case SPACE_ITEM:
    case SPACE_BANK:
    case SPACE_BATTLE:
    case SPACE_BOWSER:
    case SPACE_GAME_GUY:
    case SPACE_MUSHROOM:
        HuAudFXPlay(0x101);
        break;
    }
}

void newfunc_800EBDAC_FF9CC_shared_board(void) {
    s32 var_s0;
    s32 i, j;

    if (D_801012C4_114EE4_shared_board != NULL) {
        HuMemMemoryFreeTemp(D_801012C4_114EE4_shared_board);
    }

    D_801012C4_114EE4_shared_board = HuMemMemoryAllocTemp(SPACE_TYPES_MAX * SPACES_MAX);

    for (i = 0; i < SPACE_TYPES_MAX; i++) {
        var_s0 = 0;

        for (j = 0; j < gTotalSpaces; j++) {
            if (MBMasuGet(j)->space_type == i) {
                D_801012C4_114EE4_shared_board[i][var_s0] = j;
                var_s0++;
            }                
        }
        
        D_801012C4_114EE4_shared_board[i][var_s0] = 0xFF;
        D_80105268_118E88_shared_board[i] = var_s0;
    }
}

void newDrawSpaces(Gfx** arg0, Mtx* arg1, s32 arg2) {
    Gfx** gfxPos = arg0;
    Mtx sp10;
    char sp50[4]; //unknown type and size
    Mtx* sp5C;
    u8* sp64;
    u8* sp6C;
    s32 sp74;
    u16 sp7E;
    SpaceData* temp_s0;
    s16 var_v0;
    Mtx* temp_s0_3;
    s32 i, j;
    s32 var_s5;

    sp5C = arg1;
    var_s5 = 0;
    if (!(arg2 & 0xFF) && (D_80105262_118E82_shared_board != 0) && (D_801012C4_114EE4_shared_board != 0)) {
        sp7E = func_8004D6AC_4E2AC(0xC8, 0xC8, 0xC8);
        gSPDisplayList((*gfxPos)++, D_801013D8_114FF8_shared_board);
        func_80012640_13240(0, gfxPos);
        func_800127C4_133C4(0, gfxPos);
        func_800E989C_FD4BC_shared_board(sp50);
        
        if ((D_80105260_118E80_shared_board == 0) || (var_v0 = 8, (D_80105260_118E80_shared_board != 1))) {
            var_v0 = 0x10;
            sp64 = D_101358;
            sp6C = newD_80101308_114F28_shared_board;
            sp74 = 0;
        } else {
            var_v0 = 8;
            sp64 = D_101398;
            sp6C = NULL;
            sp74 = 1;
        }
        //iterate over all space types
        for (i = 0; i < SPACE_TYPES_MAX; i++) {
            if (D_80105220_118E40_shared_board[i] != 0) {
                if (sp74 == 0) {
                    switch (sp6C[i]) {
                    case 0:
                        gDPLoadTextureBlock((*gfxPos)++, D_80105220_118E40_shared_board[i] + 0x10, G_IM_FMT_RGBA, G_IM_SIZ_32b,
                            32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                        break;
                    case 1:
                        // + 0x10 to skip image header data
                        gDPLoadTextureBlock((*gfxPos)++, D_80105220_118E40_shared_board[i] + 0x10, G_IM_FMT_RGBA, G_IM_SIZ_32b,
                            16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                        break;
                    case 2:
                        gDPLoadTextureBlock((*gfxPos)++, D_80105220_118E40_shared_board[i] + 0x10, G_IM_FMT_RGBA, G_IM_SIZ_32b,
                            16, 16, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
                        break;
                    }
                } else {
                    gDPLoadTextureBlock((*gfxPos)++, D_80105220_118E40_shared_board[i] + 0x10, G_IM_FMT_RGBA, G_IM_SIZ_32b,
                            var_v0, var_v0, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
                }
                //read over a space types space array
                for (j = 0; j < gTotalSpaces; j++) {
                    s32 spaceId = D_801012C4_114EE4_shared_board[i][j];
                    if (spaceId == 0xff) {
                        break;
                    }
                    temp_s0 = MBMasuGet(spaceId);
                    func_80089980_8A580(&sp10, &sp5C[1]);
                    func_80017C10_18810(&sp10, temp_s0->coords.x, temp_s0->coords.y, temp_s0->coords.z);
                    if ((i == 0xD) && (var_s5 < D_801052B0_118ED0_shared_board)) {
                        func_800185A4_191A4(&sp10, D_80105290_118EB0_shared_board[var_s5++]);
                    }
                    func_80017CD0_188D0(&sp10, temp_s0->rot.x, 1.0f, temp_s0->rot.z);
                    temp_s0_3 = &D_800D1F68_D2B68[D_800CCF28_CDB28++];
                    func_800898F0_8A4F0(&sp10, temp_s0_3);
                    gSPMatrix((*gfxPos)++, OS_K0_TO_PHYSICAL(temp_s0_3), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                    gSPVertex((*gfxPos)++, sp64, 4, 0);
                    gSP1Quadrangle((*gfxPos)++, 0, 1, 2, 3, 0);
                }
            }            
        }

        func_8004D6E8_4E2E8(sp7E);
    }
}