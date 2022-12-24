#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *Ldum = new ListNode(0);
        ListNode *Lcurr = Ldum;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry == 1)
        {
            int sum = 0;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            Lcurr->next = node;
            Lcurr = Lcurr->next;
        }
        return Ldum->next;
    }
};

int main()
{
    Solution s;
    ListNode a(3);
    ListNode b(4, &a);
    ListNode c(2, &b);
    // cout << x.next->next->val << endl;
    ListNode x(4);
    ListNode y(6, &x);
    ListNode z(5, &y);

    ListNode *M;
    M = s.addTwoNumbers(&c, &z);
    cout << M->val << endl;
    return 0;
}