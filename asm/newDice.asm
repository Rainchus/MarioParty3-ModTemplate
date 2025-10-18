.headersize 0x800D6B70 - 0xEA790 //ovl_80_shared_board headersize
.org 0x800DC304
    LUI a0, hi(newDiceMainFS)
    ADDU a0, a0, v0
    LW a0, lo(newDiceMainFS) (a0)

.org 0x800DC2A0
    LUI a0, hi(newDiceMainFS2)
    ADDU a0, a0, v0
    JAL DataRead
    LW a0, lo(newDiceMainFS2) (a0)

.org 0x800DC284
    J newDiceSpawnGraphicLogic
    NOP

.org 0x800DCDD4
    J newfunc_800DCDD4_F09F4_shared_board
    NOP

.org 0x800DBD78
    J newDiceNumberCheck
    NOP