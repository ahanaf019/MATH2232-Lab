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


class Least_Square {
    private:
    vector<Point> points;

    public:
    void solve()
    {
        double x = 0;
        int m = points.size();
        double x2 = 0;
        double y = 0;
        double xy = 0;

        for(auto point: points)
        {
            x += point.x;
            y += point.y;
            x2 += point.x * point.x;
            xy += point.x * point.y;
        }

        double a1 = (x * y - m * xy) / (x * x - m * x2);

        double a0 = (y * x2 - xy * x) / (m * x2 - x * x);

        cout<<a0<<" "<<a1<<endl;


    }

    Least_Square(vector<Point> points)
    {
        this->points = points;
    }

};



int main()
{
    vector<Point> p;
    p.push_back(Point(1, 0.6));
    p.push_back(Point(2, 2.4));
    p.push_back(Point(3, 3.5));
    p.push_back(Point(4, 4.8));
    p.push_back(Point(5, 5.7));

    Least_Square *ls = new Least_Square(p);

    ls->solve();

    return 0;
}