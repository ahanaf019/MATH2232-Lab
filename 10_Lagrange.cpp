#include<bits/stdc++.h>

using namespace std;

class Point{
    public:
    double x;
    double y;

    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
};

class Lagrange{
    private:
    vector<Point> points;

    public:
    Lagrange(vector<Point> points)
    {
        this->points = points;
    }

    void solve(double x)
    {
        double res = 0;
        for(int i = 0; i < points.size(); i++)
        {
            double p = 1;

            for(int j = 0; j < points.size(); j++)
            {
                if(i != j)
                    p *= (x - points[j].x) / (points[i].x - points[j].x);
            }

            res += p * points[i].y;

        }
        cout<<res<<endl;
    }


};


int main()
{
    vector<Point> p;
    p.push_back(Point(300,2.4771));
    p.push_back(Point(304,2.4829));
    p.push_back(Point(305,2.4843));
    p.push_back(Point(307,2.4871));

    Lagrange *lr = new Lagrange(p);

    lr->solve(301);


    return 0;
}