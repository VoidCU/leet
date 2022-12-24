#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        bool pose = false;
        bool posp = true;
        bool sign = true;
        bool ans = true;
        for (auto a : s)
        {
            if (a >= '0' && a <= '9')
            {
                pose = true;
                sign = false;
            }
            else if ((a == '-' || a == '+') && sign)
            {
                sign = false;
            }
            else if ((a == 'e' || a == 'E') && pose)
            {
                pose = false;
                posp = false;
                sign = true;
            }
            else if (a == '.' && posp)
            {
                posp = false;
            }
        }
    }
};

int main()
{

    Solution S;
    string s = "42";
    // cout << S.myAtoi(s) << endl;
    cout << INT_MAX << endl;
}