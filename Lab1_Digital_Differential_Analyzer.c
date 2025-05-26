#include <graphics.h>
#include <math.h>
#include <stdio.h>

void lineDDA(int x1, int y1, int x2, int y2)
{
    int dx, dy, steps, k;
    float incrx, incry, x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }

    incrx = (float)dx / steps;
    incry = (float)dy / steps;

    x = x1;
    y = y1;

    putpixel(round(x), round(y), WHITE);

    for (k = 1; k <= steps; k++)
    {
        x = x + incrx;
        y = y + incry;
        putpixel(round(x), round(y), WHITE);
    }
}

int main()
{
    int gd = DETECT, gm;
    int xco1, yco1, xco2, yco2;

    printf("Enter the coordinate x1: ");
    scanf("%d", &xco1);
    printf("Enter the coordinate y1: ");
    scanf("%d", &yco1);

    printf("Enter the coordinate x2: ");
    scanf("%d", &xco2);
    printf("Enter the coordinate y2: ");
    scanf("%d", &yco2);

    initgraph(&gd, &gm, "");

    lineDDA(xco1, yco1, xco2, yco2);
    getch();
    return 0;
}