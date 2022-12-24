#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int ans = 0;
        int previadd = 10000;
        for (auto a : s)
        {
            if (a == 'I')
            {
                ans += 1;
                previadd = 1;
            }
            else if (a == 'V')
            {
                if (previadd < 5)
                {
                    ans += 3;
                }
                else
                {
                    ans += 5;
                }
                previadd = 5;
            }
            else if (a == 'X')
            {
                if (previadd < 10)
                {
                    ans += 8;
                }
                else
                {
                    ans += 10;
                }
                previadd = 10;
            }
            else if (a == 'L')
            {
                if (previadd < 50)
                {
                    ans += 30;
                }
                else
                {
                    ans += 50;
                }
                previadd = 50;
            }
            else if (a == 'C')
            {
                if (previadd < 100)
                {
                    ans += 80;
                }
                else
                {
                    ans += 100;
                }
                previadd = 100;
            }
            else if (a == 'D')
            {
                if (previadd < 500)
                {
                    ans += 300;
                }
                else
                {
                    ans += 500;
                }
                previadd = 500;
            }
            else if (a == 'M')
            {
                if (previadd < 1000)
                {
                    ans += 800;
                }
                else
                {
                    ans += 1000;
                }
                previadd = 1000;
            }
        }
        return ans;
    }
};
;

int main()
{
    Solution S;
    string s = "III";
    cout << S.romanToInt(s) << endl;

    return 0;
}