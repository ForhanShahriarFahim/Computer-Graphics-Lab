#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
int main()
{
    int gd = DETECT, gm = DETECT;
    char data[] = "C:\\mingw32\\lib\\libbgi.a"; // static file
    initgraph(&gd, &gm, data);

    // green rectangle
    setcolor(GREEN);
    rectangle(50, 50, 300, 200);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(60, 60, GREEN);

    // red circle
    setcolor(RED);
    circle(175, 125, 50);
    setfillstyle(SOLID_FILL, RED);
    floodfill(130, 130, RED);

    // white stand
    setcolor(WHITE);
    rectangle(40, 40, 50, 430);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(45, 45, WHITE);
    getchar();
}
