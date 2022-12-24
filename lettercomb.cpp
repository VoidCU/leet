#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        string s[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        vector<string> temp;
        for (auto a : digits)
        {
            temp.clear();
            int t = a - '0' - 2;
            if (ans.size() == 0)
            {
                for (auto x : s[t])
                {
                    string omg = "";
                    omg += x;
                    temp.push_back(omg);
                }
                ans = temp;
            }
            else
            {
                for (auto x : ans)
                {
                    string omg;
                    for (auto j : s[t])
                    {
                        omg = x;
                        omg += j;
                        temp.push_back(omg);
                    }
                }
                ans = temp;
            }
        }

        return ans;
    }
};

int main()
{
    string s = "23";
    Solution S;
    vector<string> ans;
    ans = S.letterCombinations(s);
    cout << ans.size() << endl;
    for (auto a : ans)
    {
        cout << a << endl;
    }
    return 0;
}