#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT( \
    L00, L01, L02, L03, L04, L05, L06,                R01, R02, R03, R04, R05, R06, R07, \
    L10, L11, L12, L13, L14, L15, L16,                R11, R12, R13, R14, R15, R16, R17, \
    L20, L21, L22, L23, L24, L25, L26,                R21, R22, R23, R24, R25, R26, R27, \
    L30, L31, L32, L33, L34, L35, L36, L37,      R30, R31, R32, R33, R34, R35, R36, R37, \
                   L43, L44, L45, L46, L47,      R40, R41, R42, R43, R44 \
) { \
    { L00, L01, L02, L03, L04, L05, L06, XXX }, \
    { L10, L11, L12, L13, L14, L15, L16, XXX }, \
    { L20, L21, L22, L23, L24, L25, L26, XXX }, \
    { L30, L31, L32, L33, L34, L35, L36, L37 }, \
    { XXX, XXX, XXX, L43, L44, L45, L46, L47 }, \
\
    { XXX, R01, R02, R03, R04, R05, R06, R07 }, \
    { XXX, R11, R12, R13, R14, R15, R16, R17 }, \
    { XXX, R21, R22, R23, R24, R25, R26, R27 }, \
    { R30, R31, R32, R33, R34, R35, R36, R37 }, \
    { R40, R41, R42, R43, R44, XXX, XXX, XXX } \
}
