#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main()
{
    int rect_x1, rect_y1, rect_x2, rect_y2; // Rectangle coordinates
    int scale_x, scale_y; // Scaling factors

    printf("Enter the coordinates of the first corner (x1 y1): ");
    scanf("%d %d", &rect_x1, &rect_y1);
    printf("Enter the coordinates of the opposite corner (x2 y2): ");
    scanf("%d %d", &rect_x2, &rect_y2);

    printf("Enter the scaling factors (sx sy): ");
    scanf("%d %d", &scale_x, &scale_y);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    rectangle(rect_x1, rect_y1, rect_x2, rect_y2);
    outtextxy(rect_x1, rect_y1 - 20, "Original Rectangle");

    rectangle(rect_x1 * scale_x, rect_y1 * scale_y, rect_x2 * scale_x, rect_y2 * scale_y);
    outtextxy(rect_x1 * scale_x, rect_y1 * scale_y - 20, "Scaled Rectangle");

    getch();

    return 0;
}