#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() == 1)
            return s;
        else
            return "omg";
    }
};

int main()
{

    Solution S;
    string s = "b";
    string ans;
    ans = S.longestPalindrome(s);
    cout << ans << endl;
    return 0;
}