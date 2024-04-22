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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * i;
        ListNode * res;
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        // 第一次比较,初始化遍历指针i和返回结果指针res
        if (list1->val <= list2->val)
        {
            i = list1;
            res = list1;
            list1 = list1->next;
        }
        else
        {
            i = list2;
            res = list2;
            list2 = list2->next;
        }

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                i->next = list1;
                list1 = list1->next;
            }
            else
            {
                i->next = list2;
                list2 = list2->next;
            }
            i = i->next;
        }

        if (list1 != nullptr)
            i->next = list1;

        if (list2 != nullptr)
            i->next = list2;

        return res;
    }
};