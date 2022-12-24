#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<int> a;
        vector<vector<int>> b;
        int size = nums.size();
        if (nums.size() < 3)
        {
            vector<vector<int>> b{a};
            return b;
        }
        for (int i = 0; i < size - 2; i++)
        {
            for (int j = i + 1; j < size - 1; j++)
            {
                for (int k = j + 1; k < size; k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> x{nums[i], nums[j], nums[k]};
                        sort(x.begin(), x.end());
                        std::vector<int>::iterator it;
                        it = find(b.begin(), b.end(), x);
                        if (it == b.end())
                            b.push_back(x);
                    }
                }
            }
        }

        return b;
    }
};

int main()
{
    Solution S;
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans;
    ans = S.threeSum(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].size() == 3)
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
    }
    return 0;
}