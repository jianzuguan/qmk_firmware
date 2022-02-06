#pragma once

#include "dactyl_manuform.h"

#define XXX KC_NO

#define LAYOUT( \
    L00, L01, L02, L03, L04, L05,                          R02, R03, R04, R05, R06, R07, \
    L10, L11, L12, L13, L14, L15,                          R12, R13, R14, R15, R16, R17, \
    L20, L21, L22, L23, L24, L25, L26, L27,      R20, R21, R22, R23, R24, R25, R26, R27, \
                   L33, L34, L35, L36, L37,      R30, R31, R32, R33, R34 \
) { \
    { L00, L01, L02, L03, L04, L05, XXX, XXX }, \
    { L10, L11, L12, L13, L14, L15, XXX, XXX }, \
    { L20, L21, L22, L23, L24, L25, L26, L27 }, \
    { XXX, XXX, XXX, L33, L34, L35, L36, L37 }, \
\
    { XXX, XXX, R02, R03, R04, R05, R06, R07 }, \
    { XXX, XXX, R12, R13, R14, R15, R16, R17 }, \
    { R20, R21, R22, R23, R24, R25, R26, R27 }, \
    { R30, R31, R32, R33, R34, XXX, XXX, XXX } \
}
