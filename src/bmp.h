#ifndef __DASM_BMP
#define __DASM_BMP

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Color_t;

Color_t* parseFile(char *filename);

#endif