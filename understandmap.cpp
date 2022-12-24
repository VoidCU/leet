#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;
int main()
{
    map<int, int> check;
    map<int, int>::iterator itr;
    vector<int> nums1{1, 2};
    vector<int> nums2{1, 2};
    vector<int> nums3{1, 2};
    vector<int> nums4{1, 2};
    cout << check[5];
    for (itr = check.begin(); itr != check.end(); itr++)
    {
        cout << itr->first << "\t" << itr->second << endl;
    }
    return 0;
}