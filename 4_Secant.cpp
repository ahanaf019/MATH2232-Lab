#include<bits/stdc++.h>

using namespace std;

class Secant {
    
    private:
    void calc_range(int &a, int &b)
    {
        a = rand()%100;
        b = rand()%100;
    }

    double f(double x)
    {
        return x*x*x - 2*x - 5;
    }

    double fp(double x, double y)
    {
        return (f(y) - f(x))/(y - x);

    }


    public:
    double solve(double eps)
    {
        int a, b;
        calc_range(a,b);

        double xa = a;
        double xb = b;
        double epsr;
        double x;

        do
        {
            x = xb - f(xb)/fp(xa,xb);
            xa = xb;
            xb = x;
        
            epsr = f(xb)/fp(xa,xb);

        } while (epsr > eps);
        
        return x;
    }


};


int main()
{
    Secant s;

    cout<<s.solve(0.001)<<endl;

    return 0;
}