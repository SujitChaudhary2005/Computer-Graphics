#include <stdio.h>
#include <graphics.h>
#include <dos.h> // For delay()

void draw_rect_with_label(int x[4], int y[4], const char *label, int label_y_offset);

int main()
{
    int rect_x[4], rect_y[4]; // Rectangle corner coordinates
    int shear_factor;
    int choice;
    int sheared_x[4], sheared_y[4];
    int i;

    printf("Enter the coordinates of the rectangle corners (x y):\n");
    for (i = 0; i < 4; i++)
    {
        printf("Corner %d: ", i + 1);
        scanf("%d %d", &rect_x[i], &rect_y[i]);
    }

    printf("Shear along which axis?\n");
    printf("1 for X-axis\n");
    printf("2 for Y-axis\n");
    printf("3 for both X and Y axes\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the shearing factor: ");
    scanf("%d", &shear_factor);

    // Copy original rectangle to sheared arrays
    for (i = 0; i < 4; i++) {
        sheared_x[i] = rect_x[i];
        sheared_y[i] = rect_y[i];
    }

    // Apply shearing
    if (choice == 1) {
        for (i = 0; i < 4; i++)
            sheared_x[i] = rect_x[i] + shear_factor * rect_y[i];
    } else if (choice == 2) {
        for (i = 0; i < 4; i++)
            sheared_y[i] = rect_y[i] + shear_factor * rect_x[i];
    } else if (choice == 3) {
        for (i = 0; i < 4; i++) {
            sheared_x[i] = rect_x[i] + shear_factor * rect_y[i];
            sheared_y[i] = rect_y[i] + shear_factor * rect_x[i];
        }
    }

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setbkcolor(BLACK);

    // Draw original rectangle
    draw_rect_with_label(rect_x, rect_y, "Original Rectangle", -20);

    // Draw sheared rectangle
    draw_rect_with_label(sheared_x, sheared_y, "Sheared Rectangle", 10);

    getch();

    return 0;
}

void draw_rect_with_label(int x[4], int y[4], const char *label, int label_y_offset)
{
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[3], y[3]);
    line(x[3], y[3], x[0], y[0]);
    // Place label near the first corner
    outtextxy(x[0], y[0] + label_y_offset, (char*)label);
}
