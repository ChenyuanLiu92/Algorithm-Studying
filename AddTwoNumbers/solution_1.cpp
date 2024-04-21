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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //相加两个链表
        ListNode * q = l1;

        // l1_pre l2_pre 用于存储两个链表的表尾节点，用于连接两个长度不相等的链表情况
        ListNode * l1_pre;
        ListNode * l2_pre;
        while (l1 != nullptr && l2 != nullptr)
        {
            l1->val += l2->val;
            l1_pre = l1;
            l2_pre = l2;
            l1 = l1->next;
            l2 = l2->next;
        }

        // 当两个链表长短不一，则将相加的结果与长链表的剩余部分相连
        if (l1 != nullptr)
            l2_pre->next = l1;

        if (l2 != nullptr)
            l1_pre->next = l2;

        ListNode * result = q;
        int add = 0;
        // q_pre用于存储表尾节点，用于创建由近位导致的新节点创建情况
        ListNode * q_pre;

        // 进位部分算法
        while (q != nullptr)
        {
            q->val += add;
            add = q->val / 10;
            q->val %= 10;
            q_pre = q;
            q = q->next;
        }

        // 如果进位会导致在末尾产生新一位，则在末尾新创建一个节点
        if (add != 0)
        {
            ListNode * newNode = new ListNode(add);
            q_pre->next = newNode;
        }

        return result;

    }
};