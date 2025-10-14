newDiceSpawnGraphicLogic:
    LI t0, 0x8010570E
    LBU t0, 0x0000 (t0)
    ORI t1, r0, 6 //ID of new sluggish shroom block
    BEQL t0, t1, newDiceSpawnGraphicExit
    SB t1, 0x000A (s1) //set block type to 6 if 0x8010570E is 6
    newDiceSpawnGraphicExit:
    JAL 0x80035F98
    ADDIU a0, r0, 0x0011
    J 0x800DC28C
    NOP