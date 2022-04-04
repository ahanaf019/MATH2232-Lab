#include<bits/stdc++.h>


using namespace std;


class Bisection {

    private:
    void calc_range(int &a, int &b)
    {
        do
        {
            a = rand()%10;
            b = rand()%10;

            if(rand()%2) 
                a *= -1;

            if(rand()%2)
                b *= -1;

        }while(equation(double(a)) * equation(double(b)) > 0);

        if(a > b) swap(a, b);
    }

    double equation(double x)
    {
        // Equation: x^3 - x - 1 = 0
        return x*x*x - 2*x - 5;
    }


    public:
    double solve(long eps)
    {
        int a = 0,b = 0;
        calc_range(a,b);

        double xa = a;
        double xb = b;
        cout<<xa<<" "<<xb<<endl;

        double xrp = 1000;
        double epsr = 1;
        double xr;

        do 
        {
            xr = (xa + xb)/2;

            if(equation(xr) == 0) return xr;

            else if(equation(xr) > 0) xb = xr;
            else xa = xr;

            epsr = abs((xr - xrp)/xr);
            xrp = xr;

        }while(epsr > eps);


        return xr;
    }
};


int main()
{
    Bisection b;

    cout<<b.solve(0.02)<<endl;



    return 0;
}