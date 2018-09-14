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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
        ListNode* p = new ListNode(0);
        ListNode* ans = p;

        vector<Item> heap;
        int round = 0;
        for (int i=0;i<lists.size();i++) {
            if (lists[i] == NULL)
                continue;
            ++round;
            Item item;
            item.val = lists[i]->val;
            item.index = i;
            heap.push_back(item);
        }

        make_heap(heap.begin(), heap.end(), greater_class());


        while (round > 1) {
            pop_heap(heap.begin(), heap.end(), greater_class());
            Item top = heap.back();
            heap.pop_back();
            p->next = lists[top.index];
            p = p->next;
            lists[top.index] = p->next;
            if (lists[top.index] != NULL) {
                Item item;
                item.val = lists[top.index]->val;
                item.index = top.index;
                heap.push_back(item);
                push_heap(heap.begin(), heap.end(), greater_class());
            } else {
                --round;
            }
        }

        for (int i=0;i<lists.size();i++) {
            if (lists[i] == NULL)
                continue;
            p->next = lists[i];
            break;
        }

        ListNode* tmp = ans;
        ans = ans->next;
        tmp->next = NULL;
        delete tmp;
        return ans;
    }
};

int main() {
    ListNode a1(1);
    ListNode a2(4);
    ListNode a3(5);
    a1.next = &a2;
    a2.next = &a3;

    ListNode b1(1);
    ListNode b2(3);
    ListNode b3(4);
    b1.next = &b2;
    b2.next = &b3;

    ListNode c1(2);
    ListNode c2(6);
    c1.next = &c2;

    vector<ListNode*> lists;
    lists.push_back(&a1);
    lists.push_back(&b1);
    lists.push_back(&c1);

    Solution s;
    ListNode* ans = s.mergeKLists(lists);

    while (ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}