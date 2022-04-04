#include<bits/stdc++.h>

using namespace std;

class FalsePosition {

    private:
    double equation(double x)
    {
        return x*x*x - 2*x -5;
    }

    void calc_range(int &a, int &b)
    {

        do
        {
            a = rand() % 10;
            b = rand() % 10;

            if(rand()%2) a *= -1;
            if(rand()%2) b *= -1;

        } while (equation(a) * equation(b) > 0);
        
        if(a > b) swap(a,b);

    }


    public:
    double solve(double eps)
    {
        int a, b;

        calc_range(a,b);
        cout<<a<<" "<<b<<endl;

        double epsr = 10;
        double xr, xrp = 10;
        double xa = a;
        double xb = b;

        do
        {
            xr = xa - (xb - xa) * equation(xa) / (equation(xb) - equation(xa));

            if(equation(xr) == 0) return xr;

            if(equation(xr) > 0) xb = xr;
            else xa = xr;

            cout<<xa<<" "<<xb<<endl;

            epsr = abs((xr - xrp)/xr);
            xrp = xr;

        }while(epsr > eps);

        return xr;
    }


};


int main()
{
    FalsePosition fp;

    cout<<fp.solve(0.00005)<<endl;

    return 0;
}