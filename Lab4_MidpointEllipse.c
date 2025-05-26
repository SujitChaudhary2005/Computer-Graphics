#include <stdio.h>
#include <graphics.h>
#include <math.h>

// Function to plot all four symmetric points
void plotEllipsePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

int main() {
    int xc, yc, rx, ry;
    int gd = DETECT, gm;
    printf("Enter center of ellipse (xc, yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter x-radius (rx): ");
    scanf("%d", &rx);
    printf("Enter y-radius (ry): ");
    scanf("%d", &ry);

    initgraph(&gd, &gm, "");

    int x = 0;
    int y = ry;

    // Initial decision parameter for region 1
    float rx2 = rx * rx;
    float ry2 = ry * ry;
    float two_rx2 = 2 * rx2;
    float two_ry2 = 2 * ry2;

    float p1 = ry2 - (rx2 * ry) + (0.25 * rx2);
    int dx = two_ry2 * x;
    int dy = two_rx2 * y;

    // Region 1
    while (dx < dy) {
        plotEllipsePoints(xc, yc, x, y);
        if (p1 < 0) {
            x++;
            dx += two_ry2;
            p1 += dx + ry2;
        } else {
            x++;
            y--;
            dx += two_ry2;
            dy -= two_rx2;
            p1 += dx - dy + ry2;
        }
    }

    // Initial decision parameter for region 2
    float p2 = (ry2) * (x + 0.5) * (x + 0.5) + (rx2) * (y - 1) * (y - 1) - (rx2 * ry2);

    // Region 2
    while (y >= 0) {
        plotEllipsePoints(xc, yc, x, y);
        if (p2 > 0) {
            y--;
            dy -= two_rx2;
            p2 += rx2 - dy;
        } else {
            x++;
            y--;
            dx += two_ry2;
            dy -= two_rx2;
            p2 += dx - dy + rx2;
        }
    }

    getch();
    return 0;
}