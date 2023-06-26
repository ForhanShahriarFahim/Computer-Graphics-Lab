#include<bits/stdc++.h>
#include<graphics.h>

#define Sin(x) sin(x * acos(-1.0) / 180)
#define Cos(x) cos(x * acos(-1.0) / 180)
int point, x[10], y[10];//......Coordinates of each vertex
int tx, ty; //...........Translation factors
int sfx, sfy; //.........Scaling factors
int angle;//........anti-clockwise Rotation angle
int xPivot, yPivot;//......Pivot point coordinates
using namespace std;

void draw()
{
    for(int i = 0;i<point;i++)
    {
        line(x[i], y[i], x[(i+1)%point], y[(i+1)%point]);
    }
}

void translate()
{
    for(int i = 0;i<point;i++)
    {
        x[i] += tx;
        y[i] += ty;
    }
}

void scale()
{
    for(int i = 0;i<point;i++)
    {
        x[i] *=sfx;
        y[i] *= sfy;
    }
}


void rotation()
{
    for(int i = 0;i<point; i++)
    {
        int xShift = x[i] -xPivot, yShift = y[i] - yPivot;
        x[i] = xPivot + (xShift * Cos(angle) - yShift * Sin(angle));
        y[i] = yPivot + (xShift * Sin(angle) + yShift * Cos(angle));
    }
}

int main()
{
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");

    cin>>point; //.......total vertex of the polygon
    for(int i = 0;i<point; i++)
    {
        cin>>x[i]>>y[i];
    }
    setcolor(YELLOW);
    draw();

    char ch;
    printf("Which transformation? T-> Translation, S-> Scaling, R-> Rotation: ");
    cin>>ch;
    if(ch == 'T')
    {
        cin>>tx>>ty;
        translate();
        setcolor(WHITE);
        draw();
        /*..............Input:
3
100 100
100 200
200 100
T
100 100

*/
    }
    else if(ch == 'S')
    {
        cin>>sfx>>sfy;
        scale();
        setcolor(WHITE);
        draw();
  /*..............Input:
3
100 100
100 200
200 100
S
2 2

*/
    }
    else
    {
        cout<<"Enter rotation angle: ";
        cin>>angle;
        cout<<"Enter pivot points: ";
        cin>>xPivot>>yPivot;
        rotation();
        setcolor(WHITE);
        draw();
/*        ...............Input:
4
100 100
100 200
200 200
200 100
R
45
200 200
*/
    }
    getch();

}
