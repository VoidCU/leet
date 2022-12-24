#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        double ans = 0;
        int preans = 0;
        int m = nums1.size();
        int n = nums2.size();
        if ((m + n) % 2 == 1)
        {
            for (int i = 0, j = 0, k = 0; i <= (m + n) / 2; i++)
            {
                if (j < m && k < n)
                {
                    if (nums1[j] < nums2[k])
                    {
                        ans = nums1[j++];
                    }
                    else
                    {
                        ans = nums2[k++];
                    }
                }
                else if (j == m)
                {
                    ans = nums2[k++];
                }
                else
                {
                    ans = nums1[j++];
                }
            }
        }
        else
        {
            for (int i = 0, j = 0, k = 0; i <= ((m + n) / 2); i++)
            {
                preans = ans;
                if (j < m && k < n)
                {

                    if (nums1[j] < nums2[k])
                    {
                        ans = nums1[j++];
                    }
                    else
                    {
                        ans = nums2[k++];
                    }
                }
                else if (j == m)
                {
                    ans = nums2[k++];
                }
                else
                {
                    ans = nums1[j++];
                }
            }
            ans = (ans + preans) / 2;
        }
        return ans;
    }
};

int main()
{
    Solution S;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 7};
    double x = S.findMedianSortedArrays(nums1, nums2);
    cout << x << endl;
    return 0;
}