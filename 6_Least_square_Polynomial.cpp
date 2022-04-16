#include<bits/stdc++.h>

using namespace std;


class Point {
    public:
    int x;
    int y;

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};


class LC_Polynomial {
    private:
    vector<Point> points;
    map<int, vector<double>> eq;


    public:
    LC_Polynomial(vector<Point> points)
    {
        this->points = points;
    }

    void solve()
    {
        int m = points.size();
        double x = 0;
        double x2 = 0;
        double x3 = 0;
        double x4 = 0;
        double y = 0;
        double xy = 0;
        double x2y = 0;


        for(auto point: points)
        {
            x += point.x;
            x2 += point.x * point.x;
            x3 += point.x * point.x * point.x;
            x4 += point.x * point.x * point.x * point.x;
            y += point.y;
            xy += point.x * point.y;
            x2y += point.x * point.x * point.y;
        }


        eq[0].push_back(m);
        eq[0].push_back(x);
        eq[0].push_back(x2);
        eq[0].push_back(y);

        eq[1].push_back(x);
        eq[1].push_back(x2);
        eq[1].push_back(x3);
        eq[1].push_back(xy);
        
        eq[2].push_back(x2);
        eq[2].push_back(x3);
        eq[2].push_back(x4);
        eq[2].push_back(x2y);
        
        // cout<<"spes";


        print_eqs();
    
        solve_eq();
    }


    void print_eqs()
    {
        for(int i = 0; i < eq.size(); i++)
        {
            for(int j = 0; j < eq[i].size(); j++)
            {
                printf("%7.1f", eq[i][j]);
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void solve_eq()
    {

        for(int j = 0; j < 3; j++) 
        {
            for(int i = 0; i < 3; i++) 
            {
                if(i!=j) 
                {
                    double b=eq[i][j]/eq[j][j];
                    for(int k = 0; k <= 3 + 1; k++) 
                    { 
                        eq[i][k] = eq[i][k] - b* eq[j][k];
                    }
                }
            }
        }

        print_eqs();

        stack<double> stk;

        for(int i = 2; i >= 0; i--)
        {
            stk.push(eq[i][3] / eq[i][i]);
        }

        while(!stk.empty())
        {
            cout<<stk.top()<<" ";
            stk.pop();
        }
        cout<<endl;


    }


};



int main()
{
    LC_Polynomial *lp;

    vector<Point> p;
    p.push_back(Point(0,1));
    p.push_back(Point(1,6));
    p.push_back(Point(2,17));
    lp = new LC_Polynomial(p);
    // cout<<"swq";

    lp->solve();

    return 0;
}