#include "marioparty.h"
#include "process.h"

extern s16 D_800D4080_D4C80;
s16 RNGPercentChance(s8 arg0);
void func_800500E0_50CE0(s32);                           /* extern */
s16 func_8005E0C0_5ECC0(s16);                       /* extern */
void func_800600C0_60CC0(s16, s32);                      /* extern */
s32 func_80061188_61D88(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u16 arg5);
void func_80061A5C_6265C(s16, s32);                      /* extern */
void func_800DBFBC_EFBDC_shared_board(s8);             /* extern */
s32 func_800DCD9C_F09BC_shared_board(s8);           /* extern */
Process* func_800DD6C4_F12E4_shared_board(s8);      /* extern */
Process* func_800DDDD4_F19F4_shared_board(s8);      /* extern */
void func_800DE414_F2034_shared_board(s8, u8);         /* extern */
Process* func_800DE7E4_F2404_shared_board(s8);      /* extern */
u8 func_800DE84C_F246C_shared_board(void);             /* extern */
void func_800DE858_F2478_shared_board(void);               /* extern */
void func_800DE868_F2488_shared_board(void);               /* extern */
Process* func_800E0A14_F4634_shared_board(void);        /* extern */
Process* func_800E0C3C_F485C_shared_board(void);        /* extern */
Process* func_800E0F84_F4BA4_shared_board(void);        /* extern */
void func_800E3498_F70B8_shared_board(void);               /* extern */
void func_800E34BC_F70DC_shared_board(void);               /* extern */
void func_800E455C_F817C_shared_board(void);               /* extern */
void func_800E4954_F8574_shared_board(void);               /* extern */
Process* func_800E5CE0_F9900_shared_board(s8);      /* extern */
void func_800E648C_FA0AC_shared_board(void);               /* extern */
void func_800E8DD4_FC9F4_shared_board(f32);              /* extern */
Process* func_800E8EDC_FCAFC_shared_board(f32);       /* extern */
void func_800EB97C_FF59C_shared_board(s16);            /* extern */
s32 func_800EBAC8_FF6E8_shared_board(s16, s32);       /* extern */
void func_800EBCBC_FF8DC_shared_board(s16);            /* extern */
s16 func_800EBCC8_FF8E8_shared_board(void);             /* extern */
void func_800EBEC8_FFAE8_shared_board(void);               /* extern */
void func_800ECC28_100848_shared_board(short);           /* extern */
void func_800ECDD4_1009F4_shared_board(s32, u8);         /* extern */
void func_800ED1E4_100E04_shared_board(Vec*, Vec*, Vec*, s32); /* extern */
void func_800ED410_101030_shared_board(s8, s32);         /* extern */
Process* func_800EDB98_1017B8_shared_board(Object*, f32, f32); /* extern */
void func_800EDC58_101878_shared_board(s16, u8);       /* extern */
void func_800EE688_1022A8_shared_board(Object*, f32, f32); /* extern */
void func_800F22C0_105EE0_shared_board(s32);             /* extern */
void func_800F2304_105F24_shared_board(s32, s32, s32);       /* extern */
void func_800F2388_105FA8_shared_board(s32, s32, s32, s32, s32); /* extern */
Process* func_800F292C_10654C_shared_board(void);       /* extern */
Process* func_800F29EC_10660C_shared_board(void);       /* extern */
void func_800F482C_10844C_shared_board(s32);           /* extern */
void func_800F70F8_10AD18_shared_board(void);              /* extern */
void func_800F7108_10AD28_shared_board(void);              /* extern */
void func_800F85C0_10C1E0_shared_board(void);              /* extern */
void func_800F85E4_10C204_shared_board(void);              /* extern */
void func_800F915C_10CD7C_shared_board(s32);             /* extern */
void func_800F92A0_10CEC0_shared_board(void);              /* extern */
s32 func_800F933C_10CF5C_shared_board(void);            /* extern */
void func_800F965C_10D27C_shared_board(u8);            /* extern */
void func_800F96E0_10D300_shared_board(s32, s32);      /* extern */
void func_800FA448_10E068_shared_board(void);              /* extern */
void func_800FA640_10E260_shared_board(GW_PLAYER*, s32); /* extern */
void func_800FA95C_10E57C_shared_board(void);              /* extern */
s32 func_800FAB98_10E7B8_shared_board(GW_PLAYER*, s32); /* extern */
s32 func_800FB624_10F244_shared_board(GW_PLAYER*);  /* extern */
void func_800FC3D0_10FFF0_shared_board(void);              /* extern */
void func_800FC4E0_110100_shared_board(void);              /* extern */
void func_800FC7C8_1103E8_shared_board(void);              /* extern */
void func_800FF794_1133B4_shared_board(s32, s32, s32, s32);    /* extern */
void func_800FF840_113460_shared_board(s32);             /* extern */
void func_8005A6B0_5B2B0(void);
s16 func_8005A968_5B568(s16, s16, s16, s16, s32, s16);
void func_8005B43C_5C03C(s16, s32, s32, s32);
void func_8005B6BC_5C2BC(s16 win_id, u32 arg1, s8 arg2);
void func_8005BDFC_5C9FC(s16, s32);
void func_8005BE30_5CA30(s16, s32);
void func_8005BEE0_5CAE0(s16, s32);
void func_8005C02C_5CC2C(s16, s32);
void func_8005C060_5CC60(s16, s32, s32, s32, s32);
void func_8005D294_5DE94(s16);
void func_8005E1A8_5EDA8(s16, s16);
void func_8005F364_5FF64(s16);
void func_8005F524_60124(void);
void func_8005FBF8_607F8(s16, s32, s32, s32);
void func_8005FE90_60A90(s16);
void func_8005FFA8_60BA8(s16);
void func_8006022C_60E2C(u32 mesg, s32);
void func_80060394_60F94(s32, s16*, s32);
void func_80061388_61F88(s16);
void _SetFlag(s32 flag);
extern s32 D_800A12CC;
extern f32 D_800C9938_CA538;
extern s16 D_800CC4A0_CD0A0;
extern s16 D_800D2130;
extern s32 D_800D41C0_D4DC0;
extern u8 D_80101C00_115820_shared_board[4];
extern u8 D_80101C04_115824_shared_board[4];
extern u16 D_80101C08_115828_shared_board[4][2];
extern u16 D_80101C24_115844_shared_board[];
extern u16 D_80101C2C_11584C_shared_board[4][8];
extern u8 D_80101E70_115A90_shared_board[4][2];
extern s32 D_80105660_119280_shared_board;
extern s16 D_800CDD64_CE964;
extern void* D_800D2140_D2D40[];
extern s16 D_800D6A44_D7644;
extern s16 D_800D1FEC_D2BEC;
extern s16 D_800D1708_D2308;
extern s16 D_800D1F7A_D2B7A;

extern u16 D_80101D2C_11594C_shared_board[2][4][3];
extern s32 D_80101C4C_11586C_shared_board[][8];

extern u16 D_80101C8C_1158AC_shared_board[][5][8];
extern s32 D_800D1240_D1E40;
extern s32 D_8010197C_11559C_shared_board[];

void GWBoardFlagSet(s32 flag);
s32 GWBoardFlagCheck(s32);
void func_8005035C_50F5C(s32);
void func_800F4798_1083B8_shared_board(u32, s32);
void func_800FC594_1101B4_shared_board(void);
extern s32 D_800A12D4;
s16 MBMasuLinkMasuIdGet(u16 arg0, u16 arg1);
SpaceData* GetSpaceData(s16 arg0);
void WipeInit(void);
void WipeCreateIn(s32, s32);
s32 WipeCreateOut(s32, s32);
s32 WipeStatGet(void);
void func_800F88D0_10C4F0_shared_board(void);
void func_800ECC0C_10082C_shared_board(Vec*);
void func_800ED128_100D48_shared_board(Vec*, Vec*, Vec*, s32);
void func_8001FDE8_209E8(s16);
void func_800FF900_113520_shared_board(s16, s16);
void func_800FC8A4_1104C4_shared_board(void);
s32 func_800F9A68_10D688_shared_board(s32 arg0);
void func_8004ACE0_4B8E0(s32, s16);
void func_8001C92C_1D52C(s16, f32);
void func_800F95FC_10D21C_shared_board(s16 arg0);
void func_800DB884_EF4A4_shared_board(s32);
s32 func_800FA818_10E438_shared_board(s32 arg0);
void ShowPlayerCoinChange(s32 player, s32 coins);
void func_800F5D44_109964_shared_board(s32, s32);
Process* omAddPrcObj(process_func func, u16 priority, s32 stackSize, s32 extDataSize);
s16 GetCurrentPlayerIndex(void);
void func_800EC414_100034_shared_board(s32);
s32 func_800EEF80_102BA0_shared_board(f32);
s32 func_800F2198_105DB8_shared_board(s16);
s32 BoardPlayerRankCalc(s32 player);
void ShowMessage(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_800EC6C8_1002E8_shared_board(void);
void func_800EC6EC_10030C_shared_board(void);
s16 HuSprGrpCreate(u16 arg0, u16 arg1);
s16 func_80055810_56410(void*);
void func_80055024_55C24(s16 group, s16 member, s16 arg2, s32 arg3);
void HuSprPriSet(s16 group, s16 member, u16 prio);
void func_800550F4_55CF4(s16, s16, s32);
void HuSprAttrSet(s16 group, s16 member, s32 attr);
void func_80054904_55504(s16 group, s16 member, s16 arg2, s16 arg3);
void func_80055458_56058(s16, s16, u16);
s16 HuAudFXPlay(s16 seId);
void HuSprGrpKill(s16);
void HuSprKill(s16);
s32 PlayerHasEmptyItemSlot(s32 arg0);
Object* MBModelCreate(u8, s32);
void func_800D9714_ED334_shared_board(Object*);
void HuVecCopy3F(Vec * out, Vec * a);
void func_800EC590_1001B0_shared_board(s32, s32);
void omDelPrcObj(Process*);
void func_800D9B54_ED774_shared_board(Object*);
void func_800D9CE8_ED908_shared_board(Object*, s16, u16);
void GWBoardFlagClear(s32 flag);

typedef struct UnkOvl81 {
           void* unk0;
           void* unk4;
           void* unk8;
           char unk_0C[0x14];
           s16 unk_20;
           char unk_22[2];
} UnkOvl81;
typedef struct UnkOvl81_1 {
    s32 unk_00;
    char unk_04[0xC];
} UnkOvl81_1;

extern UnkOvl81 D_800D1360_D1F60;
extern s16 D_800D1380_D1F80_shared_board;
extern s32 D_80101B6C_11578C_shared_board;
extern s16 D_800D037C_D0F7C;
extern s16 D_80105664_119284_shared_board;
extern s16 D_80105666_119286_shared_board;

extern s16 gCoinBlockSpaceIndex;
extern s16 gStarBlockSpaceIndex;
extern s16 gItemBlockSpaceIndex;

extern s16 gPrevItemBlockSpaceIndexes[10];
extern s16 gPrevCoinBlockSpaceIndexes[10];
extern s16 gPrevStarBlockSpaceIndexes[10];

void newfunc_800FCA7C_11069C_shared_board(void) {
    Process* temp_s6;
    s32 var_s1;
    s16 temp_v0_2;
    s32 temp_v0_3;
    GW_PLAYER* temp_v0_4;
    s16 var_s5; //
    SpaceData* var_s3;
    Vec sp20;
    Process* temp_s1;
    SpaceData* temp_s3_2;
    u8 temp_v1_2;
    u8 temp_v1_3;
    s16 temp_v0_7;
    s32 temp_v0_8;
    Process* temp_s1_2;
    s32 temp_v0_9;
    s32 temp_v0_10;
    s32 temp_v0_13;
    s32 temp_v0_14;
    s32 temp_v0_16;
    s32 var_v1;
    s32 var_s0;
    s16 temp_v0_18;
    GW_PLAYER* temp_s0_2;
    s32 temp_v0_20;
    s32 temp_s2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_a0;
    s32 temp_s2_2;
    void* temp_v0_21;
    s32 temp_s3_3;
    Object* temp_v0_22;
    Process* temp_s1_5;
    s32 temp_a0_4;
    s32 var_v1_3;
    s32 temp_v1_8;
    s32 temp_a0_3;
    s32 var_s1_12;
    s32 var_s0_2;
    GW_SYSTEM* system = &GwSystem;
    s16 sp30[2];
    s16 sp38[2];
    s16 sp40[2];
    char sp48[16]; //unknown buffer size
    s32 flag;
    s32 state;
    s32 eight;

    temp_s6 = HuPrcCurrentGet();
    
    while (1) {  // Main game loop
        if (D_800D1240_D1E40 < 2U && system->current_player_index == 0) {
            // Initialize all player colors
            for (var_s1 = 0; var_s1 < 4; var_s1++) {
                MBGetPlayerStruct(var_s1)->color = 0;
                func_800F70F8_10AD18_shared_board();
            }
            
            // Check if we're in the last 5 turns
            if (system->total_turns >= 0) {
                short temp_v0 = (system->total_turns - system->current_turn) + 1;
                if (temp_v0 < 6) {
                    if (temp_v0 > 0) {
                        GWBoardFlagSet(2);  // Last 5 turns flag
                    }
                }
            }

            if (!GWBoardFlagCheck(1) && system->current_turn >= 2) {
                switch (system->save_mode) {
                    case 1:
                        system->save_mode = 2;
                    case 0:
                        _SetFlag(0);
                        GWBoardFlagSet(0);
                        
                        func_80060394_60F94(1, sp30, 0x5900);
                        temp_v0_2 = func_8005A968_5B568(0, 0, sp30[0], sp30[1], 0, 2);
                        func_8005BEE0_5CAE0(temp_v0_2, 0);
                        func_8005B43C_5C03C(temp_v0_2, 0x5900, -1, -1);
                        func_8005BDFC_5C9FC(temp_v0_2, 0);
                        
                        while (func_8005E0C0_5ECC0(temp_v0_2) != 0) {
                            HuPrcVSleep();
                        }
                        
                        if (system->playMode & 4) {
                            _SetFlag(0x18);
                            _SetFlag(0x28);
                            func_8005035C_50F5C(1);
                        } else {
                            _SetFlag(0x16);
                            func_800500E0_50CE0(1);
                        }
                        
                        func_8005F364_5FF64(temp_v0_2);
                        func_80060394_60F94(1, sp30, 0x5901);
                        temp_v0_3 = func_8005A968_5B568(0, 0, sp30[0], sp30[1], 0, 2);
                        func_8005BEE0_5CAE0(temp_v0_3, 0);
                        func_8005B43C_5C03C(temp_v0_3, 0x5901, -1, -1);
                        func_8005BDFC_5C9FC(temp_v0_3, 0);
                        HuPrcSleep(0xF);
                        func_8005F364_5FF64(temp_v0_3);
                        break;
                }
            }
            
            GWBoardFlagClear(1);
            D_800A12D4 = 0;
            D_80105660_119280_shared_board = func_800EBAC8_FF6E8_shared_board(-2, 7);
        }
        

        D_800A12D4 = 1;
        
        var_s1 = 0;
        eight = 8; //definitely a hack
        for (; var_s1 < 4; var_s1++) {
            func_800F4798_1083B8_shared_board(var_s1, MBGetPlayerStruct(var_s1)->color);
            func_800F96E0_10D300_shared_board(var_s1, 1);
            
            state = D_800D1240_D1E40;
    
            if (state == eight) {
                // skip
            } else if (state < 8) {
                flag = 1;
                GwSystem.cur_player_used_item &= ~flag;
            } else if (state >= 0x10) {
                flag = 1;
                GwSystem.cur_player_used_item &= ~flag;
            } else if (state < 0xA) {
                flag = 1;
                GwSystem.cur_player_used_item &= ~flag;
            }
        }
        
        func_800FC594_1101B4_shared_board();
        temp_v0_4 = MBGetPlayerStruct(system->current_player_index);
        var_s5 = MBMasuLinkMasuIdGet(temp_v0_4->clink, temp_v0_4->cidx);
        var_s3 = GetSpaceData(var_s5);
        func_800EBCBC_FF8DC_shared_board(var_s5);

        state = D_800D1240_D1E40;

        if (state < 2U) {
            goto temp;
        }
        
        switch (state) {
            case 8:
            case 9:
            case 0xC:
                func_800FA640_10E260_shared_board(temp_v0_4, 1);
                break;
        
            case 0x12:
                var_s1 = 0;
                for (; var_s1 < 4; var_s1++) {
                    if (GwPlayer[var_s1].bonusCoin != 3)
                        break;
                }
                if (var_s1 >= 4) {
                    func_800FA640_10E260_shared_board(temp_v0_4, 1);
                }
                break;
        
            default:
                break;
        }
        
        while (WipeStatGet() != 0) {
            HuPrcVSleep();
        }
        
        D_800D037C_D0F7C = 1;
        
        switch (D_800D1240_D1E40) {
        case 12:
            func_800FA448_10E068_shared_board();
            func_800F88D0_10C4F0_shared_board();
            goto label654;

        case 13:  // Bank space
            func_800FC4E0_110100_shared_board();
            
                
        case 15:  // Some event
            func_800F88D0_10C4F0_shared_board();
            goto label654;
        case 14:
            func_800E3498_F70B8_shared_board();
            func_800E34BC_F70DC_shared_board();
            func_800F88D0_10C4F0_shared_board();
            goto label654;
            
        case 11:
            D_800D1240_D1E40 = 0xA;
            func_800E4954_F8574_shared_board();
            func_800ECC0C_10082C_shared_board(&sp20);
            func_800ED128_100D48_shared_board(&temp_v0_4->player_obj->unk18, &sp20, 
                                              &temp_v0_4->player_obj->unk18, 8);
            HuPrcSleep(8);
            goto label654;
        // case 18:
            temp:
            func_800EBAC8_FF6E8_shared_board(-4, 7);
            // Hide all player models
            func_8001FDE8_209E8(MBGetPlayerStruct(0)->player_obj->omObj1->model[0]);
            func_8001FDE8_209E8(MBGetPlayerStruct(1)->player_obj->omObj1->model[0]);
            func_8001FDE8_209E8(MBGetPlayerStruct(2)->player_obj->omObj1->model[0]);
            func_8001FDE8_209E8(MBGetPlayerStruct(3)->player_obj->omObj1->model[0]);
            
            func_800F2304_105F24_shared_board(-1, -1, 2);
            func_800F915C_10CD7C_shared_board(1);
            
            if (system->current_player_index == 4) {
                func_800E648C_FA0AC_shared_board();
            }
            
            // Camera setup
            if (D_800A12CC == 0) {
                D_800C9938_CA538 = 1.0f;
                func_800E8DD4_FC9F4_shared_board(1.0f);
                HuPrcChildLink(temp_s6, func_800F29EC_10660C_shared_board());
            } else if (system->current_player_index == 4 || system->current_player_index == 0) {
                D_800C9938_CA538 = 1.0f;
                func_800E8DD4_FC9F4_shared_board(1.0f);
                HuPrcChildLink(temp_s6, func_800F29EC_10660C_shared_board());
            } else {
                D_800C9938_CA538 = 1.0f;
                HuPrcChildLink(temp_s6, func_800E8EDC_FCAFC_shared_board(1.0f));
            }
            
            HuPrcChildWait();
        default:
            HuPrcSleep(4);
            func_800FF900_113520_shared_board(-1, 3);
            HuPrcChildLink(temp_s6, func_800E5CE0_F9900_shared_board(system->current_player_index));
            HuPrcChildWait();
            func_800EBAC8_FF6E8_shared_board(-5, 7);
            goto label654;
        case 6:
        case 16:
            HuPrcSleep(0x1E);
            goto label2444;

        case 9:
            func_800FA448_10E068_shared_board();
            goto label2444;

        case 10:
            label654:
            func_800FC7C8_1103E8_shared_board();
            D_800C9938_CA538 = 1.3f;
            HuPrcChildLink(temp_s6, func_800E8EDC_FCAFC_shared_board(1.3f));
            temp_s1 = func_800DD6C4_F12E4_shared_board(system->current_player_index);
            HuPrcChildWait();
            HuPrcSleep(1);
            
            if (system->current_player_index != 4) {
                D_800CDD58_CE958 = 1;
                D_800D037C_D0F7C = 1;
                D_800CDD64_CE964 = 1;
                D_800CC4A0_CD0A0 = 1;
            }
        
            HuPrcChildLink(temp_s6, temp_s1);
            HuPrcChildWait();
            func_800FC8A4_1104C4_shared_board();
            
            D_800CDD58_CE958 = 0;
            D_800CDD64_CE964 = 0;
            D_800D41C0_D4DC0 = func_800DCD9C_F09BC_shared_board(system->current_player_index);
            
            if (D_80105660_119280_shared_board == 0 && (temp_v0_4->rev & 0x80)) {
                temp_v0_4->nlink = temp_v0_4->blink;
                temp_v0_4->nidx = temp_v0_4->bidx;
                temp_v0_4->rev ^= 1;
            }
        
            var_s5 = func_800EBCC8_FF8E8_shared_board();
            D_80105660_119280_shared_board = func_800EBAC8_FF6E8_shared_board(var_s5, 9);
            func_800F2304_105F24_shared_board(-1, 0, 2);
        
            while (D_800D41C0_D4DC0 != 0) {
                short temp_s3;
                short temp_s0;
                func_800EBAC8_FF6E8_shared_board(var_s5, 8);
                
                // Save current position
                temp_s3 = temp_v0_4->clink;
                temp_s0 = temp_v0_4->cidx;
                
                // Update to next position
                temp_v0_4->clink = temp_v0_4->nlink;
                temp_v0_4->cidx = temp_v0_4->nidx;
                
                // Update walk speed animations
                for (var_s1 = 0; var_s1 < 4; var_s1++) {
                    func_800F96E0_10D300_shared_board(var_s1, (system->walk_speed * 5) + 5);
                }
                
                // Restore position temporarily
                temp_v0_4->clink = temp_s3;
                temp_v0_4->cidx = temp_s0;
                
                // Check if next space requires jumping
                temp_s3_2 = GetSpaceData(MBMasuLinkMasuIdGet(temp_v0_4->nlink, temp_v0_4->nidx));
                
                if ((temp_s3_2->unk_02 & 0x8000) || func_800F9A68_10D688_shared_board(system->current_player_index)) {
                    // Jump animation
                    func_8004ACE0_4B8E0(0x3A, system->current_player_index);
                    func_800F2304_105F24_shared_board(-1, 2, 0);
                    
                    switch (system->walk_speed) {
                    case 0:
                        temp_v0_4->player_obj->unk30.y = 8.0f;
                        temp_v0_4->player_obj->unk30.z = -2.0f;
                        func_800ED410_101030_shared_board(system->current_player_index, 7);
                        break;
                    case 1:
                        temp_v0_4->player_obj->unk30.y = 4.0f;
                        temp_v0_4->player_obj->unk30.z = -0.5f;
                        func_800ED410_101030_shared_board(system->current_player_index, 0xF);
                        break;
                    case 2:
                        temp_v0_4->player_obj->unk30.y = 2.0f;
                        temp_v0_4->player_obj->unk30.z = -0.125f;
                        func_800ED410_101030_shared_board(system->current_player_index, 0x1E);
                        break;
                    }
                } else {
                    // Normal walk animation
                    if (temp_v0_4->player_obj->unk46 != 0) {
                        func_800F2304_105F24_shared_board(-1, 0, 2);
                    }
                    
                    switch (system->walk_speed) {
                    case 0:
                        func_8001C92C_1D52C(temp_v0_4->player_obj->omObj1->model[0], 2.0f);
                        func_800ED410_101030_shared_board(system->current_player_index, 5);
                        break;
                    case 1:
                        func_8001C92C_1D52C(temp_v0_4->player_obj->omObj1->model[0], 1.0f);
                        func_800ED410_101030_shared_board(system->current_player_index, 0xA);
                        break;
                    case 2:
                        func_8001C92C_1D52C(temp_v0_4->player_obj->omObj1->model[0], 0.75f);
                        func_800ED410_101030_shared_board(system->current_player_index, 0xF);
                        break;
                    }
                    func_8001C92C_1D52C(temp_v0_4->player_obj->omObj1->model[0], 1.0f);
                }
                
                // Update position
                temp_v0_4->blink = temp_v0_4->clink;
                temp_v0_4->bidx = temp_v0_4->cidx;
                temp_v0_4->clink = temp_v0_4->nlink;
                temp_v0_4->cidx = temp_v0_4->nidx;
                
                // Calculate next index based on direction
                if (temp_v0_4->rev & 1) {
                    temp_v0_4->nidx = temp_v0_4->nidx - 1;
                } else {
                    temp_v0_4->nidx = temp_v0_4->nidx + 1;
                }
                
                var_s5 = MBMasuLinkMasuIdGet(temp_v0_4->clink, temp_v0_4->cidx);
                temp_s3_2 = GetSpaceData(var_s5);
                func_800EBCBC_FF8DC_shared_board(var_s5);
                
                // Handle passing over certain space types
                switch (temp_s3_2->space_type) {
                case SPACE_BLUE:   // Blue space
                case SPACE_RED:   // Red space
                case SPACE_HAPPENING:   // Happening space
                case SPACE_CHANCE_TIME:   // Event space
                case SPACE_ITEM:   // Item space
                case SPACE_BANK:   // Bank space
                case SPACE_BATTLE:   // Battle space
                case SPACE_BOWSER:  // Bowser space
                case SPACE_GAME_GUY:  // Game guy space
                case SPACE_MUSHROOM:
                    func_800DBFBC_EFBDC_shared_board(system->current_player_index);
                    D_800D41C0_D4DC0--;
                    func_800EB97C_FF59C_shared_board(var_s5);
                    break;
                }
                
                // Play appropriate sound effect
                if (D_800D41C0_D4DC0 != 0) {
                    func_800F95FC_10D21C_shared_board(temp_s3_2->space_type);
                } else {
                    func_800F965C_10D27C_shared_board(temp_s3_2->space_type);
                }
                
                func_800E455C_F817C_shared_board();
                D_80105660_119280_shared_board = func_800EBAC8_FF6E8_shared_board(var_s5, 1);
                
                if (D_80105664_119284_shared_board < 0) {
                    continue;
                }
                
                D_800D1240_D1E40 = 2;
                HuPrcSleep(-1);  // Suspend until resumed
        case 2:
                if (D_80105660_119280_shared_board & 1) {
                    var_s5 = func_800EBCC8_FF8E8_shared_board();
                    D_80105660_119280_shared_board = func_800EBAC8_FF6E8_shared_board(var_s5, 2);
                    if (D_80105664_119284_shared_board >= 0) {
                        D_800D1240_D1E40 = 3;
                        HuPrcSleep(-1);
                        
                    }
                }
            /* fallthrough */
        case 3:
                if (D_80105660_119280_shared_board & 2) {
                    D_800D41C0_D4DC0 = 0;
                    continue;
                }
                func_800DB884_EF4A4_shared_board(system->current_player_index);
                HuPrcSleep(0xA);
            }
            
            if (system->current_board_index == 3) {
                GwSystem.boardData.halfWordBytes[4] = 0;
            }
            
            // Handle reverse direction cleanup
            if (temp_v0_4->rev & 0x80) {
                if (temp_v0_4->rev & 1) {
                    // Swap blink/nlink and bidx/nidx
                    temp_v1_2 = temp_v0_4->blink;
                    temp_v0_4->blink = temp_v0_4->nlink;
                    temp_v0_4->nlink = temp_v1_2;
                    
                    temp_v1_3 = temp_v0_4->bidx;
                    temp_v0_4->bidx = temp_v0_4->nidx;
                    temp_v0_4->nidx = temp_v1_3;
                }
                temp_v0_4->rev &= 0x7E;
            }
            
            func_800F2304_105F24_shared_board(-1, -1, 2);
            temp_v0_7 = MBMasuLinkMasuIdGet(temp_v0_4->clink, temp_v0_4->cidx);
            temp_v0_8 = GetSpaceData(temp_v0_7)->space_type;
            
            // Update prize statistics
            switch (temp_v0_8) {
            case SPACE_HAPPENING:
                func_800FF900_113520_shared_board(-1, 3);
                temp_v0_4->stats.prize.hatenaPrize++;
                break;
            case SPACE_RED:
                func_800FF900_113520_shared_board(-1, 1);
                temp_v0_4->stats.prize.redPrize++;
                break;
            case SPACE_BLUE:
                temp_v0_4->stats.prize.bluePrize++;
                break;
            case SPACE_CHANCE_TIME:
                func_800FF900_113520_shared_board(-1, 4);
                temp_v0_4->stats.prize.eventPrize++;
                break;
            case SPACE_GAME_GUY:
                func_800FF900_113520_shared_board(-1, 4);
                temp_v0_4->stats.prize.gamblePrize++;
                break;
            case SPACE_BOWSER:
                func_800FF900_113520_shared_board(-1, 2);
                temp_v0_4->stats.prize.kupaPrize++;
                break;
            case SPACE_BATTLE:
                func_800FF900_113520_shared_board(0, 2);
                func_800FF900_113520_shared_board(1, 2);
                func_800FF900_113520_shared_board(2, 2);
                func_800FF900_113520_shared_board(3, 2);
                temp_v0_4->stats.prize.battlePrize++;
                break;
            case SPACE_ITEM:
                func_800FF900_113520_shared_board(-1, 2);
                temp_v0_4->stats.prize.itemPrize++;
                break;
            case SPACE_BANK:
                func_800FF900_113520_shared_board(-1, 3);
                temp_v0_4->stats.prize.bankPrize++;
                break;
            }
            
            D_800D1240_D1E40 = 4;
            D_80105660_119280_shared_board = func_800EBAC8_FF6E8_shared_board(temp_v0_7, 3);
            
            if (D_80105664_119284_shared_board < 0) {
                goto labelE5C;
            }
            HuPrcSleep(-1);

        case 4:
            if (D_80105660_119280_shared_board & 1) {
                D_80105660_119280_shared_board = func_800EBAC8_FF6E8_shared_board(func_800EBCC8_FF8E8_shared_board(), 4);
                
                if (D_80105664_119284_shared_board >= 0) {
                    D_800D1240_D1E40 = 5;
                    HuPrcSleep(-1);
                }
            }
                
        case 5:
            HuPrcSleep(0x1E);
            labelE5C:
            
            // Return player to space position
            func_800ECC0C_10082C_shared_board(&sp20);
            func_800ED1E4_100E04_shared_board(&temp_v0_4->player_obj->unk18, &sp20, 
                                              &temp_v0_4->player_obj->unk18, 8);
            
            var_s5 = MBMasuLinkMasuIdGet(temp_v0_4->clink, temp_v0_4->cidx);
            var_s3 = GetSpaceData(var_s5);
            
            // STAR BLOCK HANDLING
            if (gStarBlockSpaceIndex == var_s5 ||D_800D4080_D4C80 != 0) {
                func_800FF900_113520_shared_board(-1, 5);
                HuPrcChildLink(temp_s6, func_800E8EDC_FCAFC_shared_board(1.6f));
                temp_s1_2 = func_800DDDD4_F19F4_shared_board(system->current_player_index);
                func_800DE858_F2478_shared_board();
                
                // Display message window
                func_80060394_60F94(1, sp30, 0x3F00);
                temp_v0_9 = func_80061188_61D88(-1, 0xA0 - (sp30[0] / 2), 0x96, sp30[0], sp30[1], 0);
                func_8005B43C_5C03C(temp_v0_9, 0x3F00, -1, -1);
                func_80061388_61F88(temp_v0_9);
                func_800600C0_60CC0(temp_v0_9, 1);
                HuPrcChildWait();
                
                func_800600C0_60CC0(temp_v0_9, 0);
                func_800EDC58_101878_shared_board(temp_v0_9, temp_v0_4->turn);
                func_80061A5C_6265C(temp_v0_9, 0);
                func_8005F364_5FF64(temp_v0_9);
                func_800DE868_F2488_shared_board();
                
                // Wait for player input
                while (!(func_800DE84C_F246C_shared_board())) {
                    HuPrcVSleep();
                }
                
                // Display follow-up message
                func_80060394_60F94(1, sp30, 0x3F01);
                temp_v0_10 = func_80061188_61D88(-1, 0xA0 - (sp30[0] / 2), 0x96, sp30[0], sp30[1], 0);
                func_8005B43C_5C03C(temp_v0_10, 0x3F01, -1, -1);
                func_80061388_61F88(temp_v0_10);
                func_800EDC58_101878_shared_board(temp_v0_10, temp_v0_4->turn);
                func_80061A5C_6265C(temp_v0_10, 0);
                func_8005F364_5FF64(temp_v0_10);
                func_800DE868_F2488_shared_board();
                
                HuPrcChildLink(temp_s6, temp_s1_2);
                HuPrcChildWait();
                HuPrcChildLink(temp_s6, func_800E8EDC_FCAFC_shared_board(1.3f));
                HuPrcChildWait();
                HuPrcSleep(1);
                
                // Update star block history
                gPrevStarBlockSpaceIndexes[D_800D6A44_D7644++] = gStarBlockSpaceIndex;
                D_800D6A44_D7644 = D_800D6A44_D7644 % 10;
                gStarBlockSpaceIndex = -1;
                func_800FC594_1101B4_shared_board();
            }
            
            // COIN BLOCK HANDLING (similar structure to star block)
            if (gCoinBlockSpaceIndex == var_s5 || D_800D2130 != 0) {
                func_800FF900_113520_shared_board(-1, 5);
                HuPrcChildLink(temp_s6, func_800E8EDC_FCAFC_shared_board(1.6f));
                temp_s1_2 = func_800DE7E4_F2404_shared_board(system->current_player_index);
                func_800DE858_F2478_shared_board();
                func_80060394_60F94(1, sp38, 0x3F00);
                temp_v0_13 = func_80061188_61D88(-1, 0xA0 - (sp38[0] / 2), 0x96, sp38[0], sp38[1], 0);
                func_8005B43C_5C03C(temp_v0_13, 0x3F00, -1, -1);
                func_80061388_61F88(temp_v0_13);
                func_800600C0_60CC0(temp_v0_13, 1);
                HuPrcChildWait();
                func_800600C0_60CC0(temp_v0_13, 0);
                func_800EDC58_101878_shared_board(temp_v0_13, temp_v0_4->turn);
                func_80061A5C_6265C(temp_v0_13, 0);
                func_8005F364_5FF64(temp_v0_13);
                func_800DE868_F2488_shared_board();
                while (!func_800DE84C_F246C_shared_board()) {
                    HuPrcVSleep();
                }
                HuPrcChildLink(temp_s6, temp_s1_2);
                HuPrcChildWait();
                func_80060394_60F94(1, sp38, 0x3F02);
                temp_v0_13 = func_80061188_61D88(-1, 0xA0 - (sp38[0] / 2), 0x96, sp38[0], sp38[1], 0);
                func_8005B43C_5C03C(temp_v0_13, 0x3F02, -1, -1);
                func_80061388_61F88(temp_v0_13);
                func_800EDC58_101878_shared_board(temp_v0_13, temp_v0_4->turn);
                func_80061A5C_6265C(temp_v0_13, 0);
                func_8005F364_5FF64(temp_v0_13);
                HuPrcChildLink(temp_s6, func_800E8EDC_FCAFC_shared_board(1.3f));
                HuPrcChildWait();
                HuPrcSleep(1);
                gPrevCoinBlockSpaceIndexes[D_800D1FEC_D2BEC++] = gCoinBlockSpaceIndex;
                D_800D1FEC_D2BEC = D_800D1FEC_D2BEC % 10;
                gCoinBlockSpaceIndex = -1;
                func_800FC594_1101B4_shared_board();
            }
    
            // ITEM BLOCK HANDLING
            if (gItemBlockSpaceIndex == var_s5 || D_800D1708_D2308 != 0) {
                short var_s1;
                short temp_v1_6;
                func_800FF900_113520_shared_board(-1, 5);
                
                // Random item selection with weighted probabilities
                do {
                    var_s1 = 0;
                    temp_v1_6 = func_800EEF80_102BA0_shared_board(100.0f) + 1;
                    
                    while (1) {
                        if (temp_v1_6 <= D_80101E70_115A90_shared_board[var_s1][1]) break;
                        var_s1++;
                    }
                    
                    // Reroll if Boo item and special flag is set
                } while (GwSystem.unk_52 != 0 && D_80101E70_115A90_shared_board[var_s1][0] == 0x12);
                
                HuPrcChildLink(temp_s6, func_800E8EDC_FCAFC_shared_board(1.6f));
                func_800DE414_F2034_shared_board(system->current_player_index, 
                                                D_80101E70_115A90_shared_board[var_s1][0]);
                func_800DE858_F2478_shared_board();
                
                // Display item message window
                func_80060394_60F94(1, sp40, 0x3F00);
                temp_v0_13 = func_80061188_61D88(-1, 0xA0 - (sp40[0] / 2), 0x96, sp40[0], sp40[1], 0);
                func_8005B43C_5C03C(temp_v0_13, 0x3F00, -1, -1);
                func_80061388_61F88(temp_v0_13);
                func_800600C0_60CC0(temp_v0_13, 1);
                HuPrcChildWait();
                
                func_800600C0_60CC0(temp_v0_13, 0);
                func_800EDC58_101878_shared_board(temp_v0_13, temp_v0_4->turn);
                func_80061A5C_6265C(temp_v0_13, 0);
                func_8005F364_5FF64(temp_v0_13);
                func_800DE868_F2488_shared_board();
                
                // Wait for input
                while (!(func_800DE84C_F246C_shared_board() & 0xFF)) {
                    HuPrcVSleep();
                }
                
                func_800DE868_F2488_shared_board();
                func_8006022C_60E2C(var_s1 + 0x3F04, 0);
                
                // Display item received message
                func_80060394_60F94(1, sp40, 0x3F03);
                temp_v0_14 = func_80061188_61D88(-1, 0xA0 - (sp40[0] / 2), 0x96, sp40[0], sp40[1], 0);
                func_8005B6BC_5C2BC(temp_v0_14, var_s1 + 0x3F04, 0);
                func_8005B43C_5C03C(temp_v0_14, 0x3F03, -1, -1);
                func_80061388_61F88(temp_v0_14);
                func_800EDC58_101878_shared_board(temp_v0_14, temp_v0_4->turn);
                func_80061A5C_6265C(temp_v0_14, 0);
                func_8005F364_5FF64(temp_v0_14);
                
                // Check if player has empty item slot
                if (PlayerHasEmptyItemSlot(system->current_player_index) == -1) {
                    func_800EC414_100034_shared_board(0x3F0A);  // Inventory full message
                }
                
                func_800DE858_F2478_shared_board();
                HuPrcSleep(5);
                
                // Wait for input
                while (!(func_800DE84C_F246C_shared_board() & 0xFF)) {
                    HuPrcVSleep();
                }
                
                HuPrcSleep(0xA);
                HuPrcChildLink(temp_s6, func_800E8EDC_FCAFC_shared_board(1.3f));
                HuPrcChildWait();
                HuPrcSleep(1);
                
                // Update item block history
                gPrevItemBlockSpaceIndexes[D_800D1F7A_D2B7A++] = gItemBlockSpaceIndex;
                D_800D1F7A_D2B7A = D_800D1F7A_D2B7A % 10;
                gItemBlockSpaceIndex = -1;
                func_800FC594_1101B4_shared_board();
            }
            
            if (var_s3->space_type == SPACE_HAPPENING) {
                goto label;
            } else {
                short temp_v0_15;
                temp_v0_15 = func_800FA818_10E438_shared_board(1);
                
                if (temp_v0_15 == 0) {
                    goto label;
                } else {
                    GwSystem.unk_58 = temp_v0_15;
                    GwSystem.playerIndexVisitingBowser = (1 << temp_v0_4->turn); //?
                    func_800FF900_113520_shared_board(temp_v0_4->turn, 3);
                    
                    temp_v0_16 = func_800FAB98_10E7B8_shared_board(temp_v0_4, 0);
                    
                    if (temp_v0_16 == 0) {
                        goto label; //?
                        func_800FA448_10E068_shared_board();
                    } else if (temp_v0_16 == 1) {
                        HuPrcSleep(-1);
                    }
                    func_800FA95C_10E57C_shared_board();
                }
            }
        case 8: 
            func_800FA448_10E068_shared_board();
            label:
            func_800ECDD4_1009F4_shared_board(-1, var_s3->space_type);
            func_800F4798_1083B8_shared_board(system->current_player_index, temp_v0_4->color);
            
            switch (var_s3->space_type) {
            case SPACE_BLUE:  // BLUE SPACE
                var_v1 = (GWBoardFlagCheck(2) != 0) ? 2 : 1;  // Last 5 turns doubles coins
                var_s0 = var_v1*2;
                var_s0 += var_v1;

                label181C:
                ShowPlayerCoinChange(system->current_player_index, var_s0);
                func_800F5D44_109964_shared_board(system->current_player_index, var_s0);
                HuPrcSleep(0x1E);
                goto label2444;
               
                
            case SPACE_RED:  // RED SPACE
                var_v1 = (GWBoardFlagCheck(2) != 0) ? 2 : 1;
                var_s0 = var_v1*2;
                var_s0 += var_v1;
                var_s0 = -var_s0;
                goto label181C;
                
                // ShowPlayerCoinChange(system->current_player_index, var_s0);
                // func_800F5D44_109964_shared_board(system->current_player_index, var_s0);
                break;
                
            case SPACE_HAPPENING:  // HAPPENING SPACE
                if (D_80101B6C_11578C_shared_board == 0) {
                    goto label2444;
                }
                
                // Execute board-specific happening event
                HuPrcChildLink(temp_s6, omAddPrcObj(D_80101B6C_11578C_shared_board, 0x4800U, 0, 0));
                HuPrcChildWait();
                
                // Special handling for board 3
                if (system->current_board_index == 3 && GwSystem.boardData.halfWordBytes[3] != 0) {
                    GwSystem.boardData.halfWordBytes[3] = 0;
                    goto label654;  // Jump back to state 10 (dice roll)
                }
                
                // Check for another duel minigame
                temp_v0_18 = func_800FA818_10E438_shared_board(1);
                
                if (temp_v0_18 == 0) {
                    goto label2444;
                }
                GwSystem.unk_58 = temp_v0_18;
                GwSystem.playerIndexVisitingBowser = (1 << MBGetPlayerStruct(-1)->turn); //?
                func_800FF900_113520_shared_board(MBGetPlayerStruct(-1)->turn, 3);
                
                temp_v0_16 = func_800FAB98_10E7B8_shared_board(temp_v0_4, 1);
                
                if (temp_v0_16 == 0) {
                    goto label2444;
                } else if (temp_v0_16 == 1) {
                    HuPrcSleep(-1);
                }
                func_800FA95C_10E57C_shared_board();
                func_800FA448_10E068_shared_board();
                goto label2444;
                
            case SPACE_CHANCE_TIME:
                D_800D1240_D1E40 = 0x10;
                
                // Set up team groups
                for (var_s1 = 0; var_s1 < 4; var_s1++) {
                    temp_s0_2 = MBGetPlayerStruct(var_s1);
                    temp_s0_2->group = (var_s1 != GetCurrentPlayerIndex());
                }
                
                // Trigger event minigame
                func_800FF794_1133B4_shared_board(0x6A, 0, 5, 1);
                HuPrcSleep(-1);
                HuPrcSleep(0x1E);
                goto label2444;
                
            case SPACE_ITEM:
                D_800D037C_D0F7C = 0;
                HuPrcSleep(8);
                
                // Check if last turn
                if (system->current_turn == system->total_turns) {
                    func_800EC414_100034_shared_board(0x3C01);  // Last turn message
                    goto label2444;
                }
                
                // Check if inventory full
                if (PlayerHasEmptyItemSlot(system->current_player_index) == -1) {
                    func_800EC414_100034_shared_board(0x3C00);  // Inventory full
                    goto label2444;
                }
                
                // Item shop - random outcome
                temp_v0_20 = func_800EEF80_102BA0_shared_board(5.0f);

                switch (temp_v0_20) {
                case 0:
                    func_800F85C0_10C1E0_shared_board();  // Shop outcome 1
                    goto label2444;                    
                case 1:
                    func_800F85E4_10C204_shared_board();  // Shop outcome 2
                    goto label2444;                    
                default:
                    // Item minigame option
                    if (func_800F2198_105DB8_shared_board(-1) == 0 || system->show_com_minigames == 0) {
                        goto label1d70;
                    }
                                                // COM item minigame logic
                    WipeCreateOut(6, 0x10);
                    HuPrcSleep(0x11);
                    HuPrcSleep(5);
                    WipeCreateIn(6, 0x10);
                    HuPrcSleep(0x11);


                    temp_s2 = RNGPercentChance(0x42) ? 0 : 1;
                    
                    
                    // AI decision logic
                    if (!(func_800EEF80_102BA0_shared_board(100.0f) >= D_80101C24_115844_shared_board[GwPlayer[system->current_player_index].cpu_difficulty])) {
                        // AI accepts - determine item
                        var_s1 = 0;
                        temp_s0_3 = BoardPlayerRankCalc(system->current_player_index);
                        //extern s8 D_80101DAC_1159CC_shared_board[][4][2];
                        temp_s0_4 = D_80101D2C_11594C_shared_board[temp_s2][temp_s0_3][BoardGetTurnTier(-1)];
                        temp_a0 = func_800EEF80_102BA0_shared_board(100.0f);

                        
                        
                        // Find item based on weighted table
                        //something is slightly off here...
                        for (var_s1 = 0; var_s1 < 8; var_s1++) {
                            if (D_80101C8C_1158AC_shared_board[temp_s2][temp_s0_4][var_s1] > temp_a0) {
                                break;
                            }               
                        }                            
                        

                        // Display message
                        ShowMessage(-1, 0x3C22, D_80101C4C_11586C_shared_board[temp_s2][var_s1], 0, 0, 0, 0);
                        func_800EC6C8_1002E8_shared_board();
                        func_800EC6EC_10030C_shared_board();
                        
                        // Store item
                        GwPlayer[system->current_player_index].bonusCoin = D_80101C2C_11584C_shared_board[temp_s2][var_s1];
                        
                        // Display item sprite with animation
                        temp_s2_2 = HuSprGrpCreate(1U, 5U);
                        temp_v0_21 = DataRead(D_8010197C_11559C_shared_board[D_80101C2C_11584C_shared_board[temp_s2][var_s1]]);
                        temp_s3_3 = func_80055810_56410(temp_v0_21);
                        DataClose(temp_v0_21);
                        
                        func_80055024_55C24(temp_s2_2, 0, temp_s3_3, 0);
                        HuSprPriSet(temp_s2_2, 0, 0xAU);
                        func_800550F4_55CF4(temp_s2_2, 0, 0);
                        HuSprAttrSet(temp_s2_2, 0, 0x180C);
                        func_80054904_55504(temp_s2_2, 0, 0xA0, 0x5A);
                        func_80055458_56058(temp_s2_2, 0, 0U);
                        HuAudFXPlay(0x10);
                        
                        // Animate sprite appearing
                        for (var_s1 = 0; var_s1 < 0xA; var_s1++) {
                            func_80055458_56058(temp_s2_2, 0, (var_s1 * 25) & 0xFFFF);
                            HuPrcVSleep();
                        }
                        
                        func_80055458_56058(temp_s2_2, 0, 0x100U);
                        HuPrcSleep(5);
                        func_800F2304_105F24_shared_board(-1, 5, 0);
                        HuPrcSleep(5);
                        func_8004ACE0_4B8E0(0x2BD, system->current_player_index);
                        HuPrcSleep(0x14);
                        func_800F2388_105FA8_shared_board(-1, -1, 0, 5, 2);
                        HuPrcSleep(0xA);
                        
                        // Clean up sprite
                        HuSprGrpKill(temp_s2_2);
                        HuSprKill(temp_s3_3);
                        goto tempCase17;
                    }
                    

                    func_800EC414_100034_shared_board(0x3C32);
                    goto label2444;
                    //missing  goto label2444; here (but then code after is unreachable)

                    label1d70:
                    func_800F7108_10AD28_shared_board();
    
                    for (var_s1 = 0; var_s1 < 4; var_s1++) {
                        GwPlayer[var_s1].group = 1;
                    }
                    
                    temp_v0_4->group = 0;
                    HuPrcChildLink(temp_s6, func_800E0F84_F4BA4_shared_board());
                    HuPrcChildWait();
                    
                    D_800D1240_D1E40 = 0x11;
                    D_80105664_119284_shared_board = 2;
                    D_80105666_119286_shared_board = 1;
                    D_800D1360_D1F60.unk_20 = 6;
                    HuPrcSleep(-1);
                    goto label2444;
                }

                tempCase17:
                GwPlayer[system->current_player_index].itemNo[PlayerHasEmptyItemSlot(system->current_player_index)] = 
                    GwPlayer[system->current_player_index].bonusCoin;
                HuPrcSleep(0x1E);
                goto label2444;
            case SPACE_BATTLE:
                if (!(func_800FB624_10F244_shared_board(temp_v0_4))) {
                    goto label2444;
                } else {
                    D_800D037C_D0F7C = 0;
                    func_800F7108_10AD28_shared_board();
                    HuPrcChildLink(temp_s6, func_800E0C3C_F485C_shared_board());
                    HuPrcChildWait();
                    D_800D1240_D1E40 = 0x12;
                    D_80105664_119284_shared_board = 2;
                    D_80105666_119286_shared_board = 1;
                    D_800D1380_D1F80_shared_board = 8;
                    HuPrcSleep(-1);
                }

                test:
                for (var_s1 = 0; var_s1 < 4; var_s1++) {
                    if (GwPlayer[var_s1].bonusCoin != 3) {
                        break;
                    }
                }
                
                if (var_s1 >= 4) {
                    // All players done with battle
                    func_800FC3D0_10FFF0_shared_board();
                }
                
                goto label2444;
            case SPACE_BOWSER:  // BOWSER SPACE
                D_800D1240_D1E40 = 6;
                GwSystem.playerIndexVisitingBowser = system->current_player_index;
                func_800FF794_1133B4_shared_board(0x50, 0, 3, 1);
                HuPrcSleep(-1);
                HuPrcSleep(0x1E);
                goto label2444;
                
            case SPACE_GAME_GUY:  // GAME GUY SPACE
                HuPrcSleep(8);
                
                // Create game guy object
                temp_v0_22 = MBModelCreate(0x3EU, 0);
                func_800D9714_ED334_shared_board(temp_v0_22);
                HuVecCopy3F(&temp_v0_22->coords, &temp_v0_4->player_obj->coords);
                temp_v0_22->unk30.x = 100.0f;
                
                // Animate game guy appearing on screen
                while (temp_v0_22->unk30.x >= 30.0f) {
                    temp_v0_22->unk30.x -= 2.0f;
                    HuPrcVSleep();
                }
                
                temp_s1_5 = func_800EDB98_1017B8_shared_board(temp_v0_22, 5.0f, 2.0f);
                HuAudFXPlay(0x2A1);
                
                if (GwPlayer[system->current_player_index].coin != 0) {
                    // Take all coins
                    func_800EC590_1001B0_shared_board(0xA, 0x2F00);
                    GwPlayer[system->current_player_index].gameCoin = 
                        GwPlayer[system->current_player_index].coin;
                    
                    ShowPlayerCoinChange(system->current_player_index, 
                                       -GwPlayer[system->current_player_index].coin);
                    func_800F5D44_109964_shared_board(system->current_player_index,
                                                     -GwPlayer[system->current_player_index].coin);
                    HuPrcSleep(0x1E);
                    func_800EC590_1001B0_shared_board(0xA, 0x2F02);
                    omDelPrcObj(temp_s1_5);
                    
                    // Animate game guy leaving with player
                    while (temp_v0_22->unk30.x >= 10.0f) {
                        temp_v0_22->unk30.x -= 2.0f;
                        HuPrcVSleep();
                    }
                    
                    func_800EE688_1022A8_shared_board(temp_v0_22, 2.0f, 0.0001f);
                    func_800EE688_1022A8_shared_board(temp_v0_4->player_obj, 2.0f, 0.0001f);
                    HuPrcSleep(0x1E);
                } else {
                    func_800EC590_1001B0_shared_board(0xA, 0x2F01);
                    omDelPrcObj(temp_s1_5);
                    // Animate game guy leaving with player
                    while (temp_v0_22->unk30.x <= 100.0f) {
                        temp_v0_22->unk30.x += 4.0f;
                        HuPrcVSleep();
                    }
                    func_800D9B54_ED774_shared_board(temp_v0_22);
                    goto label2488;
                }
                
                    
                if (func_800F2198_105DB8_shared_board(-1) != 0 && system->show_com_minigames != 0) {
                    // COM game guy - immediate result
                    WipeCreateOut(9, 0x10);
                    HuPrcSleep(0x11);
                    func_800D9B54_ED774_shared_board(temp_v0_22);
                    func_800EE688_1022A8_shared_board(temp_v0_4->player_obj, 0, 0);
                    temp_v0_4->player_obj->unk30.x = 0.0f;
                    HuPrcSleep(5);
                    WipeCreateIn(9, 0x10);
                    HuPrcSleep(0x11);
                    
                    // Weighted random multiplier
                    temp_v1_8 = func_800EEF80_102BA0_shared_board(1000.0f) + 1;

                    for (var_s1 = 0; var_s1 < 7; var_s1++) {
                        if (D_80101C08_115828_shared_board[var_s1][1] >= temp_v1_8) {
                            break;
                        }
                    }

                    
                    temp_a0_3 = D_80101C08_115828_shared_board[var_s1][0];
                    
                    if (temp_a0_3 != 0) {
                        // Won multiplier
                        var_s1_12 = GwPlayer[system->current_player_index].gameCoin * temp_a0_3;
                        
                        if (var_s1_12 > 999) {
                            var_s1_12 = 999;
                        }
                        
                        sprintf(sp48, "%d", var_s1_12);
                        ShowMessage(-1, 0x2F03, sp48, 0, 0, 0, 0);
                        func_800EC6C8_1002E8_shared_board();
                        func_800EC6EC_10030C_shared_board();
                        
                        ShowPlayerCoinChange(system->current_player_index, var_s1_12);
                        func_800F5D44_109964_shared_board(system->current_player_index, var_s1_12);
                        HuPrcSleep(0x14);
                        func_800F2304_105F24_shared_board(-1, 5, 0);
                        func_8004ACE0_4B8E0(0x274, system->current_player_index);
                        func_800F22C0_105EE0_shared_board(-1);
                    } else {
                        // Lost everything
                        func_800EC590_1001B0_shared_board(-1, 0x2F04);
                        func_800F2304_105F24_shared_board(-1, 3, 0);
                        func_8004ACE0_4B8E0(0x286, system->current_player_index);
                        func_800F22C0_105EE0_shared_board(-1);
                        HuPrcSleep(0x14);
                    }
                    
                    func_800F2388_105FA8_shared_board(-1, -1, 0, 5, 2);
                    HuPrcSleep(0xA);
                    goto label2488;
                } else {
                    // Setup for game guy minigame
                    D_800D1240_D1E40 = 0x13;
                    D_80105664_119284_shared_board = 2;
                    D_80105666_119286_shared_board = 1;
                    D_800D1360_D1F60.unk_20 = 9;
                    
                    for (var_s1 = 0; var_s1 < 4; var_s1++) {
                        GwPlayer[var_s1].group = 1;
                    }
                    temp_v0_4->group = 0;
                    
                    // Select minigame based on weighted random
                    temp_a0_4 = func_800EEF80_102BA0_shared_board(100.0f);
                    var_v1_3 = 0;

                    for (var_v1_3 = 0; var_v1_3 < 4U; var_v1_3++) {
                        if (D_80101C04_115824_shared_board[var_v1_3] > temp_a0_4) {
                            break;
                        }
                    }
                    
                    if (var_v1_3 == 4) {
                        var_v1_3 = 3;
                    }
                    
                    system->minigame_index = D_80101C00_115820_shared_board[var_v1_3];
                    GwSystem.playerIndexVisitingBowser = system->current_player_index;
                }
                
                HuPrcSleep(-1);
                goto label2438;
                
            case SPACE_UNK:
            case SPACE_BANK:
            case SPACE_START:
            case SPACE_UNK2:
            case SPACE_UNK3:
            case SPACE_ARROW:
            case SPACE_STAR:
            default:
                goto label2444;
            }
        case 17:
            goto tempCase17;
        case 18:
            goto test;
        case 19:
            label2438:
                func_800FC4E0_110100_shared_board();
                label2444:
                D_800D1240_D1E40 = 7;
                D_80105660_119280_shared_board = func_800EBAC8_FF6E8_shared_board(var_s5, 5);
                if (D_80105664_119284_shared_board < 0) {
                    goto label2488;
                }
                HuPrcSleep(-1);
        case 7:
            HuPrcSleep(0x1E);
            label2488:
            D_800D037C_D0F7C = 0;
            
            // END OF TURN: Check for end of round minigames
            if (system->current_player_index >= 3) {
                func_800EBAC8_FF6E8_shared_board(-3, 7);
                func_8001FDE8_209E8(MBGetPlayerStruct(3)->player_obj->omObj1->model[0]);
                D_800A12D4 = 0;
                func_800F7108_10AD28_shared_board();
                
                HuPrcChildLink(temp_s6, func_800E0A14_F4634_shared_board());
                HuPrcChildWait();
                
                if (system->minigame_index >= 0) {
                    D_800D1240_D1E40 = 0;
                    
                    // Determine minigame type
                    if (system->total_turns >= 0 && system->current_turn >= system->total_turns) {
                        if (GwSystem.unk_52 == 2) {
                            D_80105664_119284_shared_board = 3;
                        } else {
                            D_80105664_119284_shared_board = 0x23;
                        }
                    } else {
                        D_80105664_119284_shared_board = 3;
                    }
                    D_80105666_119286_shared_board = 1;
                    D_800D1360_D1F60.unk_20 = 0xA;
                    
                    for (var_s0_2 = 0; var_s0_2 < 4; var_s0_2++) {
                        func_800F482C_10844C_shared_board(var_s0_2);
                    }
                    
                    HuPrcSleep(-1);
                }
            }
            
            // Check for game end condition
            if (func_800F933C_10CF5C_shared_board() != 0) {
                D_800D1240_D1E40 = 0;
                D_80105664_119284_shared_board = 1;
                HuPrcSleep(-1);
            }
            
            HuPrcSleep(4);
            
            HuPrcChildLink(temp_s6, func_800F292C_10654C_shared_board());
            HuPrcChildWait();
            
            func_800F92A0_10CEC0_shared_board();
            
            // Hide all players
            for (var_s1 = 0; var_s1 < 4; var_s1++) {
                func_800ECC28_100848_shared_board(var_s1);
                func_800D9CE8_ED908_shared_board(MBGetPlayerStruct(var_s1)->player_obj, -1, 2);
            }
            
            HuPrcVSleep();
        
            if (GwSystem.current_board_index == 0 && GWBoardFlagCheck(0x12) != 0) {
                func_800EBEC8_FFAE8_shared_board();
                GWBoardFlagClear(0x12);
            }
            
            func_800FF840_113460_shared_board(0);
            D_800D1240_D1E40 = 1;
        }
    }
}
