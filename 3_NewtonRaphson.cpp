#include<bits/stdc++.h>

using namespace std;


class NewtonRaphson {

    private:
    int calc_initial()
    {
        return rand()%10;
    }

    double f(double x)
    {
        return x*x*x - 2*x - 5;
    }

    double fp(double x)
    {
        return 3*x*x - 2;
    }

    public:
    double solve(double eps)
    {
        int a = calc_initial();
        double epsr = 1000;
        double xr = a;
        double x = a;

        do
        {
            x = x - f(x)/fp(x);

            epsr = f(x)/fp(x);

        } while (epsr > eps);

        return x;
    }


};


int main()
{
    NewtonRaphson nr;

    cout<<nr.solve(0.001)<<endl;

    return 0;
}