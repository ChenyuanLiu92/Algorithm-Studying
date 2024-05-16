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
    ListNode* rotateRight(ListNode* head, int k) {
        // 排除特殊值
        if (head == nullptr)
            return nullptr;

        vector<int> s;
        ListNode * p = head;
        int length = 0;
        while (p)
        {
            s.push_back(p->val);
            p = p->next;
            length++;
        }
        p = head;
        // 无论k为多大，实际上都等于旋转k % length次
        k = k % length;

        //反转整个链表
        for(int i = 0; i<s.size(); i++)
        {
            p->val = s[s.size()-1-i];
            p = p->next;
        }

        p = head;
        // 清空栈
        while(s.size()>0)
            s.pop_back();

        //反转前k个结点
        for (int i = 0; i<k;i++)
        {
            s.push_back(p->val);
            p = p->next;
        }

        ListNode * q = head;
        for (int i = 0; i<k; i++)
        {
            q->val =  s[s.size()-1-i];
            q = q->next;
        }
        // 清空栈
        while(s.size()>0)
            s.pop_back();

        // p保存的刚好是第k+1个结点
        q = p;
        for (int i = 0;i<length-k;i++)
        {
            s.push_back(p->val);
            p = p->next;
        }

        // 反转后续的结点
        for (int i = 0;i<length-k;i++)
        {
            q->val = s[s.size()-i-1];
            q = q->next;
        }

        return head;
    }
};