#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int hs = haystack.length();
        int ns = needle.length();
        for (int i = 0; i <= hs - ns; i++)
        {
            if (haystack.substr(i, 3) == needle)
                return i;
        }

        return -1;
    }
};

int main()
{
    Solution S;
    string hay = "sadbutsad";
    cout << hay.length() << endl;
    hay.erase(0, 1);
    cout << hay.length() << endl;
    cout << hay << endl;
    string ned = "sad";
    // cout << S.strStr(hay, ned) << endl;
    return 0;
}