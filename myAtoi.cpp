#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int ans = 0;
        int neg = 0;
        for (auto a : s)
        {
            int ans = 0;
            int neg = 0;
            for (auto a : s)
            {
                if (a == '+')
                {
                    cout << "  1" << endl;
                    if (neg == 0)
                        neg = 1;
                    else
                        return 0;
                }
                else if (a == '-')
                {
                    cout << "  2" << endl;
                    if (neg == 0)
                        neg = -1;
                    else
                        return 0;
                }
                else if (a >= '0' && a <= '9')
                {
                    cout << "  3" << endl;
                    if (ans > (INT_MAX / 10) || ans > ((INT_MAX / 10) + (a - '0')))
                        if (neg == 0)
                            return (INT_MAX)-1;
                        else
                            return (INT_MAX)*neg - 1;
                    cout << a << endl;
                    ans = ans * 10 + (a - '0');
                }
                else if (a == ' ')
                {
                    cout << "  4" << endl;
                    continue;
                }
                else
                {
                    cout << "  5" << endl;
                    if (neg == 0 || neg == 1)
                        return ans;
                    else
                        return ans * neg;
                }
            }
        }
        if (neg == 0 || neg == 1)
            return ans;
        else
            return ans * neg;
    }
};
int main()
{

    Solution S;
    string s = "42";
    // cout << S.myAtoi(s) << endl;
    cout << INT_MAX << endl;
    return 0;
}