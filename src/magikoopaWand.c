#include "marioparty.h"

#define INFLICT_SHIFT 3
#define INFLICT_MASK  (0x07 << INFLICT_SHIFT) // bits 3-5

void setInfliction(u8 *flags, int inflictor) {
    // inflictor: -1 = none, 0–3 = player index
    u8 val = (inflictor < 0) ? 0 : (inflictor + 1);
    *flags &= ~INFLICT_MASK;
    *flags |= (val << INFLICT_SHIFT);
}

u8 isInflicted(u8 flags) {
    return ((flags >> INFLICT_SHIFT) & 0x07) != 0;
}

int getInflictor(u8 flags) {
    u8 val = (flags >> INFLICT_SHIFT) & 0x07;
    return (val == 0) ? -1 : (val - 1);
}

s32 magikoopaWandCheck(void) {
    s32 inflictedBool = -1;
    s32 inflictedBy = -1;


    inflictedBool = isInflicted(GwPlayer[gCurrentPlayerIndex].stat);
    if (!inflictedBool) {
        return -1;
    }

    return getInflictor(GwPlayer[gCurrentPlayerIndex].stat);
}