#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<int> a;
        vector<vector<int>> b;
        bool exist = false;
        int count = -1;
        int size = nums.size();
        if (nums.size() < 3)
        {
            vector<vector<int>> b{a};
            return b;
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        int j, m;
        while (nums[i] <= 0)
        {
            j = size - 1;
            m = i + 1;
            if (i > 0 && nums[i] == nums[i - 1])
            {
                i++;
                continue;
            }
            while (m < j)
            {
                if (nums[j] < 0)
                    break;
                if (m > (i + 1) && nums[m] == nums[m - 1])
                {
                    m++;
                    continue;
                }
                if (nums[i] + nums[j] + nums[m] == 0)
                {

                    vector<int> x{nums[i], nums[m], nums[j]};
                    if (count == -1 || b[count] != x)
                    {
                        b.push_back(x);
                        count++;
                    }
                    m++;
                    j--;
                }
                else if (nums[i] + nums[j] + nums[m] > 0)
                {
                    j--;
                }
                else if (nums[i] + nums[j] + nums[m] < 0)
                {
                    m++;
                }
            }
            i++;
        }

        return b;
    }
};

int main()
{
    Solution S;
    vector<int> nums{-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
    vector<vector<int>> ans;
    ans = S.threeSum(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].size() == 3)
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
    }
    return 0;
}