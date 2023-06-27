#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;


int factorial(int n)
{
    if(!n) return 1;
    return n * factorial(n-1);
}

double power(double p, double n)
{
    double ans = 1.0;
    while(n--)
    {
        ans*=p;
    }
    return ans;
}

double nCr(int n, int r)
{
    return factorial(n)/(double)(factorial(r) * factorial(n-r));
}

double bezierFunction(int i, int n, double u)
{
    return nCr(n, i) * power(u, i) * power((1 - u), (n - i));
}


void bezierCurve(vector<pair<int,int>>&xy)
{
    int n = xy.size()-1;
    double eps = 0.0005;
    for(double u = 0;u<=1;u+=eps)
    {
        double x = 0.0, y = 0.0;

        for(int i = 0;i<=n;i++)
        {
            double bez = bezierFunction(i, n, u);
            x += xy[i].first * bez;
            y += xy[i].second * bez;
        }
        putpixel(x, y, WHITE);
    }
    for(auto it: xy)
    {
        putpixel(it.first, it.second,WHITE);
        circle(it.first, it.second, 5);
    }
}

int main()
{
    int gd = DETECT, dm = DETECT;
    initgraph(&gd, &dm,"");
    vector<pair<int,int>>xy{{30, 300}, {101,47}, {250, 250}, {350, 50}};
    bezierCurve(xy);
    getch();
    return 0;
}
