#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int numVertices, numFaces, totalFaces;

    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");

    printf("Enter the number of faces: ");
    scanf("%d", &numFaces);
    totalFaces = numFaces;

    for (int faceIndex = 0; numFaces != faceIndex; numFaces--)
    {
        printf("Enter the total number of vertices in face %d: ", totalFaces - numFaces + 1);
        scanf("%d", &numVertices);
        int vertices[numVertices * 2 + 2], vertexIndex;

        printf("Enter vertices for face %d (x,y): \n", totalFaces - numFaces + 1);
        for (vertexIndex = 0; vertexIndex < (numVertices * 2); vertexIndex++)
        {
            printf("\tx%d , y%d : ", vertexIndex / 2, vertexIndex / 2);
            scanf("%d %d", &vertices[vertexIndex], &vertices[vertexIndex + 1]);
            vertexIndex++;
        }
        vertices[numVertices * 2] = vertices[0];
        vertices[(numVertices * 2) + 1] = vertices[1];

        setcolor(getmaxcolor());
        setfillstyle(SOLID_FILL, totalFaces - numFaces + 1);
        fillpoly(numVertices + 1, vertices);
    }

    getch();

    return 0;
}