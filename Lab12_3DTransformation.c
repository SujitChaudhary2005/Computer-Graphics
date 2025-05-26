#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>

#define PI 3.14159

typedef struct {
    float x, y, z;
} Point3D;

// Original cube coordinates (from -1 to 1)
Point3D cube[8] = {
    {-1, -1, -1},
    { 1, -1, -1},
    { 1,  1, -1},
    {-1,  1, -1},
    {-1, -1,  1},
    { 1, -1,  1},
    { 1,  1,  1},
    {-1,  1,  1}
};

int edges[12][2] = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0},
    {4, 5}, {5, 6}, {6, 7}, {7, 4},
    {0, 4}, {1, 5}, {2, 6}, {3, 7}
};

// Project 3D point to 2D (orthographic)
void project(Point3D p, int *x, int *y) {
    int scale = 100;
    *x = getmaxx()/2 + (int)(p.x * scale);
    *y = getmaxy()/2 - (int)(p.y * scale);
}

// Draw cube edges
void drawCube(Point3D cube[]) {
    cleardevice();
    int x1, y1, x2, y2;

    for (int i = 0; i < 12; i++) {
        project(cube[edges[i][0]], &x1, &y1);
        project(cube[edges[i][1]], &x2, &y2);
        line(x1, y1, x2, y2);
    }
}

// Apply translation
void translate(Point3D cube[], float tx, float ty, float tz) {
    for (int i = 0; i < 8; i++) {
        cube[i].x += tx;
        cube[i].y += ty;
        cube[i].z += tz;
    }
}

// Apply scaling
void scale(Point3D cube[], float sx, float sy, float sz) {
    for (int i = 0; i < 8; i++) {
        cube[i].x *= sx;
        cube[i].y *= sy;
        cube[i].z *= sz;
    }
}

// Rotate around X-axis
void rotateX(Point3D cube[], float angle) {
    float rad = angle * PI / 180;
    for (int i = 0; i < 8; i++) {
        float y = cube[i].y;
        float z = cube[i].z;
        cube[i].y = y * cos(rad) - z * sin(rad);
        cube[i].z = y * sin(rad) + z * cos(rad);
    }
}

// Rotate around Y-axis
void rotateY(Point3D cube[], float angle) {
    float rad = angle * PI / 180;
    for (int i = 0; i < 8; i++) {
        float x = cube[i].x;
        float z = cube[i].z;
        cube[i].x = x * cos(rad) + z * sin(rad);
        cube[i].z = -x * sin(rad) + z * cos(rad);
    }
}

// Rotate around Z-axis
void rotateZ(Point3D cube[], float angle) {
    float rad = angle * PI / 180;
    for (int i = 0; i < 8; i++) {
        float x = cube[i].x;
        float y = cube[i].y;
        cube[i].x = x * cos(rad) - y * sin(rad);
        cube[i].y = x * sin(rad) + y * cos(rad);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Copy of original cube to transform
    Point3D transformedCube[8];
    for (int i = 0; i < 8; i++)
        transformedCube[i] = cube[i];

    // Step 1: Scale cube smaller (initially)
    scale(transformedCube, 0.5, 0.5, 0.5);
    drawCube(transformedCube);
    outtextxy(10, 10, "Original Small Cube");
    getch();

    // Step 2: Translate
    translate(transformedCube, 1.0, 1.0, 0.0);
    drawCube(transformedCube);
    outtextxy(10, 10, "Translated Cube");
    getch();

    // Step 3: Rotate around X and Y
    rotateX(transformedCube, 30);
    rotateY(transformedCube, 30);
    drawCube(transformedCube);
    outtextxy(10, 10, "Rotated Cube");
    getch();

    // Step 4: Scale again
    scale(transformedCube, 1.5, 1.5, 1.5);
    drawCube(transformedCube);
    outtextxy(10, 10, "Scaled Cube");
    getch();

    return 0;
}