#include "main.h"

int main()
{
    Color_t *colors;
    int i;

    colors = parseFile("main.dasm");

    if (colors == NULL) {
        perror("Failed to parse file");
        free(colors);
        return EXIT_FAILURE;
    }

    i = 0;
    for (; i < 2; i++) {
        Color_t color = colors[i];
        switch (color.r)
        {
        case 0x1:
            printf("Hello, world!\n");
            break;
        
        case 0xFF:
            return EXIT_SUCCESS;

        default:
            perror("Operand not recognized");
            return EXIT_FAILURE;
        }
    }

    free(colors);
    return EXIT_SUCCESS;
}
