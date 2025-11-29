#include "marioparty.h"
#include "fs_mp2.h"

s32 initMp2MainFS = FALSE;

// u8 ciImage[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x22, 0x21, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x22, 0x22, 0x33, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x22, 0x22, 0x33, 0x21, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x33, 0x33, 0x33, 0x24, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x13, 0x33, 0x33, 0x24, 0x41, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x12, 0x22, 0x22, 0x24, 0x41, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x44, 0x44, 0x22, 0x41, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x14, 0x44, 0x42, 0x21, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x14, 0x42, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// u16 palette[] = {0x1886, 0x20C9, 0x8BEB, 0x6AE3, 0xC5F7, 0x2883, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};

// Gfx* gfx_draw_textured_rectangle_rgba32(Gfx* gfx, int x, int y, int width, int height, u8* texture) {
//     gDPPipeSync(gfx++);
    
//     gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
//     gDPSetTextureFilter(gfx++, G_TF_POINT);
//     gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
//     gDPSetRenderMode(gfx++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
    
//     gDPSetTextureImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, texture);
//     gDPSetTile(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_32b, (width + 1) / 2, 0, G_TX_LOADTILE, 0, G_TX_NOMIRROR, 0, 0, G_TX_NOMIRROR, 0, 0);
//     gDPLoadSync(gfx++);
//     gDPLoadTile(gfx++, G_TX_LOADTILE, 0, 0, (width - 1) << 2, (height - 1) << 2);
//     gDPPipeSync(gfx++);
//     gDPSetTile(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_32b, (width + 1) / 2, 0, G_TX_RENDERTILE, 0, G_TX_NOMIRROR, 0, 0, G_TX_NOMIRROR, 0, 0);
//     gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, 0, (width - 1) << 2, (height - 1) << 2);

//     gSPTextureRectangle(gfx++, x << 2, y << 2, (x + width) << 2, (y + height) << 2,
//                         G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

//     gDPPipeSync(gfx++);
//     gSPTexture(gfx++, 0, 0, 0, 0, G_OFF);
    
//     return gfx;
// }

// Gfx* gfx_draw_textured_rectangle_rgba16(Gfx* gfx, int x, int y, int width, int height, u8* texture) {
//     gDPPipeSync(gfx++);
    
//     gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
//     gDPSetTextureFilter(gfx++, G_TF_POINT);
//     gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
//     gDPSetRenderMode(gfx++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
//     gDPSetTextureImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, texture);
//     gDPSetTile(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, (width + 3) / 4, 0, G_TX_LOADTILE, 0, G_TX_NOMIRROR, 0, 0, G_TX_NOMIRROR, 0, 0);
//     gDPLoadSync(gfx++);
//     gDPLoadTile(gfx++, G_TX_LOADTILE, 0, 0, (width - 1) << 2, (height - 1) << 2);
//     gDPPipeSync(gfx++);
//     gDPSetTile(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, (width + 3) / 4, 0, G_TX_RENDERTILE, 0, G_TX_NOMIRROR, 0, 0, G_TX_NOMIRROR, 0, 0);
//     gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, 0, (width - 1) << 2, (height - 1) << 2);

//     gSPTextureRectangle(gfx++, x << 2, y << 2, (x + width) << 2, (y + height) << 2,
//                         G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

//     gDPPipeSync(gfx++);
//     gSPTexture(gfx++, 0, 0, 0, 0, G_OFF);
    
//     return gfx;
// }

// Gfx* drawCi8Image(Gfx* gfx, int x, int y, int width, int height, u8* texture, u16* palette) {
//     gDPSetTextureLUT(gfx++, G_TT_RGBA16);
//     gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
//     gDPPipeSync(gfx++);
//     gDPSetTextureFilter(gfx++, G_TF_POINT);  // Disable bilinear filtering
//     gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
//     gDPSetRenderMode(gfx++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
//     gDPTileSync(gfx++);
//     gDPSetTile(gfx++, G_IM_FMT_CI, G_IM_SIZ_8b, (width + 7) / 8, 0, 0, 0, G_TX_NOMIRROR, 5, 0, G_TX_NOMIRROR, 5, 0);
//     gDPSetTileSize(gfx++, 0, 0, 0, (width - 1) << 2, (height - 1) << 2);
//     gSPClearGeometryMode(gfx++, G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH);
//     gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH);
//     gDPLoadTLUT_pal256(gfx++, palette);
//     gDPLoadTextureBlock(gfx++, texture, G_IM_FMT_CI, G_IM_SIZ_8b, width, height, 0, G_TX_NOMIRROR, G_TX_NOMIRROR, 5, 5, 0, 0);
//     gSPTextureRectangle(gfx++, x << 2, y << 2, (x + width) << 2, (y + height) << 2,
//                         G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

//     gDPPipeSync(gfx++);
//     return gfx;
// }

// Gfx* drawCi4Image(Gfx* gfx, int x, int y, int width, int height, u8* texture, u16* palette) {
//     gDPSetTextureLUT(gfx++, G_TT_RGBA16);
//     gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
//     gDPPipeSync(gfx++);
//     gDPSetTextureFilter(gfx++, G_TF_POINT);  // Disable bilinear filtering
//     gDPSetCombineMode(gfx++, G_CC_DECALRGBA , G_CC_DECALRGBA );
//     gDPSetRenderMode(gfx++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
//     gDPTileSync(gfx++);
//     gDPSetTile(gfx++, G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0, 0, 0, G_TX_NOMIRROR, 5, 0, G_TX_NOMIRROR, 5, 0);
//     gDPSetTileSize(gfx++, 0, 0, 0, (width - 1) << 2, (height - 1) << 2);
//     gSPClearGeometryMode(gfx++, G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH);
//     gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH);
//     gDPLoadTLUT_pal16(gfx++, 0, palette);
//     gDPLoadTextureBlock_4b(gfx++, texture, G_IM_FMT_CI,width,height,0,G_TX_NOMIRROR,G_TX_NOMIRROR,5,5,0,0);
//     gSPTextureRectangle(gfx++, x << 2, y << 2, (x + width) << 2, (y + height) << 2,
//                         G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

//     gDPPipeSync(gfx++);
//     return gfx;
// };

#define MAKE_ID(dir,file) (((dir)<<16) | (file))

void func_8000BBD4_C7D4(s32, s32, s32);
u16 func_8000B838_C438(s32);
s16 InitEspriteSlot(s16, s32, s32);
void ScaleESprite(s32, f32, f32);
s16 func_80055810_56410(void*);
void InitMp2FS(void);
Gfx* WipeExecAlways(Gfx**);

extern FSContext mp2fs;

s16 newfunc_8000B838_C438(s32 arg0) {
    void* temp_v0;
    s16 temp_s0;

    temp_v0 = FS_Read(&mp2fs, arg0);
    temp_s0 = func_80055810_56410(temp_v0);
    HuMemMemoryFreePerm(temp_v0);
    return temp_s0;
}

s32 DrawImageWrapper(s32 mainFileSystemID, s32 xPos, s32 yPos) {
    s32 curGraphicID;
    s32 curESpriteID;

    curGraphicID = newfunc_8000B838_C438(mainFileSystemID);
    curESpriteID = InitEspriteSlot(curGraphicID, 0, 1);
    func_8000BBD4_C7D4(curESpriteID, xPos, yPos); //set sprite position
    return curESpriteID;
}

void DrawMp2Image(void){
    s32 invalidEepBoxSpriteId = DrawImageWrapper(MAKE_ID(0, 0x67), 0, 0);
    ScaleESprite(invalidEepBoxSpriteId, 1.0f, 1.0f);
    s32 xPos = 36;
    s32 yPos = 35;
    func_8000BBD4_C7D4(invalidEepBoxSpriteId, xPos, yPos); //set sprite position
}

s32 prevWasYoshi = 0;

typedef struct CharModelMap {
	s32 mp2_FS_ID[2];
	s32 mp3_FS_ID[2];
} CharModelMap;

enum CHARCTERS {
    CHAR_MARIO = 0,
    CHAR_LUIGI = 1,
    CHAR_PEACH = 2,
    CHAR_YOSHI = 3,
    CHAR_WARIO = 4,
    CHAR_DK = 5,
    CHAR_MAX
};

CharModelMap modelMaps[] = {
    { //CHAR_MARIO,
	{0x000200D7, 0x6A9}, //mp2 args passed to func_80018A98
	{0x000200A0, 0x6A9}, //mp3 args passed to func_8000B108
    },

    { //CHAR_LUIGI,
	{0x000300D7, 0x6A9}, //mp2 args passed to func_80018A98
	{0x000300A0, 0x6A9}, //mp3 args passed to func_8000B108
    },

    { //CHAR_YOSHI,
	{0x000400D7, 0x6A9}, //mp2 args passed to func_80018A98
	{0x000400A0, 0x6A9}, //mp3 args passed to func_8000B108
    },

    { //CHAR_WARIO,
	{0x000500D7, 0x6A9}, //mp2 args passed to func_80018A98
	{0x000500A0, 0x6A9}, //mp3 args passed to func_8000B108
    },

    { //CHAR_DK,
	{0x000600D7, 0x6A9}, //mp2 args passed to func_80018A98
	{0x000600A0, 0x6A9}, //mp3 args passed to func_8000B108
    },

    { //CHAR_PEACH,
	{0x000700D7, 0x6A9}, //mp2 args passed to func_80018A98
	{0x000700A0, 0x6A9}, //mp3 args passed to func_8000B108
    },


    {//Mario in game setup (NOTE: mario uses 0x000200A1, not the expected 0x000200A2)
    {0x000200D7, 0x6A9}, //mp2 data
    {0x000200A1, 0x2A9}, //mp3 data
    },

    {//Luigi in game setup
    {0x000300D6, 0x6A9}, //mp2 data
    {0x000300A2, 0x2A9}, //mp3 data
    },

    {//Yoshi in game setup
    {0x000400D6, 0x6A9}, //mp2 data
    {0x000400A2, 0x2A9}, //mp3 data
    },

    {//Wario in game setup (NOTE: wario uses 0x000500A1, not the expected 0x000500A2)
    {0x000500D7, 0x6A9}, //mp2 data
    {0x000500A1, 0x2A9}, //mp3 data
    },

    {//DK in game setup (NOTE: wario uses 0x000600A1, not the expected 0x000600A2)
    {0x000600D7, 0x6A9}, //mp2 data
    {0x000600A1, 0x2A9}, //mp3 data
    },

    {//Peach in game setup
    {0x000700D6, 0x6A9}, //mp2 data
    {0x000700A2, 0x2A9}, //mp3 data
    },
};

CharModelMap* FindPlayerModelMap(s32 characterID) { 
	s32 i;
	for (i = 0; i < ARRAY_COUNT(modelMaps); i++) {
		if (characterID == i) {
			return &modelMaps[i];
		}
	}
	return NULL;
}

s32 wasPrevCharMp2 = 0;
s32 mp2SkeletonData[2] = {0xD, 0x229};
s32 mp3SkeletonData[2] = {0x9, 0x229};
s32 mp3GameSetupSkeletonData[2] = {9, 0x299};



typedef struct omOvlHisData {
   s32 overlayID;
   s16 event;
   s16 stat;
} omOvlHisData;

omOvlHisData gameSetup[] = {
	{0x0000007A, 2, 0x0092},
	{0x0000007A, 2, 0x0092},
	{0x00000077, 1, 0x0091},	
};

extern s16 omovlhisidx;
s32 omOvlCallEx(s32 ovlID, s16 event, u16 stat);
void omOvlHisChg(s16 level, s32 overlay, s16 event, s16 stat);

void newOvlOnLoad(s32 ovlID, s16 event, u16 stat) {
    // omovlhisidx = 2;
    // omOvlCallEx(0x78, 0, 0x91);
    // omOvlHisChg(0x1, 0x77, 0, 0x91);
    omOvlCallEx(ovlID, event, stat);
}

u16 newfunc_8000B108_BD08(s32 arg0, s32 arg1) {
    s32 i;

    if (wasPrevCharMp2 == 1) {
        wasPrevCharMp2 = 0;
        if (arg0 == mp3SkeletonData[0] && arg1 == mp3SkeletonData[1]) {
            return Hu3DModelCreate(FS_Read(&mp2fs, mp2SkeletonData[0]), mp2SkeletonData[1]);
        }

        // if (arg0 == mp3GameSetupSkeletonData[0] && arg1 == mp3GameSetupSkeletonData[1]) {
        //     return Hu3DModelCreate(FS_Read(&mp2fs, mp2SkeletonData[0]), mp2SkeletonData[1]); //is this going to work?
        // }
    }

    for (i = 0; i < ARRAY_COUNT(modelMaps); i++) {
        if (arg0 == modelMaps[i].mp3_FS_ID[0] && arg1 == modelMaps[i].mp3_FS_ID[1]) {
            wasPrevCharMp2 = 1;
            return Hu3DModelCreate(FS_Read(&mp2fs, modelMaps[i].mp2_FS_ID[0]), modelMaps[i].mp2_FS_ID[1]);
        }
    }


    return Hu3DModelCreate(DataRead(arg0), arg1);

    // if (arg0 == 0x000400A0 && arg1 == 0x6A9) {
    //     //hardcoded yoshi check
    //     prevWasYoshi = 1;
    //     return Hu3DModelCreate(FS_Read(&mp2fs, 0x000400D7), arg1);
    // } else {
    //     if (prevWasYoshi != 1) {
    //         return Hu3DModelCreate(DataRead(arg0), arg1);
    //     }
    //     //previously loaded yoshi, poke next load to correct file
    //     if (arg0 == 9 && arg1 == 0x229) {
    //         prevWasYoshi = 0;
    //         return Hu3DModelCreate(FS_Read(&mp2fs, 0xD), 0x229);
    //     }
    // }
    // return Hu3DModelCreate(DataRead(arg0), arg1);
}

Gfx* drawFonts3(void) {
    if (initMp2MainFS == 0) {
        InitMp2FS();
    }

    initMp2MainFS++;

    if (initMp2MainFS == 300) {
        DrawMp2Image();
    }

    if (initMp2MainFS > 301) {
        initMp2MainFS = 301;
    }

    //mp3_gMainGfxPos = drawCi4Image(mp3_gMainGfxPos, 20, 20, 32, 32, ciImage, palette);
    //mp3_gMainGfxPos = gfx_draw_textured_rectangle_rgba16(mp3_gMainGfxPos, 20, 20, 42, 42, moon);

    return WipeExecAlways(&mp3_gMainGfxPos); //restore from hook
}