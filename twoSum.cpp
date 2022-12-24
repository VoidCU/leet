#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> a;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    a.push_back(i);
                    a.push_back(j);
                    break;
                }
            }
        }

        return a;
    }
};

int main()
{
    vector<int> x{2, 11, 7, 15}, a;
    Solution s;

    a = s.twoSum(x, 9);
    for (int o : a)
    {
        cout << o << endl;
    }
    return 0;
}