#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ;


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }

        ListNode* ans = l1;
        int c = 0;

        while (l1->next != NULL && l2->next != NULL) {
            l1->val += (l2->val + c);
            c = l1->val / 10;
            l1->val = l1->val % 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        l1->val += (l2->val + c);
        c = l1->val / 10;
        l1->val = l1->val % 10;

        if (l1->next == NULL) {
            l1->next = l2->next;
        }

        while (l1->next != NULL) {
            l1 = l1->next;
            l1->val += c;
            c = l1->val / 10;
            l1->val = l1->val % 10;
        }
        if (c > 0) {
            l1->next = new ListNode(c);
        }
        return ans;
    }

};

int main() {
    ListNode a(5), b(5);
    Solution s;
    ListNode* ans = s.addTwoNumbers(&a, &b);
    while (ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}