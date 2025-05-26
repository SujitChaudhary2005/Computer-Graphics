#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int main()
{
    int rect_x1, rect_y1, rect_x2, rect_y2; // Rectangle coordinates
    float angle_deg, angle_rad;

    printf("Enter the coordinates of the first corner (x1 y1): ");
    scanf("%d %d", &rect_x1, &rect_y1);
    printf("Enter the coordinates of the opposite corner (x2 y2): ");
    scanf("%d %d", &rect_x2, &rect_y2);

    printf("Enter the rotation angle (degrees): ");
    scanf("%f", &angle_deg);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw original rectangle
    rectangle(rect_x1, rect_y1, rect_x2, rect_y2);
    outtextxy(rect_x1, rect_y1 - 20, "Original Rectangle");

    // Calculate center of rectangle
    float cx = (rect_x1 + rect_x2) / 2.0;
    float cy = (rect_y1 + rect_y2) / 2.0;

    // Convert angle to radians
    angle_rad = angle_deg * M_PI / 180.0;

    // Rectangle corners
    int x[4] = {rect_x1, rect_x2, rect_x2, rect_x1};
    int y[4] = {rect_y1, rect_y1, rect_y2, rect_y2};
    int xr[4], yr[4];

    // Rotate each corner around the center
    for (int i = 0; i < 4; i++) {
        float dx = x[i] - cx;
        float dy = y[i] - cy;
        xr[i] = (int)(cx + dx * cos(angle_rad) - dy * sin(angle_rad));
        yr[i] = (int)(cy + dx * sin(angle_rad) + dy * cos(angle_rad));
    }

    // Draw rotated rectangle
    for (int i = 0; i < 4; i++) {
        line(xr[i], yr[i], xr[(i+1)%4], yr[(i+1)%4]);
    }
    outtextxy(xr[0], yr[0] - 20, "Rotated Rectangle");

    getch();

    return 0;
}
