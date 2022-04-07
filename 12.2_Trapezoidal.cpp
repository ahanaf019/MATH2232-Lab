#include<bits/stdc++.h>

using namespace std;

class Point {
    public:
    double x;
    double y;

    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
};


class Trapezoidal {
    private:
    double high, low;
    int h;
    vector<Point> points;
    
    double f(double x)
    {
        return x * sin(x);
    }

    void make_points()
    {
        double width = (high - low)/h;
        // cout<<width<<endl;

        for(int i = 0; i <= h; i++)
        {
            double x = low + i * width;
            double y = f(x);
            points.push_back(Point(x,y));
            // cout<<x<<" "<<y<<endl;
        }
    }

    public:
    Trapezoidal(double high, double low, int h)
    {
        this->high = high;
        this->low = low;
        this->h = h;
    }



    void solve()
    {
        make_points();
        double h = abs(points[0].x - points[1].x);
        double res = 0;

        for(int i = 1; i < points.size() - 1; i++)
        {
            res += h * points[i].y;
        }

        res += h/2 * (points[0].y + points[points.size() - 1].y);
    
        cout<<res<<endl;
    }
    
};


int main()
{

    Trapezoidal *tz = new Trapezoidal(3.1416, 0, 5);

    tz->solve();

    return 0;
}