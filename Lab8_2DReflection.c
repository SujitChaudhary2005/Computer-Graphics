#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main()
{
    int rect_x1, rect_y1, rect_x2, rect_y2; // Rectangle coordinates
    int choice;
    int gd = DETECT, gm;

    printf("Enter the coordinates of the first corner (x1 y1): ");
    scanf("%d %d", &rect_x1, &rect_y1);
    printf("Enter the coordinates of the opposite corner (x2 y2): ");
    scanf("%d %d", &rect_x2, &rect_y2);

    printf("Reflect about:\n1. X-axis\n2. Y-axis\nEnter your choice: ");
    scanf("%d", &choice);

    initgraph(&gd, &gm, "");

    rectangle(rect_x1, rect_y1, rect_x2, rect_y2);
    outtextxy(rect_x1, rect_y1 - 20, "Original Rectangle");

    int maxx = getmaxx();
    int maxy = getmaxy();

    if (choice == 1) {
        // Reflection about X-axis (invert y)
        rectangle(rect_x1, maxy - rect_y1, rect_x2, maxy - rect_y2);
        outtextxy(rect_x1, maxy - rect_y1 - 20, "Reflected (X-axis)");
    } else if (choice == 2) {
        // Reflection about Y-axis (invert x)
        rectangle(maxx - rect_x1, rect_y1, maxx - rect_x2, rect_y2);
        outtextxy(maxx - rect_x1, rect_y1 - 20, "Reflected (Y-axis)");
    } else {
        outtextxy(10, maxy - 30, "Invalid choice!");
    }

    getch();
    return 0;
}
