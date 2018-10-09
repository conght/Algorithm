/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        ListNode* ans = head;

        if (NULL == head) return ans;

        int length = 0;
        while (head) {
            ++length;
            head = head->next;
        }

        k = k%length;

        if (0 == k) return ans;

        k = length - k;
        ListNode* p=ans;
        ListNode* q=ans;
        head = ans;
        for (int i=0; i<k-1; i++) p = p->next;
        q = p->next;
        ans = q;
        while (q->next) q = q->next;
        q->next = head;
        p->next = NULL;

        return ans;
    }
};