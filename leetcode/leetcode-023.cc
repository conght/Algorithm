#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

typedef struct _Item
{
    int val;
    int index;
} Item;

class greater_class{
public:
    bool operator()(Item a, Item b)
    {
        return a.val > b.val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(0);
        ListNode* p = ans;

        vector<Item> heap;
        int round = 0;
        for (int i=0;i<heap.size();i++) {
            if (lists[i] == NULL)
                continue;
            ++round;
            Item item;
            item.val = lists[i]->val;
            item.index = i;
            heap[i] = item;
        }

        make_heap(heap.begin(), heap.end(), greater_class());


        while (round > 0) {
            pop_heap(heap.begin(), heap.end(), greater_class());
            Item top = heap.back();
            heap.pop_back();
            p->next = lists[top.index];
            lists[top.index] = p->next->next;
            if (lists[top.index] != NULL) {
                push_heap(heap.begin(), heap.end(), greater_class());
            } else {
                --round;
            }
        }

        ListNode* tmp = ans;
        ans = ans->next;
        tmp->next = NULL;
        delete tmp;
        return ans;
    }
};