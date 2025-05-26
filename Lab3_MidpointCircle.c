#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// Function to plot all eight symmetric points of the circle
void drawpoints(int x, int y, int xc, int yc) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

// Function to implement the Midpoint Circle Drawing Algorithm
void drawcircle(int xc, int yc, int r) {
    int p, x, y;
    x = 0;
    y = r;
    drawpoints(x, y, xc, yc); // Draw initial points
    p = 1 - r; // Initial decision parameter

    // Loop until x < y
    while (x < y) {
        x = x + 1;
        if (p < 0) {
            // Midpoint is inside the circle
            p = p + 2 * x + 1;
        } else {
            // Midpoint is outside or on the circle
            y = y - 1;
            p = p + 2 * (x - y) + 1;
        }
        drawpoints(x, y, xc, yc); // Draw symmetric points
    }
}

int main(void) {
    int gdriver = DETECT, gmode, errorcode;
    int xc, yc, r;

    // Initialize graphics mode
    initgraph(&gdriver, &gmode, "");

    // Check for initialization error
    errorcode = graphresult();
    if (errorcode != grOk) {
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getch();
        exit(1);
    }

    // Input center and radius
    printf("Enter the center co-ordinates: ");
    scanf("%d%d", &xc, &yc);
    printf("Enter the radius: ");
    scanf("%d", &r);

    // Draw the circle
    drawcircle(xc, yc, r);

    getch(); // Wait for user input
    return 0;
}