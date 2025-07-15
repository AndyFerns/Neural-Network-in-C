#include <stdio.h>

// Displays loss via an ascii graph
void plotLoss(double *losses, int len, int width, int height) {
    double max = 0.0;
    for (int i = 0; i < len; i++)
        if (losses[i] > max) max = losses[i];

    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            int idx = x * len / width;
            int bar_height = (int)((losses[idx] / max) * height);
            if (bar_height > y)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }

    // X-axis
    for (int i = 0; i < width; i++) printf("-");
    printf("\n");
}
