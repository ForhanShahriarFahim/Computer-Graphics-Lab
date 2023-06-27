#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void bresenham(int x1, int y1, int x2, int y2)
{
    if(x1>y1)
    {
        swap(x1,x2);
        swap(y1,y2);
    }
    int dx = x2 - x1, dy = abs(y2 - y1);
    int p = 2 * dy - dx;
    for(int x = x1, y = y1; x<=x2; x++)
    {
        putpixel(x,y,WHITE);
        if(p>=0)
        {
            y1<y2 ? y++ : y--;
            p+=(2*dy - 2*dx);
        }
        else p+=(2*dy);
    }
}
int main()
{
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");

    int x1,y1,x2,y2;
    cout<<"Enter the start and End line: ";
    cin>>x1>>y1>>x2>>y2;
    bresenham(x1, y1, x2, y2);
    getch();
    return 0;
}

// Input format:  100 100 400 700
