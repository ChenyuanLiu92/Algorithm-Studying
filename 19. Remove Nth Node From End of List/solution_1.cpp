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
        // 即删除头结点，需要变更返回值
        // 首先使用暴力法
        ListNode* p = head;
        int counter = 0;
        while ( p != nullptr)
        {
            counter++;
            p = p->next;
        }
        // 找counter - n + 1个节点

        if (n == counter)
        {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }

        ListNode* pre = nullptr;
        p = head;
        for (int i = 0 ;i < counter-n; i++)
        {
            pre = p;
            p = p -> next;
        }
        cout<<pre->val<<endl;
        ListNode* tmp = p;
        pre->next = p->next;
        delete tmp;
        return head;
    }
};