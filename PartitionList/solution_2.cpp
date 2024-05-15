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
        ListNode * small = nullptr, *big = nullptr, *head2 = nullptr, *p = head;
        while(p != nullptr){
            if(p->val < x){
                if(small != nullptr)
                    small->next = p;
                else
                    head = p;
                small = p;
            } else{
                if(big != nullptr)
                    big->next = p;
                else
                    head2 = p;
                big = p;
            }
            p = p->next;
        }
        if(big != nullptr)
            big->next = nullptr;
        if(small != nullptr)
            small->next = head2;
        return head;
    }
};