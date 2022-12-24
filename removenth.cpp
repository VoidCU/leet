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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int count = 0;
        ListNode *test = head;
        while (test != nullptr)
        {
            count++;
            test = test->next;
        }
        cout << count << endl;
        if (count == n)
        {
            return head->next;
        }
        count -= n;
        ListNode *pre;
        ListNode *curr = head;
        while (true)
        {
            if (count == 0)
            {
                pre->next = curr->next;
                break;
            }
            pre = curr;
            curr = curr->next;
            count--;
        }
        return head;
    }
};

int main()
{
    Solution S;
    int num[] = {1};
    ListNode *ans;
    ListNode *head = new ListNode(num[0]);
    ListNode *curr = head;
    for (int i = 1; i < sizeof(num) / sizeof(int); i++)
    {
        ListNode *node = new ListNode(num[i]);
        curr->next = node;
        curr = curr->next;
    }
    ans = S.removeNthFromEnd(head, 1);
    while (ans != nullptr)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }
    return 0;
}