/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int counter = 0;
        ListNode * p = head;
        ListNode * q = head;
        ListNode * pre = nullptr;
        while (p != nullptr)
        {
            p = p->next;
            if (counter >= n)
            {
                pre = q;
                q = q->next;
            }
            counter++;
        }
        if (q == head)
        {
            head = head->next;

        }
        else
        {
            pre->next = q->next;
        }
        delete q;
        return head;
    }
};