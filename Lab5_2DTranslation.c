#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main()
{
    int rect_x1, rect_y1, rect_x2, rect_y2;// Rectangle coordinates
    int trans_x, trans_y;// Translation values

    printf("Enter the coordinates of the first corner (x1 y1): ");
    scanf("%d %d", &rect_x1, &rect_y1);
    printf("Enter the coordinates of the opposite corner (x2 y2): ");
    scanf("%d %d", &rect_x2, &rect_y2);

    printf("Enter the translation values (tx ty): ");
    scanf("%d %d", &trans_x, &trans_y);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    rectangle(rect_x1, rect_y1, rect_x2, rect_y2);
    outtextxy(rect_x1, rect_y1 - 20, "Original Rectangle");

    rectangle(rect_x1 + trans_x, rect_y1 + trans_y, rect_x2 + trans_x, rect_y2 + trans_y);
    outtextxy(rect_x1 + trans_x, rect_y1 + trans_y - 20, "Translated Rectangle");

    getch();

    return 0;
}
