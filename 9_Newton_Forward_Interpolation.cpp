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


class Newton_Forward_Interpolation {
    private:  
    vector<Point> points;
    double table[10][10] = {0};

    void make_table()
    {
        for(int i = 0; i < points.size(); i++)
            table[i][0] = points[i].y;
        
        for(int i = 1; i < points.size(); i++)
        {
            for(int j = i; j < points.size(); j++)
            {
                table[j - i][i] = table[j - i + 1][i - 1] - table[j - i][i - 1];
            }
        }
    }

    void print_table()
    {
        for(int i = 0; i < points.size(); i++)
        {
            for(int j = 0; j < points.size(); j++)
            {
                printf("%8.2f", table[i][j]);
            }
            cout<<endl;
        }
    }


    public:
    Newton_Forward_Interpolation(vector<Point> points)
    {
        this->points = points;
    }

    void solve(double x)
    {
        make_table();
        print_table();

        double h = points[1].x - points[0].x;
        double res = 0;
        for(int i = 0; i < points.size(); i++)
        {
            double p = 1;
            for(int j = 0; j < i; j++)
            {
                p *= (x - points[j].x) * 1 / ((j+1) * h);
                // cout<<j<<endl;
            }
            // cout<<p * table[0][i]<<endl;

            res += p * table[0][i];
        }

        cout<<"Result for x="<<x<<": "<<res<<endl;
    }
    

};


int main()
{
    vector<Point> p;
    p.push_back(Point(1,24));
    p.push_back(Point(3,120));
    p.push_back(Point(5,336));
    p.push_back(Point(7,720));


    Newton_Forward_Interpolation *nfi;
    nfi = new Newton_Forward_Interpolation(p);

    nfi->solve(4);

    return 0;
}