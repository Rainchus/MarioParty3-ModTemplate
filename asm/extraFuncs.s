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

newExtraDiceSpawnHook:
    LI v1, 0x8010570E //restore from hook
    LBU v0, 0x0000 (v1) //restore from hook
    ORI a0, r0, 6 //id of custom block
    BEQ v0, a0, isSluggishBlock
    NOP
    //if not sluggish block, continue as normal
    J 0x800DD02C
    NOP

    isSluggishBlock:
    ORI v0, r0, 1
    J 0x800DD08C
    SB v0, 0x0000 (v1) //set to 1 for normal dice block behavior (bit of a hack but oh well)
    
newDiceDisplayBehavior:
    ADDIU sp, sp, -0x50
    SW v0, 0x0010 (sp)
    SW v1, 0x0014 (sp)
    SW a0, 0x0018 (sp)
    SW a1, 0x001C (sp)
    SW a2, 0x0020 (sp)
    SW a3, 0x0024 (sp)
    SW t0, 0x0028 (sp)
    SW t1, 0x002C (sp)
    SW t2, 0x0030 (sp)
    SW t3, 0x0034 (sp)
    SW t4, 0x0038 (sp)
    SW t5, 0x003C (sp)
    SW t6, 0x0040 (sp)
    SW t7, 0x0044 (sp)
    SW t8, 0x0048 (sp)
    SW ra, 0x004C (sp)
    ADDU a0, v0, r0 //pass current displayed number to func
    JAL SluggishNumberFreezeCheck
    NOP

    //LW v0, 0x0010 (sp)
    LW v1, 0x0014 (sp)
    LW a0, 0x0018 (sp)
    LW a1, 0x001C (sp)
    LW a2, 0x0020 (sp)
    LW a3, 0x0024 (sp)
    LW t0, 0x0028 (sp)
    LW t1, 0x002C (sp)
    LW t2, 0x0030 (sp)
    LW t3, 0x0034 (sp)
    LW t4, 0x0038 (sp)
    LW t5, 0x003C (sp)
    LW t6, 0x0040 (sp)
    LW t7, 0x0044 (sp)
    LW t8, 0x0048 (sp)
    LW ra, 0x004C (sp)
    ADDIU sp, sp, 0x50

    SH v0, 0x0002 (a1) //restore from hook
    J 0x80033218
    LH v1, 0x0000 (t0) //restore from hook


newDiceNumberCheck:
    LB v1, 0x000A (s0)
    ORI v0, r0, 6 //slugghish shroom dice block
    BEQL v0, v1, isSluggish
    ORI v1, r0, 1 //fake sluggish shroom as normal block here
    isSluggish:
    J 0x800DBD80
    SLTIU v0, v1, 6