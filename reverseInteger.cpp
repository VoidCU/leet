#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        bool neg = false;
        if (x < INT_MIN)
            return 0;
        if (x < 0)
            neg = true;
        x = abs(x);
        long long int ans = 0;
        while (x != 0)
        {
            if (ans > (INT_MAX / 10) || ans > ((INT_MAX / 10) + x % 10))
                return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        if (neg)
            ans *= -1;
        return ans;
    }
};

int main()
{

    Solution S;
    int a = -1534236469;
    cout << S.reverse(a) << endl;
    return 0;
}