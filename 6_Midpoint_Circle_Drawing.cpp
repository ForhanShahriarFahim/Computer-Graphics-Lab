#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void midpointCircle(int xc, int yc, int radius)
{
    int x = 0, y = radius;
    int p = 1-radius;
    vector<pair<int, int>>points;
    while(x<y)
    {
        points.push_back({x,y});
        points.push_back({y,x});
        x++;
        if(p>=0)
        {
            y--;
            p+=(2*(x-y) + 1);
        }
        else p+=(2*x + 1);
    }
    for(auto p:points)
    {
        putpixel(xc + p.first, yc + p.second, WHITE);
        putpixel(xc - p.first, yc + p.second, WHITE);
        putpixel(xc - p.first, yc - p.second, WHITE);
        putpixel(xc + p.first, yc - p.second, WHITE);
    }
}

int main()
{
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");
    int xc,yc,radius;
    cout<<"Enter the coordinate and radius: ";
    cin>>xc>>yc>>radius;
    midpointCircle(xc,yc,radius);
    getch();
    return 0;
}
// Input: 200 200 80