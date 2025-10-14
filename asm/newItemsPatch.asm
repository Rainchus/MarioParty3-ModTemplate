.headersize 0x800D6B70 - 0xEA790 //ovl_80_shared_board headersize

.org 0x800E3CB0
    LUI at, hi(newMBItemFunctions + (sizeof_s32 * 1))
    ADDU at, at, v0
    LW v0, lo(newMBItemFunctions + (sizeof_s32 * 1)) (at)

//patch references to D_80105588_1191A8_shared_board (is bss, 1191A8 is a fake rom address)
.org 0x800F4358 //patches func_800F4348_107F68_shared_board
    LI s1, newSpriteIDList

.org 0x800F41C0 //patches func_800F4190_107DB0_shared_board
    LI s3, newSpriteIDList

.org 0x800F3DCC //patches func_800F3D70_107990_shared_board
    LUI a2, hi(newSpriteIDList)
    LH a2, lo(newSpriteIDList) (a2)  //index 0

.org 0x800F3A00 //patches func_800F39C0_1075E0_shared_board
    LUI a2, hi(newSpriteIDList + (sizeof_s16 * 1))  //index 1
    ADDU a2, a2, v0
    LH a2, lo(newSpriteIDList + (sizeof_s16 * 1)) (a2)

.org 0x800F3AC8 //patches func_800F3A80_1076A0_shared_board
    LI s5, (newSpriteIDList + + (sizeof_s16 * 5)) //index 5

.org 0x800F3584 //patches func_800F3400_107020_shared_board
    LUI a2, hi(newSpriteIDList + (sizeof_s16 * 10)) //index 10
    ADDU a2, a2, v0
    LH a2, lo(newSpriteIDList + (sizeof_s16 * 10)) (a2)

.org 0x800F3E7C //patches func_800F3E34_107A54_shared_board
    LUI a2, hi(newSpriteIDList + (sizeof_s16 * 8)) //index 8
    LH a2, lo(newSpriteIDList + (sizeof_s16 * 8))(a2)

.org 0x800F3F4C //patches func_800F3F0C_107B2C_shared_board
    LUI a2, hi(newSpriteIDList + (sizeof_s16 * 9)) //index 9
    LH a2, lo(newSpriteIDList + (sizeof_s16 * 9)) (a2)

.org 0x800F40A8 //patches func_800F3FF4_107C14_shared_board
    LUI a2, hi(newSpriteIDList + (sizeof_s16 * 10))
    ADDU a2, a2, v0
    LH a2, lo(newSpriteIDList + (sizeof_s16 * 10)) (a2)


///////patch references to 
.org 0x800F4190 //patch func_800F4190_107DB0_shared_board
    J newfunc_800F4190_107DB0_shared_board
    NOP

.org 0x800F4348 //patch newfunc_800F4348_107F68_shared_board
    J newfunc_800F4348_107F68_shared_board
    NOP

///////patch references to D_8010197C_11559C_shared_board
//still ovl_80_shared_board headersize
.org 0x800FE68C
    LUI a0, hi(newD_8010197C_11559C_shared_board)
    ADDU a0, a0, v0
    JAL DataRead
    LW a0, lo(newD_8010197C_11559C_shared_board) (a0)

.org 0x800DDFF4
    LUI a0, hi(newD_8010197C_11559C_shared_board)
    ADDU a0, a0, v0
    JAL DataRead
    LW a0, lo(newD_8010197C_11559C_shared_board) (a0)

.org 0x800F792C
    LUI a0, hi(newD_8010197C_11559C_shared_board)
    ADDU a0, a0, v0
    LW a0, lo(newD_8010197C_11559C_shared_board) (a0)

.org 0x800F605C
    LUI a0, hi(newD_8010197C_11559C_shared_board)
    ADDU a0, a0, v0
    J 0x800F607C
    LW a0, lo(newD_8010197C_11559C_shared_board) (a0)

//chilly waters (w01)
.headersize 0x8010C004 - 0x321B74
.org 0x8010C004
    LUI a0, hi(newD_8010197C_11559C_shared_board)
    ADDU a0, a0, v0
    LW a0, lo(newD_8010197C_11559C_shared_board) (a0)

.org 0x8010C3B8
    LUI a0, hi(newD_8010197C_11559C_shared_board)
    ADDU a0, a0, v0
    LW a0, lo(newD_8010197C_11559C_shared_board) (a0)

.org 0x801120B8
    LUI a0, hi(newD_8010197C_11559C_shared_board + (sizeof_s32 * 1)) //index 1
    LW a0, lo(newD_8010197C_11559C_shared_board + (sizeof_s32 * 1)) (a0)

.org 0x80115BD4
    LUI a0, hi(newD_8010197C_11559C_shared_board + (sizeof_s32 * 18)) //index 18
    LW a0, lo(newD_8010197C_11559C_shared_board + (sizeof_s32 * 18)) (a0) //index 18


//w02
.headersize 0x8010BB6C - 0x33B7AC
.org 0x8010BB6C
    LUI a0, hi(newD_8010197C_11559C_shared_board)
    ADDU a0, a0, v0
    LW a0, lo(newD_8010197C_11559C_shared_board) (a0)

.org 0x8010BF20
    LUI a0, hi(newD_8010197C_11559C_shared_board)
    ADDU a0, a0, v0
    LW a0, lo(newD_8010197C_11559C_shared_board) (a0)

.org 0x80111C20
    LUI a0, hi(newD_8010197C_11559C_shared_board + (sizeof_s32 * 1)) //index 1
    LW a0, lo(newD_8010197C_11559C_shared_board + (sizeof_s32 * 1)) (a0)

.org 0x8011573C
    LUI a0, hi(newD_8010197C_11559C_shared_board + (sizeof_s32 * 18)) //index 18
    LW a0, lo(newD_8010197C_11559C_shared_board + (sizeof_s32 * 18)) (a0)


//w03
.headersize 0x8010C0DC - 0x354F4C
.org 0x8010C0DC
    LUI a0, hi(newD_8010197C_11559C_shared_board)
    ADDU a0, a0, v0
    LW a0, lo(newD_8010197C_11559C_shared_board) (a0)

.org 0x8010C490
    LUI a0, hi(newD_8010197C_11559C_shared_board)
    ADDU a0, a0, v0
    LW a0, lo(newD_8010197C_11559C_shared_board) (a0)

.org 0x80115CAC
    LUI a0, hi(newD_8010197C_11559C_shared_board + (sizeof_s32 * 18)) //index 18
    LW a0, lo(newD_8010197C_11559C_shared_board + (sizeof_s32 * 18)) (a0)

.org 0x80112190
    LUI a0, hi(newD_8010197C_11559C_shared_board + (sizeof_s32 * 1)) //index 1
    LW a0, lo(newD_8010197C_11559C_shared_board + (sizeof_s32 * 1)) (a0)


//w04
.headersize 0x8010BBA4 - 0x36DB34
.org 0x8010BBA4
    LUI a0, hi(newD_8010197C_11559C_shared_board)
    ADDU a0, a0, v0
    LW a0, lo(newD_8010197C_11559C_shared_board) (a0)

.org 0x8010BF58
    LUI a0, hi(newD_8010197C_11559C_shared_board)
    ADDU a0, a0, v0
    LW a0, lo(newD_8010197C_11559C_shared_board) (a0)

.org 0x80111C58
    LUI a0, hi(newD_8010197C_11559C_shared_board + (sizeof_s32 * 1)) //index 1
    LW a0, lo(newD_8010197C_11559C_shared_board + (sizeof_s32 * 1)) (a0)

.org 0x80115774
    LUI a0, hi(newD_8010197C_11559C_shared_board + (sizeof_s32 * 18)) //index 18
    LW a0, lo(newD_8010197C_11559C_shared_board + (sizeof_s32 * 18)) (a0)


//w05
.headersize 0x8010B5B0 - 0x385B90
.org 0x8010B5B0
    LUI a0, hi(newD_8010197C_11559C_shared_board)
    ADDU a0, a0, v0
    LW a0, lo(newD_8010197C_11559C_shared_board) (a0)

.org 0x8010B964
    LUI a0, hi(newD_8010197C_11559C_shared_board)
    ADDU a0, a0, v0
    LW a0, lo(newD_8010197C_11559C_shared_board) (a0)

.org 0x80118788
    LUI a0, hi(newD_8010197C_11559C_shared_board)
    ADDU a0, a0, v0
    JAL DataRead
    LW a0, lo(newD_8010197C_11559C_shared_board) (a0)

.org 0x80115180
    LUI a0, hi(newD_8010197C_11559C_shared_board + (sizeof_s32 * 18)) //index 18
    LW a0, lo(newD_8010197C_11559C_shared_board + (sizeof_s32 * 18)) (a0)

.org 0x80111664
    LUI a0, hi(newD_8010197C_11559C_shared_board + (sizeof_s32 * 1)) //index 1
    LW a0, lo(newD_8010197C_11559C_shared_board + (sizeof_s32 * 1)) (a0)


//w06
.headersize 0x8010D394 - 0x3A2714
.org 0x8010D394
    LUI a0, hi(newD_8010197C_11559C_shared_board)
    ADDU a0, a0, v0
    LW a0, lo(newD_8010197C_11559C_shared_board) (a0)

.org 0x8010D748
    LUI a0, hi(newD_8010197C_11559C_shared_board)
    ADDU a0, a0, v0
    LW a0, lo(newD_8010197C_11559C_shared_board) (a0)

.org 0x80116F64
    LUI a0, hi(newD_8010197C_11559C_shared_board + (sizeof_s32 * 18)) //index 18
    LW a0, lo(newD_8010197C_11559C_shared_board + (sizeof_s32 * 18)) (a0)

.org 0x80113448
    LUI a0, hi(newD_8010197C_11559C_shared_board + (sizeof_s32 * 1)) //index 1
    LW a0, lo(newD_8010197C_11559C_shared_board + (sizeof_s32 * 1)) (a0)