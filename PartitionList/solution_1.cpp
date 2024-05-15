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
    ListNode* partition(ListNode* head, int x) {
        vector<int> q_1;
        vector<int> q_2;
        ListNode * p = head;
        while (p != nullptr)
        {
            if (p->val < x)
            {
                q_1.push_back(p->val);
            }
            else
            {
                q_2.push_back(p->val);
            }
            p = p->next;
        }
        p = head;
        for (int i = 0; i <q_1.size(); i++)
        {
            p->val = q_1[i];
            p = p->next;
        }
        for (int i = 0; i < q_2.size(); i++)
        {
            p->val = q_2[i];
            p = p->next;
        }

        return head;
    }
};