#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return head;

        /*if (head->next == NULL)
            return NULL;*/

        ListNode* p = NULL;
        ListNode* q = NULL;

        while (/*p->next != NULL && */n > 0) {
            if (p == NULL)
                p = head;
            else 
                p = p->next;
            --n;
        }

        while (p->next != NULL) {
            p = p->next;
            if (q == NULL)
                q = head;
            else
                q = q->next;
        }

        ListNode* tmp = NULL;
        if (q == NULL) {
            tmp = head;
            head = head->next;
        } else {
            tmp = q->next;
            q->next = q->next->next;
        }
        delete tmp;
        return head;
    }
};


// No need debug