#include <iostream>
#include <fstream>

using namespace std;

const double K1 = 0.008, K2 = 0.002;

double fun1(double c1, double c2, double c3, double t)
{
    return c1 + (K2 * c3 - K1 * c1 * c2) * t;
}

double fun2(double c1, double c2, double c3, double t)
{
    return c2 + (K2 * c3 - K1 * c1 * c2) * t;
}

double fun3(double c1, double c2, double c3, double t)
{
    return c3 + (2 * K1 * c1 * c2 - 2 * K2 * c3) * t;
}

int main()
{
    double c1 = 50, c2 = 25, c3 = 0, t1, t2;
    ofstream fout("cherex.csv");
    fout << "time,Chemical1,Chemical2,Chemical3" << endl;
    for (double i = 0; i <= 10; i += 0.1)
    {
        t1 = fun1(c1, c2, c3, i);
        t2 = fun2(c1, c2, c3, i);
        c3 = fun3(c1, c2, c3, i);
        c1 = t1;
        c2 = t2;
        fout << i << "," << c1 << "," << c2 << "," << c3 << endl;
    }

    fout.close();
    return 0;
}
