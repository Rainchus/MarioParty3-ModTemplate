#include "marioparty.h"

s32 MBKettouExec(GW_PLAYER* arg0, s32 arg1);
s32 MBKettouModifiedExec(GW_PLAYER* arg0, s32 arg1);

extern s16 D_800D037C_D0F7C;
extern s16 D_800C9930_CA530;
extern s16 D_800CE206;
extern s32 D_800D1240_D1E40;
extern s16 D_80105664_119284_shared_board;
extern s16 D_80105666_119286_shared_board;
extern s16 D_800D1380_D1F80;

void func_8004A670_4B270(s32);
void HuPrcSleep(s32 time);
s16 func_8004A5C4_4B1C4(s32);
Object* MBModelCreate(u8, u32*);
void Hu3DModelScaleSet(s16 arg0, f32 x, f32 y, f32 z);
void func_8001FDE8_209E8(s16);
void HuVecCopy3F(Vec * out, Vec * a);
void HuPrcVSleep(void);
void MBBattleKuriboObjMain(omObjData* arg0);
omObjData* omAddObj(s16 priority, u16 arg1, u16 arg2, s16 arg3, omObjFunc func);
s16 HuAudFXPlay(s16 seId);
void func_800E2260_F5E80_shared_board(s32, char*);
void MBDlgWinExecY(s16 arg0, s32 arg1, s32 arg2);
void MBBattleKuriboEnd(void);
void func_8004A7C4_4B3C4(s32);
void func_8004A72C_4B32C(s32);
void omPrcSetStatBit(Process*, s32);
Process* omAddPrcObj(process_func func, u16 priority, s32 stackSize, s32 extDataSize);
void func_800F9C68_10D888_shared_board(void);
void MBDlgWinInsertCreate(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s32 func_800FA104_10DD24_shared_board(u8* arg0);
void MBDlgWinClose(void);
void MBDlgWinKill(void);
Process* HuPrcCurrentGet(void);
void func_8010067C_11429C_shared_board(s32);
void func_800FC8A4_1104C4_shared_board(void);
extern int _sprintf(char *s, const char *fmt, ...);
void func_8006022C_60E2C(u32 mesg, s32);
void func_80060394_60F94(s32, s16*, s32);
s16 MBWinCreate(s16 arg0, s16* arg1, s16 arg2);
void func_8005B6BC_5C2BC(s16 win_id, u32 arg1, s8 arg2);
void func_8005B43C_5C03C(s16, s32, s32, s32);
void func_80061388_61F88(s16);
s32 func_800F2198_105DB8_shared_board(s16);
s32 func_800F9F84_10DBA4_shared_board(s32 playerNo);
void func_80061A5C_6265C(s16, s32);
void func_8005F364_5FF64(s16);
void MBCoinChangeStatusCreate(s32, s32);
void func_800F5BF4_109814_shared_board(s32, s32, s32);
void func_800F7108_10AD28_shared_board(void);
void HuPrcChildLink(Process*process, Process*child);
void HuPrcChildWait(void);
Process* func_800E11C0_F4DE0_shared_board(s8, s32);
void omPrcResetStatBit(Process*, s32);

extern Object* mbBattleKuriboMdl;
extern Object* mbBattleKuriboUpperMdl;
extern omObjData* mbBattleKuriboObj;
extern u16 D_800C9520_CA120[];
extern s16 D_800D0590_D1190[];

void newKettouDecision(GW_PLAYER* arg0, s32 arg1) {
    if (1) {
        MBKettouExec(arg0, arg1);
    } else {
        MBKettouModifiedExec(arg0, arg1);
    }
}

s32 MBKettouExec(GW_PLAYER* arg0, s32 arg1) {
    char sp20[MB_MAX_PLAYERS][16];
    u8 sp60[MB_MAX_PLAYERS+2]; //+2?
    s16 sp68[2];
    s32 sp84;
    
    Process* temp_s0_2;
    s32 var_s1_3;
    s32 var_s2;
    s32 var_s5;
    s32 var_s0_3;
    s32 var_s1;
    s32 var_s3;
    s32 var_s4;
    s32 var_s6;
    s32 var_s7;
    s32 i;
    s8* showComMinigames = &GwSystem.show_com_minigames;

    var_s7 = 0;
    var_s4 = 0;
    D_800D037C_D0F7C = 0;
    func_8004A670_4B270(0xF);
    HuPrcSleep(0x10);
    D_800C9930_CA530 = func_8004A5C4_4B1C4(0x3E);
    D_800D037C_D0F7C = 1;
    mbBattleKuriboMdl = MBModelCreate(0xC, NULL);
    Hu3DModelScaleSet(mbBattleKuriboMdl->omObj1->model[0], 0.0f, 0.0f, 0.0f);
    func_8001FDE8_209E8(mbBattleKuriboMdl->omObj1->model[0]);
    mbBattleKuriboMdl->flags |= 1;
    mbBattleKuriboUpperMdl = MBModelCreate(0x1F, NULL);
    Hu3DModelScaleSet(mbBattleKuriboUpperMdl->omObj1->model[0], 0.0f, 0.0f, 0.0f);
    HuVecCopy3F(&mbBattleKuriboMdl->coords, &arg0->player_obj->coords);
    HuVecCopy3F(&mbBattleKuriboUpperMdl->coords, &arg0->player_obj->coords);
    mbBattleKuriboMdl->unk30.x = 120.0f;
    mbBattleKuriboUpperMdl->unk30.x = 122.0f;
    
    while (mbBattleKuriboMdl->unk30.x > 30.0f) {
        HuPrcVSleep();
        mbBattleKuriboMdl->unk30.x -= 1.0f;
        mbBattleKuriboUpperMdl->unk30.x -= 1.0f;
    }
    
    mbBattleKuriboObj = omAddObj(0x1F4, 0U, 0U, -1, MBBattleKuriboObjMain);
    mbBattleKuriboObj->rot.x = 180.0f;
    HuAudFXPlay(0x25B);
    var_s1 = 0;
    
    if (GwPlayer[arg0->turn].coin != 0) {
        var_s6 = 0;
        
        do { //reg alloc hack
        // Count valid duel targets
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            if ((GwSystem.unk_58 >> i) & 1 && GwPlayer[i].coin != 0) {
                var_s7++; //valid duel target
                var_s4 = i;
                var_s1++;
                sp20[var_s4][0] = 8;
                sp60[var_s4] = 1;
                var_s6 |= 1 << var_s4;
            } else {
                sp20[i][0] = 1; //invalid duel target (disable prompt?)
                sp60[i] = 0;
            }
            
            func_800E2260_F5E80_shared_board(i, &sp20[i][1]);
        }
        } while(0);
        
        if (var_s1 == 0) {
            MBDlgWinExecY(6, 0x4002, 0x88);
            MBBattleKuriboEnd();
            D_800D037C_D0F7C = 0;
            func_8004A7C4_4B3C4(0x1E);
            HuPrcSleep(0xF);
            func_8004A72C_4B32C(0x1E);
            D_800D037C_D0F7C = 1;
            D_800C9930_CA530 = -1;
            D_800CE206 = 0;
            omPrcSetStatBit(omAddPrcObj(func_800F9C68_10D888_shared_board, 0U, 0, 0), 0xA0);
            HuPrcSleep(0x1F);
            return 0;
        } else {
            MBDlgWinExecY(6, 0x4000, 0x88);
        }
    } else {
        MBDlgWinExecY(6, 0x4001, 0x88);
        MBBattleKuriboEnd();
        D_800D037C_D0F7C = 0;
        func_8004A7C4_4B3C4(0x1E);
        HuPrcSleep(0xF);
        func_8004A72C_4B32C(0x1E);
        D_800D037C_D0F7C = 1;
        D_800C9930_CA530 = -1;
        D_800CE206 = 0;
        omPrcSetStatBit(omAddPrcObj(func_800F9C68_10D888_shared_board, 0U, 0, 0), 0xA0);
        HuPrcSleep(0x1F);
        return 0;
    }

    // Target selection loop
    while (1) {
        if (var_s7 >= 2 || (GwSystem.playerIndexVisitingBowser & 0x8000)) {
            tempLabel:
            //?
            sp60[4] = 1;
            sp60[5] = 1;
            MBDlgWinInsertCreate(6, 0x5C02, (u32) sp20[0], (u32) sp20[1], (u32) sp20[2], (u32) sp20[3], 0);
            var_s4 = func_800FA104_10DD24_shared_board(sp60);
            MBDlgWinClose();
            MBDlgWinKill();

            switch (var_s4) {
            case 4:
                i = 0;
                var_s1 = var_s7;
                for (i = 0; i < MB_MAX_PLAYERS; i++) {
                    if (var_s6 & (1 << i)) {
                        if (var_s1-- != 0) {
                            break;
                        }
                    }
                }
                var_s4 = i;
                break;
            case 5:
                D_800CDD58_CE958 = 1;
                D_800D037C_D0F7C = 0;
                omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
                func_8010067C_11429C_shared_board(GwPlayer[GwSystem.current_player_index].pad);
                omPrcResetStatBit(HuPrcCurrentGet(), 0x80);
                D_800CDD58_CE958 = 0;
                D_800D037C_D0F7C = 1;
                func_800FC8A4_1104C4_shared_board();
                goto tempLabel; // Go back to selection menu
            }
        }
        
        var_s3 = 0;
        break; // Exit selection loop
    }
    
    // Coin wager selection
    _sprintf(sp20[0], "%d", 0x3E7);
    func_8006022C_60E2C((u32)sp20[0], 0);
    func_80060394_60F94(1, sp68, 0x4003);
    sp84 = MBWinCreate(6, sp68, 0x64);
    
    var_s1_3 = 1;
    
    var_s5 = 1;
    
    if (GwPlayer[GwSystem.current_player_index].coin <= GwPlayer[var_s4].coin) {
        var_s2 = GwPlayer[GwSystem.current_player_index].coin;
    } else {
        var_s2 = GwPlayer[var_s4].coin;
    }
    
    _sprintf(sp20[0], "%d", var_s1_3);
    func_8005B6BC_5C2BC(sp84, (u32) &sp20, 0);
    func_8005B43C_5C03C(sp84, 0x4003, -1, -1);
    func_80061388_61F88(sp84);
    
    if (func_800F2198_105DB8_shared_board(-1) != 0) {
        var_s3 = func_800F9F84_10DBA4_shared_board(var_s4);
        do { //reg alloc hack
        if (var_s2 < var_s3) {
            var_s3 = var_s2;
        }
        if (var_s3 <= 0) {
            var_s3 = 1;
        }
        } while(0);
    }
    
    var_s0_3 = 5;
    
    // Coin amount input loop
    while (1) {
        if (func_800F2198_105DB8_shared_board(-1) == 0) {
            // Player controlled input
            if (D_800C9520_CA120[GwPlayer[GwSystem.current_player_index].pad] & A_BUTTON) { //?
                break; // Player confirmed selection
            }
            
            if (D_800D0590_D1190[GwPlayer[GwSystem.current_player_index].pad] & U_JPAD) {
                var_s1_3++;
            }
            if (D_800D0590_D1190[GwPlayer[GwSystem.current_player_index].pad] & D_JPAD) {
                var_s1_3--;
            }
            if (D_800D0590_D1190[GwPlayer[GwSystem.current_player_index].pad] & L_JPAD) {
                var_s1_3 -= 0xA;
            }
            if (D_800D0590_D1190[GwPlayer[GwSystem.current_player_index].pad] & R_JPAD) {
                var_s1_3 += 0xA;
            }
        } else {
            var_s0_3--;
            // AI controlled input
            
            if (var_s0_3 == -1) {
                if (var_s3 != var_s1_3) {
                    if ((var_s3 % 10) != (var_s1_3 % 10)) {
                        var_s1_3 += 1;
                        var_s0_3 = 5;
                    } else if ((var_s3 / 10) != (var_s1_3 / 10)) {
                        var_s1_3 += 0xA;
                        var_s0_3 = 5;
                    }
                } else {
                    break; // AI finished selecting amount
                }
            }
        }
            
        // Clamp value to valid range
        if (var_s5 == 1 && var_s1_3 < 1) {
            var_s1_3 = var_s2;
        }
        if (var_s5 == var_s2 && var_s2 < var_s1_3) {
            var_s1_3 = 1;
        }
        if (var_s1_3 <= 0) {
            var_s1_3 = 1;
        }
        if (var_s2 < var_s1_3) {
            var_s1_3 = var_s2;
        }
        
        if (var_s5 != var_s1_3) {
            HuAudFXPlay(0x246);
        }
        
        var_s5 = var_s1_3;
        
        _sprintf(sp20[0], "%d", var_s1_3);
        func_8005B6BC_5C2BC(sp84, (u32) &sp20, 0);
        func_8005B43C_5C03C(sp84, 0x4003, -1, -1);
        
        
        HuPrcVSleep();
    }
    
    HuAudFXPlay(0x247);
    func_80061A5C_6265C(sp84, 0);
    func_8005F364_5FF64(sp84);
    HuPrcSleep(0xA);
    MBCoinChangeStatusCreate(GwSystem.current_player_index, -var_s1_3);
    func_800F5BF4_109814_shared_board(GwSystem.current_player_index, -var_s1_3, 0);
    MBCoinChangeStatusCreate(var_s4, -var_s1_3);
    func_800F5BF4_109814_shared_board(var_s4, -var_s1_3, 1);
    HuPrcSleep(0x1E);
    MBDlgWinExecY(6, 0x4004, 0x88);
    
    if (func_800F2198_105DB8_shared_board(-1) != 0) {
        if ((func_800F2198_105DB8_shared_board(var_s4) != 0)) {
            if (*showComMinigames != 0) {
                GwSystem.unk_58 = var_s4;
                GwSystem.playerIndexVisitingBowser = var_s1_3;
                return 2;                
            }
        }
    }
    
    D_800D037C_D0F7C = 0;
    func_800F7108_10AD28_shared_board();
    temp_s0_2 = func_800E11C0_F4DE0_shared_board(GwSystem.current_player_index, var_s4);
    HuPrcChildLink(HuPrcCurrentGet(), temp_s0_2);
    HuPrcChildWait();
    
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        GwPlayer[i].group = 2;
    }

    arg0->group = 0;
    GwPlayer[var_s4].group = 1;
    GwSystem.unk_58 = var_s4;
    GwSystem.playerIndexVisitingBowser = var_s1_3;

    D_800D1240_D1E40 = (arg1 == 0) ? 8 : 9;
    
    D_80105664_119284_shared_board = 2;
    D_80105666_119286_shared_board = 1;
    D_800D1380_D1F80 = 8;
    return 1;
}



//star duel version
s32 MBKettouModifiedExec(GW_PLAYER* arg0, s32 arg1) {
    char sp20[MB_MAX_PLAYERS][16];
    u8 sp60[MB_MAX_PLAYERS+2]; //+2?
    s16 sp68[2];
    s32 sp84;
    
    Process* temp_s0_2;
    s32 var_s1_3;
    s32 var_s2;
    s32 var_s5;
    s32 var_s0_3;
    s32 var_s1;
    s32 var_s3;
    s32 var_s4;
    s32 var_s6;
    s32 var_s7;
    s32 i;
    s8* showComMinigames = &GwSystem.show_com_minigames;

    var_s7 = 0;
    var_s4 = 0;
    D_800D037C_D0F7C = 0;
    func_8004A670_4B270(0xF);
    HuPrcSleep(0x10);
    D_800C9930_CA530 = func_8004A5C4_4B1C4(0x3E);
    D_800D037C_D0F7C = 1;
    mbBattleKuriboMdl = MBModelCreate(0xC, NULL);
    Hu3DModelScaleSet(mbBattleKuriboMdl->omObj1->model[0], 0.0f, 0.0f, 0.0f);
    func_8001FDE8_209E8(mbBattleKuriboMdl->omObj1->model[0]);
    mbBattleKuriboMdl->flags |= 1;
    mbBattleKuriboUpperMdl = MBModelCreate(0x1F, NULL);
    Hu3DModelScaleSet(mbBattleKuriboUpperMdl->omObj1->model[0], 0.0f, 0.0f, 0.0f);
    HuVecCopy3F(&mbBattleKuriboMdl->coords, &arg0->player_obj->coords);
    HuVecCopy3F(&mbBattleKuriboUpperMdl->coords, &arg0->player_obj->coords);
    mbBattleKuriboMdl->unk30.x = 120.0f;
    mbBattleKuriboUpperMdl->unk30.x = 122.0f;
    
    while (mbBattleKuriboMdl->unk30.x > 30.0f) {
        HuPrcVSleep();
        mbBattleKuriboMdl->unk30.x -= 1.0f;
        mbBattleKuriboUpperMdl->unk30.x -= 1.0f;
    }
    
    mbBattleKuriboObj = omAddObj(0x1F4, 0U, 0U, -1, MBBattleKuriboObjMain);
    mbBattleKuriboObj->rot.x = 180.0f;
    HuAudFXPlay(0x25B);
    var_s1 = 0;
    
    if (GwPlayer[arg0->turn].coin != 0) {
        var_s6 = 0;
        
        do { //reg alloc hack
        // Count valid duel targets
        for (i = 0; i < MB_MAX_PLAYERS; i++) {
            if ((GwSystem.unk_58 >> i) & 1 && GwPlayer[i].coin != 0) {
                var_s7++; //valid duel target
                var_s4 = i;
                var_s1++;
                sp20[var_s4][0] = 8;
                sp60[var_s4] = 1;
                var_s6 |= 1 << var_s4;
            } else {
                sp20[i][0] = 1; //invalid duel target (disable prompt?)
                sp60[i] = 0;
            }
            
            func_800E2260_F5E80_shared_board(i, &sp20[i][1]);
        }
        } while(0);
        
        if (var_s1 == 0) {
            MBDlgWinExecY(6, 0x4002, 0x88);
            MBBattleKuriboEnd();
            D_800D037C_D0F7C = 0;
            func_8004A7C4_4B3C4(0x1E);
            HuPrcSleep(0xF);
            func_8004A72C_4B32C(0x1E);
            D_800D037C_D0F7C = 1;
            D_800C9930_CA530 = -1;
            D_800CE206 = 0;
            omPrcSetStatBit(omAddPrcObj(func_800F9C68_10D888_shared_board, 0U, 0, 0), 0xA0);
            HuPrcSleep(0x1F);
            return 0;
        } else {
            MBDlgWinExecY(6, 0x4000, 0x88);
        }
    } else {
        MBDlgWinExecY(6, 0x4001, 0x88);
        MBBattleKuriboEnd();
        D_800D037C_D0F7C = 0;
        func_8004A7C4_4B3C4(0x1E);
        HuPrcSleep(0xF);
        func_8004A72C_4B32C(0x1E);
        D_800D037C_D0F7C = 1;
        D_800C9930_CA530 = -1;
        D_800CE206 = 0;
        omPrcSetStatBit(omAddPrcObj(func_800F9C68_10D888_shared_board, 0U, 0, 0), 0xA0);
        HuPrcSleep(0x1F);
        return 0;
    }

    // Target selection loop
    while (1) {
        if (var_s7 >= 2 || (GwSystem.playerIndexVisitingBowser & 0x8000)) {
            tempLabel:
            //?
            sp60[4] = 1;
            sp60[5] = 1;
            MBDlgWinInsertCreate(6, 0x5C02, (u32) sp20[0], (u32) sp20[1], (u32) sp20[2], (u32) sp20[3], 0);
            var_s4 = func_800FA104_10DD24_shared_board(sp60);
            MBDlgWinClose();
            MBDlgWinKill();

            switch (var_s4) {
            case 4:
                i = 0;
                var_s1 = var_s7;
                for (i = 0; i < MB_MAX_PLAYERS; i++) {
                    if (var_s6 & (1 << i)) {
                        if (var_s1-- != 0) {
                            break;
                        }
                    }
                }
                var_s4 = i;
                break;
            case 5:
                D_800CDD58_CE958 = 1;
                D_800D037C_D0F7C = 0;
                omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
                func_8010067C_11429C_shared_board(GwPlayer[GwSystem.current_player_index].pad);
                omPrcResetStatBit(HuPrcCurrentGet(), 0x80);
                D_800CDD58_CE958 = 0;
                D_800D037C_D0F7C = 1;
                func_800FC8A4_1104C4_shared_board();
                goto tempLabel; // Go back to selection menu
            }
        }
        
        var_s3 = 0;
        break; // Exit selection loop
    }
    
    // Coin wager selection
    _sprintf(sp20[0], "%d", 0x3E7);
    func_8006022C_60E2C((u32)sp20[0], 0);
    func_80060394_60F94(1, sp68, 0x4003);
    sp84 = MBWinCreate(6, sp68, 0x64);
    
    var_s1_3 = 1;
    
    var_s5 = 1;
    
    if (GwPlayer[GwSystem.current_player_index].coin <= GwPlayer[var_s4].coin) {
        var_s2 = GwPlayer[GwSystem.current_player_index].coin;
    } else {
        var_s2 = GwPlayer[var_s4].coin;
    }
    
    _sprintf(sp20[0], "%d", var_s1_3);
    func_8005B6BC_5C2BC(sp84, (u32) &sp20, 0);
    func_8005B43C_5C03C(sp84, 0x4003, -1, -1);
    func_80061388_61F88(sp84);
    
    if (func_800F2198_105DB8_shared_board(-1) != 0) {
        var_s3 = func_800F9F84_10DBA4_shared_board(var_s4);
        do { //reg alloc hack
        if (var_s2 < var_s3) {
            var_s3 = var_s2;
        }
        if (var_s3 <= 0) {
            var_s3 = 1;
        }
        } while(0);
    }
    
    var_s0_3 = 5;
    
    // Coin amount input loop
    while (1) {
        if (func_800F2198_105DB8_shared_board(-1) == 0) {
            // Player controlled input
            if (D_800C9520_CA120[GwPlayer[GwSystem.current_player_index].pad] & 0x8000) { //?
                break; // Player confirmed selection
            }
            
            if (D_800D0590_D1190[GwPlayer[GwSystem.current_player_index].pad] & 0x800) {
                var_s1_3++;
            }
            if (D_800D0590_D1190[GwPlayer[GwSystem.current_player_index].pad] & 0x400) {
                var_s1_3--;
            }
            if (D_800D0590_D1190[GwPlayer[GwSystem.current_player_index].pad] & 0x200) {
                var_s1_3 -= 0xA;
            }
            if (D_800D0590_D1190[GwPlayer[GwSystem.current_player_index].pad] & 0x100) {
                var_s1_3 += 0xA;
            }
        } else {
            var_s0_3--;
            // AI controlled input
            
            if (var_s0_3 == -1) {
                if (var_s3 != var_s1_3) {
                    if ((var_s3 % 10) != (var_s1_3 % 10)) {
                        var_s1_3 += 1;
                        var_s0_3 = 5;
                    } else if ((var_s3 / 10) != (var_s1_3 / 10)) {
                        var_s1_3 += 0xA;
                        var_s0_3 = 5;
                    }
                } else {
                    break; // AI finished selecting amount
                }
            }
        }
            
        // Clamp value to valid range
        if (var_s5 == 1 && var_s1_3 < 1) {
            var_s1_3 = var_s2;
        }
        if (var_s5 == var_s2 && var_s2 < var_s1_3) {
            var_s1_3 = 1;
        }
        if (var_s1_3 <= 0) {
            var_s1_3 = 1;
        }
        if (var_s2 < var_s1_3) {
            var_s1_3 = var_s2;
        }
        
        if (var_s5 != var_s1_3) {
            HuAudFXPlay(0x246);
        }
        
        var_s5 = var_s1_3;
        
        _sprintf(sp20[0], "%d", var_s1_3);
        func_8005B6BC_5C2BC(sp84, (u32) &sp20, 0);
        func_8005B43C_5C03C(sp84, 0x4003, -1, -1);
        
        
        HuPrcVSleep();
    }
    
    HuAudFXPlay(0x247);
    func_80061A5C_6265C(sp84, 0);
    func_8005F364_5FF64(sp84);
    HuPrcSleep(0xA);
    MBCoinChangeStatusCreate(GwSystem.current_player_index, -var_s1_3);
    func_800F5BF4_109814_shared_board(GwSystem.current_player_index, -var_s1_3, 0);
    MBCoinChangeStatusCreate(var_s4, -var_s1_3);
    func_800F5BF4_109814_shared_board(var_s4, -var_s1_3, 1);
    HuPrcSleep(0x1E);
    MBDlgWinExecY(6, 0x4004, 0x88);
    
    if (func_800F2198_105DB8_shared_board(-1) != 0) {
        if ((func_800F2198_105DB8_shared_board(var_s4) != 0)) {
            if (*showComMinigames != 0) {
                GwSystem.unk_58 = var_s4;
                GwSystem.playerIndexVisitingBowser = var_s1_3;
                return 2;                
            }
        }
    }
    
    D_800D037C_D0F7C = 0;
    func_800F7108_10AD28_shared_board();
    temp_s0_2 = func_800E11C0_F4DE0_shared_board(GwSystem.current_player_index, var_s4);
    HuPrcChildLink(HuPrcCurrentGet(), temp_s0_2);
    HuPrcChildWait();
    
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        GwPlayer[i].group = 2;
    }

    arg0->group = 0;
    GwPlayer[var_s4].group = 1;
    GwSystem.unk_58 = var_s4;
    GwSystem.playerIndexVisitingBowser = var_s1_3;

    D_800D1240_D1E40 = (arg1 == 0) ? 8 : 9;
    
    D_80105664_119284_shared_board = 2;
    D_80105666_119286_shared_board = 1;
    D_800D1380_D1F80 = 8;
    return 1;
}