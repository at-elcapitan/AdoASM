#include "bmp.h"

Color_t* parseFile(char *filename)
{
    int i;
    int j;
    int k;
    FILE *pfile;
    Color_t *colors;
    size_t bytesRead;
    char type[3] = {0};
    uint8_t buf[3] = {0};
    uint32_t size = 0;
    uint32_t cols = 0;
    uint32_t rows = 0;
    uint32_t offset = 0;

    pfile = fopen(filename, "r");
    if (pfile == NULL) {
        return NULL;
    }

    bytesRead = fread(type, 1, 2, pfile);

    if (bytesRead != 2) {
        return NULL;
    }

    if (strcmp(type, "BM") != 0) {
        return NULL;
    }

    bytesRead = fread(&size, sizeof(uint32_t), 1, pfile);

    if (bytesRead != 1) {
        return NULL;
    }

    fseek(pfile, 4, SEEK_CUR);
    bytesRead = fread(&offset, sizeof(uint32_t), 1, pfile);

    if (bytesRead != 1) {
        return NULL;
    }

    fseek(pfile, 4, SEEK_CUR);

    fread(&cols, 4, 1, pfile);

    if (bytesRead != 1) {
        return NULL;
    }

    fread(&rows, 4, 1, pfile);

    if (bytesRead != 1) {
        return NULL;
    }

    fseek(pfile, offset - 26, SEEK_CUR);

    colors = malloc(3 * ((size - offset) / 3));

    if (colors == NULL) {
        return NULL;
    }

    i = 0;
    j = 0;
    k = 0;
    while ((bytesRead = fread(&buf, 1, 3, pfile)) == 3) {
        if (i == cols) {
            i = 0;
            j++;
        }

        if (j == rows) {
            break;
        }

        if (k >= (size - offset) / 3) {
            break;
        }
        
        Color_t color = {
            .b = buf[0],
            .g = buf[1],
            .r = buf[2]
        };

        colors[k] = color;
        k++;
    }

    fclose(pfile);
    return colors;
}
