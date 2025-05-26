#include <stdio.h>
#include <math.h>
#include <graphics.h>

#define MAX_POINTS 20
#define MAX_ORDER  20

typedef struct Point
{
    int x;
    int y;
} Point;

// calculating bezier coefficients
void coefficients_calculate(int n, int *coefficients)
{
    int k, j;
    for (k = 0; k <= n; k++)
    {
        coefficients[k] = 1;
        for (j = n; j >= k + 1; j--)
        {
            coefficients[k] *= j;
        }
        for (j = n - k; j >= 2; j--)
        {
            coefficients[k] /= j;
        }
    }
}

// calculating bezier points
void bezier_points(float parameter, Point *curve, int control_points_num, Point *control_points, int *coefficients)
{
    int k, n = control_points_num - 1;
    float blending;
    float x = 0.0, y = 0.0;

    for (k = 0; k < control_points_num; k++)
    {
        blending = coefficients[k] * pow(parameter, k) * pow(1 - parameter, n - k);
        x += control_points[k].x * blending;
        y += control_points[k].y * blending;
    }
    putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);
}

// drawing bezier curve
void bezier_curve(int divisions, int control_points_num, Point *control_points, int *coefficients)
{
    int i;
    coefficients_calculate(control_points_num - 1, coefficients);
    for (i = 0; i <= divisions; i++)
    {
        float param = i / (float)divisions;
        Point curve;
        bezier_points(param, &curve, control_points_num, control_points, coefficients);
    }
}

int main()
{
    int gd = DETECT, gm;
    int control_points_num, order;
    int coefficients[MAX_ORDER];
    Point control_points[MAX_POINTS];

    printf("Enter number of control points (max %d): ", MAX_POINTS);
    scanf("%d", &control_points_num);

    if (control_points_num > MAX_POINTS || control_points_num < 2) {
        printf("Invalid number of control points.\n");
        return 1;
    }

    printf("Enter control points (x y):\n");
    for (int i = 0; i < control_points_num; i++)
    {
        scanf("%d %d", &control_points[i].x, &control_points[i].y);
    }

    printf("Enter the order of bezier curve (max %d): ", MAX_ORDER);
    scanf("%d", &order);

    if (order > MAX_ORDER || order < 1) {
        printf("Invalid order.\n");
        return 1;
    }

    initgraph(&gd, &gm, NULL);
    bezier_curve(10000, control_points_num, control_points, coefficients);
    getch();

    return 0;
}