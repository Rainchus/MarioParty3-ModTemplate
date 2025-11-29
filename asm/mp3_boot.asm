.definelabel ROM_START, 0x1F80000

.headersize 0x7FFFF400 //ran once on boot
.org 0x80000400
    //set up stack pointer
    LUI sp, 0x800D
    ADDIU sp, sp, 0x300
    
    LI a1, ROM_START
    //these ram symbols are defined in main.asm
    LI a2, PAYLOAD_START_RAM
    LI a3, PAYLOAD_END_RAM - PAYLOAD_START_RAM
    JAL osPiRawStartDma
     ADDU a0, r0, r0
    LI t0, 0xA4600010
    pi_loop:
    LW t1, 0x0000 (t0)
    ANDI t2, t1, 0x0001
    BNEZ t2, pi_loop
     LUI t3, 0x800B
    alreadyDMAed:
    ADDIU t3, t3, 0x8AF0
    LUI t1, 0x0003
    ADDIU t1, t1, 0xE080
    mp3_bss_clear_loop:
    SD r0, 0x0000 (t3)
    ADDI t1, t1, 0xFFF8
    BNEZ t1, mp3_bss_clear_loop
     ADDI t3, t3, 0x0008

.org 0x80033210
    J newDiceDisplayBehavior
    NOP

.org 0x8001BC74
    JAL drawFonts3
    SW s0, 0x0004 (v0)

//.org 0x8007D900
    //J displayFrameBufferWrites
    //NOP


//.org 0x80035594
    //JAL dmaAndSramInit
    //NOP

//remove 16KBit eeprom assert
.org 0x8000C2A8
    NOP

//.org 0x8000C4DC //_WriteEeprom
    //JR RA
    //ORI v0, r0, 2

//.org 0x8000C7A0 //_ReadEeprom
    //JR RA
    //ORI v0, r0, 2


//.org 0x8000CB30 //WriteEeprom
    //JR RA
    //ORI v0, r0, 0

.org 0x8000B108
    J newfunc_8000B108_BD08
    NOP

.org 0x8000E658
    JAL newOvlOnLoad
    NOP