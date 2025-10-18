#include "marioparty.h"
#include "hmfman.h"

typedef struct DiceInstance {
    char unk_00[0x4C];
    s32 unk_4C;
} DiceInstance; //unk size

typedef struct UnkDice2 {
    s32 unk0;
    s32 unk4;
} UnkDice2;

typedef struct UnkDiceRelatedInner {
    /* 0x00 */ char pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ s8 unk3;
    /* 0x04 */  s8 unk4;
    /* 0x05 */ s8 unk5;
    /* 0x06 */ s8 unk6;
    /* 0x07 */ s8 unk7;
    /* 0x08 */ s8 unk8;
    /* 0x09 */ char unk_09[5];
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk16;                             /* inferred */
    /* 0x16 */ char pad18[0x10];
    /* 0x28 */ s16 unk_28;
    /* 0x2A */ char pad2A[0xA];                     /* maybe part of unk_28[6]? */
    /* 0x34 */ DiceInstance* dice;
    /* 0x38 */ char pad38[0xC];                     /* maybe part of dice[4]? */
} UnkDiceRelatedInner;                              /* size = 0x44 */

typedef struct UnkDiceRelated {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ char unk_02[6];  
    /* 0x08 */ UnkDiceRelatedInner UnkDiceInner;
} UnkDiceRelated;

typedef struct jump_buf
{
    u32* sp;
    void *func;
    u32 regs[21];
} jmp_buf;

extern s32 setjmp(jmp_buf *jump_buf);
extern s32 longjmp(jmp_buf *jump_buf, s32 val);

#define EXEC_PROCESS_DEFAULT 0
#define EXEC_PROCESS_SLEEPING 1
#define EXEC_PROCESS_WATCH 2
#define EXEC_PROCESS_DEAD 3

typedef void (*process_func)();

typedef struct Process {
/* 0x00 */ struct Process *next;
/* 0x04 */ struct Process *youngest_child;
/* 0x08 */ struct Process *oldest_child;
/* 0x0C */ struct Process *relative;
/* 0x10 */ struct Process *parent_oldest_child;
/* 0x14 */ struct Process *new_process;
/* 0x18 */ void *heap;
/* 0x1C */ u16 exec_mode;
/* 0x1E */ u16 stat;
/* 0x20 */ u16 priority;
/* 0x22 */ s16 dtor_idx;
/* 0x24 */ s32 sleep_time;
/* 0x28 */ void *base_sp;
/* 0x2C */ jmp_buf prc_jump;
/* 0x88 */ process_func destructor;
/* 0x8C */ void *user_data;
} Process;

Process* HuPrcCurrentGet();
extern UnkDiceRelated D_800CDBC8_CE7C8[4];
extern s8 D_80105704_119324_shared_board;
void func_800DC128_EFD48_shared_board(s32);
void HuPrcSleep(s32 time);
extern u16 D_800D5558_D6158[4];
extern HmfModel* HmfModelData;
extern s16 D_80100D90_1149B0_shared_board[4][2];
void func_800F2304_105F24_shared_board(s32 playerIndex, s16 arg1, u16 arg2);
extern s16 D_800CDD64_CE964;
extern u8 D_800CC0C0_CCCC0;
void func_8004A650_4B250(s32);                           /* extern */
void func_8004A670_4B270(s32);                           /* extern */
void func_8004A880_4B480(s32);                           /* extern */
void func_8004A918_4B518(s32);                           /* extern */
void func_800DBE6C_EFA8C_shared_board(s32);            /* extern */
void func_800DCBCC_F07EC_shared_board(s32);            /* extern */
void func_800DE9B8_F25D8_shared_board(s32, s32, s32, s32); /* extern */
void func_800EE688_1022A8_shared_board(Object*, f32, f32);     /* extern */
void func_800F2304_105F24_shared_board(s32 playerIndex, s16 arg1, u16 arg2);
void func_800F2388_105FA8_shared_board(s32, s32, s32, s32, s32); /* extern */

extern s8 D_80105704_119324_shared_board;
extern u8 D_8010570E_11932E_shared_board;
extern s16 D_800D037C_D0F7C;
s16 HuAudFXPlay(s16 seId);
void func_800FF900_113520_shared_board(s16, s16);
f32 HuMathCos(f32);
f32 HuMathSin(f32);
void HuSprScaleSet(s16 group, s16 member, f32 x, f32 y);
void HuPrcVSleep(void);
void func_800EC590_1001B0_shared_board(s32, s32);
void ShowPlayerCoinChange(s32 player, s32 coins);
void func_800F5D44_109964_shared_board(s32, s32);
void func_8004ACE0_4B8E0(s32, s16);
s32 func_800DBEC0_EFAE0_shared_board(s32);
void func_800DB884_EF4A4_shared_board(s32);
s32 GWBoardFlagCheck(s32);
void omDelPrcObj(Process*);

typedef struct MagikoopaWandData {
    u8 inflictedBy;
    u8 pad;
    u8 stat;
    u8 playerNo;
} MagikoopaWandData;

MagikoopaWandData inflictData[4] = {-1};


//if board was just loaded and it's turn 1, get this info for later
void magikoopaWandGetPlayerPorts(void) {

}

char testMessage[] = "The effects of a magikoopa wand are active\xC3\xFF";

void newfunc_800DCDD4_F09F4_shared_board(void) {
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 temp_f20_7;
    f32 temp_f20_8;
    f32 temp_f20_9;
    f32 temp_f20_10;
    f32 temp_f22;
    f32 temp_f24;
    s32 temp_s0;
    s32 var_s1;
    s32 var_s5;
    s32 i, j;
    UnkDice2* temp_s3;
    UnkDiceRelatedInner* temp_s4;
    s32 inflictor = -1;
    s32 savedPort = -1;

    var_s1 = 0;
    temp_s3 = HuPrcCurrentGet()->user_data;
    temp_s4 = &D_800CDBC8_CE7C8[temp_s3->unk0].UnkDiceInner;
    var_s5 = 0;

    //check if magikoopa wand is active on current player
    inflictor = magikoopaWandCheck();
    if (inflictor != -1) {
        //is active, show message then assign inflictor to current player
        func_800EC590_1001B0_shared_board(-1, testMessage);

        //backup important data so it can be restored later
        inflictData[GwSystem.current_player_index].inflictedBy = inflictor;
        inflictData[GwSystem.current_player_index].pad = GwPlayer[GwSystem.current_player_index].pad;
        inflictData[GwSystem.current_player_index].stat = GwPlayer[GwSystem.current_player_index].stat;
        inflictData[GwSystem.current_player_index].playerNo = GwSystem.current_player_index;
        
        //copy pad number and cpu flags from inflictor
        GwPlayer[GwSystem.current_player_index].pad = GwPlayer[inflictor].pad;

        if (GwPlayer[inflictor].stat & 1) {
            GwPlayer[GwSystem.current_player_index].stat |= 1;
        } else {
            GwPlayer[GwSystem.current_player_index].stat &= ~1;
        }
        
    }

    while (1) {
        switch (temp_s3->unk4) {
        case 0:
            D_80105704_119324_shared_board = 0;
            func_800DC128_EFD48_shared_board(temp_s3->unk0);
            D_80105704_119324_shared_board = 1;
            temp_s3->unk4++;
            HuPrcSleep(0x14);
            break;
        case 1:
            if (((GwPlayer[temp_s3->unk0].stat & 1) || (D_800D5558_D6158[GwPlayer[temp_s3->unk0].pad] & 0x8000)) && !(HmfModelData[D_800CDBC8_CE7C8[temp_s3->unk0].UnkDiceInner.unk16].unk18 & 4) && (GWBoardFlagCheck(0x11) == 0)) {
                temp_s3->unk4++;
                func_800F2304_105F24_shared_board(temp_s3->unk0, 2, 0);
                func_800EE688_1022A8_shared_board(GwPlayer[temp_s3->unk0].player_obj, 2.0f, -0.3f);
                D_800CDD58_CE958 = 0;
                D_800CDD64_CE964 = 0;
            }
            break;
        case 2:
            if (++var_s1 >= 5) {
                func_800DCBCC_F07EC_shared_board(temp_s3->unk0);
                func_800F2388_105FA8_shared_board(temp_s3->unk0, -1, 0, 0xA, 2);
                temp_s3->unk4++;
            }
            break;
        case 3:
            HuPrcSleep(20);

            //hack for sluggish shroom to work
            if (D_8010570E_11932E_shared_board == 6) {
                D_8010570E_11932E_shared_board = 1;
            }
            if (++var_s5 != D_8010570E_11932E_shared_board) {
                HuPrcSleep(10);
                var_s1 = 0;
                func_800DBE6C_EFA8C_shared_board(temp_s3->unk0);
                {
                    s16* temp0 = &D_80100D90_1149B0_shared_board[var_s5][0];
                    s16* temp1 = &D_80100D90_1149B0_shared_board[var_s5][1];
                    func_800DE9B8_F25D8_shared_board(temp_s3->unk0, temp_s4->unk8, *temp0, *temp1);
                }
                
                temp_s4->unk8++;
                temp_s3->unk4 = 0;
            } else {
                if (D_8010570E_11932E_shared_board != 1) {
                    HuPrcSleep(10);
                    func_800DBE6C_EFA8C_shared_board(temp_s3->unk0);
                    {
                        s16* temp0 = &D_80100D90_1149B0_shared_board[var_s5][0];
                        s16* temp1 = &D_80100D90_1149B0_shared_board[var_s5][1];
                        func_800DE9B8_F25D8_shared_board(temp_s3->unk0, temp_s4->unk8, *temp0, *temp1);
                    }    
                    
                    HuPrcSleep(20);
                    if (D_8010570E_11932E_shared_board == 2) {
                        if (temp_s4->unk5 != temp_s4->unk6) {

                        } else {
                            HuAudFXPlay(0x15D);
                            if (temp_s4->unk5 == 7) {
                                func_800FF900_113520_shared_board(-1, 3);
                            } else {
                                func_800FF900_113520_shared_board(-1, 2);
                            }
                            
                            for (j = 0; j < 0x25; j++) {
                                temp_f22 = (f32) (((j * 4) + j) * 4);
                                temp_f20 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                HuSprScaleSet(temp_s4->unk_0E, 0, temp_f20, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                temp_f20_2 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                HuSprScaleSet(temp_s4->unk_10, 0, temp_f20_2, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                if (temp_s4->unk5 == 0xA) {
                                    temp_f20_3 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                    HuSprScaleSet(temp_s4->unk_0E, 1, temp_f20_3, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                    temp_f20_4 = (HuMathSin(temp_f22) * 0.5f) + 1.0f;
                                    HuSprScaleSet(temp_s4->unk_10, 1, temp_f20_4, (HuMathSin(temp_f22) * 0.5f) + 1.0f);
                                }
                                HuPrcVSleep();                            
                            }

                            if (temp_s4->unk5 == 7) {
                                func_800EC590_1001B0_shared_board(0x16, 0x3A24);
                                ShowPlayerCoinChange(temp_s3->unk0, 20); //triples, 20 coins
                                func_800F5D44_109964_shared_board(temp_s3->unk0, 20);
                            } else {
                                func_800EC590_1001B0_shared_board(0x16, 0x3A26);
                                ShowPlayerCoinChange(temp_s3->unk0, 0xA); //doubles, 10 coins
                                func_800F5D44_109964_shared_board(temp_s3->unk0, 10); 
                            }
                            
                            func_8004ACE0_4B8E0(0x274, temp_s3->unk0);
                            func_800F2304_105F24_shared_board(temp_s3->unk0, 5, 0);
                            HuPrcSleep(30);
                            func_800F2304_105F24_shared_board(temp_s3->unk0, -1, 2);
                        }
                    } else {
                        if (D_8010570E_11932E_shared_board == 3) {
                            if ((temp_s4->unk5 == temp_s4->unk6) && (temp_s4->unk5 == temp_s4->unk7)) {
                                if (temp_s4->unk5 == 7) {
                                    D_800D037C_D0F7C = 0;
                                    HuAudFXPlay(0x15E);
                                    func_8004A670_4B270(0);
                                    func_8004A918_4B518(0x69);
                                    func_8004A880_4B480(0);
                                    func_8004A650_4B250(0xF);
                                    func_800FF900_113520_shared_board(-1, 4);
                                } else {
                                    HuAudFXPlay(0x15D);
                                    func_800FF900_113520_shared_board(-1, 3);
                                }
                                for (i = 0; i < 73; i++, HuPrcVSleep()) {
                                    var_s1 = i;
                                    temp_s0 = (i * 4) + var_s1;
                                    temp_f24 = (f32) (temp_s0 * 4);
                                    temp_f20_5 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                    HuSprScaleSet(temp_s4->unk_0E, 0, temp_f20_5, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                    temp_f20_6 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                    HuSprScaleSet(temp_s4->unk_10, 0, temp_f20_6, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                    temp_f20_7 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                    HuSprScaleSet(temp_s4->unk_12, 0, temp_f20_7, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                    if (temp_s4->unk5 == 0xA) {
                                        temp_f20_8 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                        HuSprScaleSet(temp_s4->unk_0E, 1, temp_f20_8, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                        temp_f20_9 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                        HuSprScaleSet(temp_s4->unk_10, 1, temp_f20_9, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                        temp_f20_10 = (HuMathSin(temp_f24) * 0.5f) + 1.0f;
                                        HuSprScaleSet(temp_s4->unk_12, 1, temp_f20_10, (HuMathSin(temp_s0) * 0.5f) + 1.0f);
                                    }                            
                                }
                                
                                if (temp_s4->unk5 == 7) {
                                    func_800EC590_1001B0_shared_board(0x16, 0x3A25);
                                    ShowPlayerCoinChange(temp_s3->unk0, 0x32);
                                    func_800F5D44_109964_shared_board(temp_s3->unk0, 0x32);
                                    D_800CC0C0_CCCC0 = 1;
                                } else {
                                    func_800EC590_1001B0_shared_board(0x16, 0x3A24);
                                    ShowPlayerCoinChange(temp_s3->unk0, 0x14);
                                    func_800F5D44_109964_shared_board(temp_s3->unk0, 0x14);
                                }
                                func_8004ACE0_4B8E0(0x274, temp_s3->unk0);
                                func_800F2304_105F24_shared_board(temp_s3->unk0, 5, 0);
                                HuPrcSleep(30);
                                if (temp_s4->unk5 == 7) {
                                    D_800D037C_D0F7C = 1;
                                }
                                func_800F2304_105F24_shared_board(temp_s3->unk0, -1, 2);
                            }
                        }
                    }

                    for (var_s1 = 0; var_s1 < 50; HuPrcVSleep(), var_s1 += 2) {
                        func_800DE9B8_F25D8_shared_board(temp_s3->unk0, 0, D_80100D90_1149B0_shared_board[1][0] + var_s1, D_80100D90_1149B0_shared_board[1][1] + (var_s1 / 2));
                        func_800DE9B8_F25D8_shared_board(temp_s3->unk0, 1, D_80100D90_1149B0_shared_board[2][0] - var_s1, D_80100D90_1149B0_shared_board[2][1] + (var_s1 / 2));
                        if (D_8010570E_11932E_shared_board == 3) {
                            func_800DE9B8_F25D8_shared_board(temp_s3->unk0, 2, D_80100D90_1149B0_shared_board[3][0], D_80100D90_1149B0_shared_board[3][1]+ (var_s1 / 2));
                        }
                    }
                    
                    if (D_8010570E_11932E_shared_board == 2) {
                        HuAudFXPlay(0x140);
                    } else if (D_8010570E_11932E_shared_board == 3) {
                        HuAudFXPlay(0x146);
                    }

                    D_8010570E_11932E_shared_board = 1;
                    temp_s4->unk8 = 0;
                    temp_s4->unk5 += temp_s4->unk6 + temp_s4->unk7;
                    temp_s4->unk7 = 0;
                    temp_s4->unk6 = 0;
                    func_800DBEC0_EFAE0_shared_board(temp_s3->unk0);
                    func_800DB884_EF4A4_shared_board(temp_s3->unk0);
                    HuPrcSleep(0x14);
                }
                omDelPrcObj(NULL);
            }
            break;
        }
        HuPrcVSleep();
    }
}
