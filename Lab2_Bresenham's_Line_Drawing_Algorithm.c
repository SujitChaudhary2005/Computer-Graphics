#include<stdio.h>
#include<graphics.h>
#include<math.h>

void lineBresenham(int x1, int y1, int x2, int y2){
    int x, y, dx, dy, pk, k, xend;

    dx=abs(x2-x1);
    dy=abs(y2-y1);

    if(x1>x2){
        x=x2;
        y=y2;

        xend=x1;
    }
    else{
        x=x1;
        y=y1;

        xend=x2;
    }
    putpixel(x, y, 15);
    pk=2*dy-dx;

    while (x<=xend)
    {
        if(pk==0){
            x=x+1;
            pk=pk+2*dy;
        }

        else{
            x=x+1;
            y=y+1;
            pk=pk+2*dy-2*dx;
        }

        putpixel(x, y, 15);
    } 
}

int main(){
    int gd=DETECT, gm;
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

    lineBresenham(xco1, yco1, xco2, yco2);

    getch();

    return 0;
}