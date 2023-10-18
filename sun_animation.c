#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 25

#define PI 3.14159265

void clear_screen() {
    printf("\033[H\033[J");
}

void draw_sun(double theta) {
    int x, y;

    clear_screen();

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            double distance = sqrt(pow(x - WIDTH / 2, 2) + pow(y - HEIGHT / 2, 2));
            if (distance < 10) {
                putchar('*');
            } else {
                double angle = atan2(y - HEIGHT / 2, x - WIDTH / 2);
                angle = fmod(theta + 2 * PI + angle, 2 * PI);
                if (angle < PI / 3 || angle > 5 * PI / 3) {
                    putchar('/');
                } else if (angle < 2 * PI / 3) {
                    putchar('\\');
                } else if (angle < PI) {
                    putchar('|');
                } else if (angle < 4 * PI / 3) {
                    putchar('/');
                } else {
                    putchar('|');
                }
            }
        }
        putchar('\n');
    }
}

int main() {
    double theta = 0;
    while (1) {
        draw_sun(theta);
        theta += 0.05;
        usleep(100000);
    }

    return 0;
}
