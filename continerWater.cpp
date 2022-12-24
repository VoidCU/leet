#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ans = 0;
        int temp;
        int size = height.size();
        int left = 0;
        int right = size - 1;
        while (left != right)
        {
            if (height[left] > height[right])
            {
                temp = height[right] * (right - left);
                right--;
            }
            else
            {
                temp = height[left] * (right - left);
                left++;
            }
            ans = ans > temp ? ans : temp;
        }
        return ans;
    }
};

int main()
{
    Solution S;
    int ans;
    vector<int> val{1, 2, 1};

    ans = S.maxArea(val);
    cout << ans << endl;
    return 0;
}