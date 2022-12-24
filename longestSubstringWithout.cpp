#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++)
        {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;

            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

int main()
{

    int ans;
    Solution S;
    int oo[5];
    for (int i = 0; i < 5; i++)
    {
        oo[i] = -1;
    }
    string s = "abcdcfaeaabcbb";
    ans = S.lengthOfLongestSubstring(s);
    cout << ans << endl;
    for (auto i : oo)
    {
        cout << i << endl;
    }
    return 0;
}
