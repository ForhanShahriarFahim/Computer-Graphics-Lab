#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
//Clipping Window
int xMin = 130, xMax = 500, yMin = 100, yMax = 350;
//Region Code
int Left = 1, Right = 2, Bottom = 4, Top = 8;

int regionCode(int x, int y)
{
    int code = 0;
    if(x<xMin) code |= Left;
    else if(x>xMax) code |= Right;
    if(y<yMin) code |= Bottom;
    else if(y>yMax) code |=Top;
    return code;
}

void cohenSutherland(int x1, int y1, int x2, int y2)
{
    int code1 = regionCode(x1,y1);
    int code2 = regionCode(x2,y2);

    bool inside = false;
    while(true)
    {
        int x,y;
        if(!(code1|code2)) // Line is inside
        {
            inside = true;
            break;
        }
        else if(code1 & code2) break; // Line is outside
        else // Line is partially inside
        {
            int code;
            if(code1)code = code1;
            else code = code2;

            if(code&Top)
            {
                y = yMax;
                x = x1 + (x2 -x1)/(y2-y1) * (y - y1);
            }
            else if(code & Bottom)
            {
                y = yMin;
                x = x1 + (x2-x1)/(y2-y1) * (y - y1);
            }
            else if(code & Left)
            {
                x = xMin;
                y = y1 + (y2-y1)/(x2-x1) * (x-x1);
            }
            else if(code & Right)
            {
                x = xMax;
                y = y1 + (y2 - y1) / (x2-x1) * (x - x1);
            }
            if(code == code1)
            {
                x1 = x;
                y1 = y;
                code1 = regionCode(x1,y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = regionCode(x2,y2);
            }

        }


    }
    if(inside)
        {

            rectangle(xMin, yMin, xMax, yMax);
            setcolor(WHITE);
            line(x1,y1,x2,y2);
        }
}

int main()
{
    int gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");
    while(true)
    {
        cohenSutherland(100, rand()%1000,700,400);
        delay(10);
    }

    getch();
    return 0;
}
