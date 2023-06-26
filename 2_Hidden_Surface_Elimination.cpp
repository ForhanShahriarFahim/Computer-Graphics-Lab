#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void circle()
{
    setcolor(RED);
    circle(150,150,30);
    setfillstyle(SOLID_FILL, RED);
    floodfill(151,151, RED);
}

void rectangle()
{
    setcolor(GREEN);
    rectangle(80,80,150,150);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(81,81,GREEN);
}

void triangle()
{
    setcolor(BLUE);
    line(100, 100, 200, 100);
    line(100, 100, 150, 150);
    line(200, 100, 150, 150);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(150,130, BLUE);
}
int main()
{
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");

    string sequence;
    printf("Enter the sequence: ");
    cin>>sequence;
    for(char x:sequence)
    {
        if(x == 'C') circle();
        else if(x == 'R') rectangle();
        else triangle();
    }
    getch();
}
