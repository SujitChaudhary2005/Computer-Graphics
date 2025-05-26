#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#define WIDTH 640
#define HEIGHT 480

float zBuffer[WIDTH][HEIGHT];

// Function to initialize Z-buffer
void clearZBuffer() {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            zBuffer[x][y] = 1e9; // Initialize with farthest depth
        }
    }
}

// Function to plot pixel with Z-buffer test
void putPixelZ(int x, int y, float z, int color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        if (z < zBuffer[x][y]) {
            putpixel(x, y, color);
            zBuffer[x][y] = z;
        }
    }
}

// Draw a filled rectangle with depth (Z)
void drawRectangle3D(int x1, int y1, int x2, int y2, float z, int color) {
    for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++) {
            putPixelZ(x, y, z, color);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    clearZBuffer();

    // Draw far rectangle first (green, z = 50)
    drawRectangle3D(150, 100, 300, 250, 50.0f, GREEN);

    // Draw near rectangle overlapping (red, z = 30)
    drawRectangle3D(200, 150, 350, 300, 30.0f, RED);

    getch();

    return 0;
}
