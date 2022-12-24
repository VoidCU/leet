#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string s = strs[0];
        string temp = "";
        int len = s.length();
        for (int x = 1; x < strs.size(); x++)
        {
            temp = "";
            len = s.length();
            if (len > strs[x].length())
                len = strs[x].length();
            for (int i = 0; i < len; i++)
            {
                if (s[i] == strs[x][i])
                {
                    temp += s[i];
                }
                else
                {
                    break;
                }
            }
            s = temp;
        }
        return s;
    }
};

int main()
{
    Solution S;
    vector<string> strs{"dog", "racecar", "car"};
    cout << S.longestCommonPrefix(strs) << endl;
    return 0;
}