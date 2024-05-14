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
    ListNode* deleteDuplicates(ListNode* head) {
        // 用一个哈希表记录所有重复次数超过1的结点，然后再次遍历删除这些结点
        map<int, int> mymap;
        ListNode * p = head;
        while ( p != nullptr )
        {
            if (mymap.find(p->val) == mymap.end())
            {
                mymap[p->val] = 1;
            }
            else
            {
                int times = mymap[p->val];
                mymap[p->val] = times + 1;
            }
            p = p->next;
        }

        p = head;
        ListNode * pre = nullptr;
        ListNode * res = p;
        while(p != nullptr)
        {
            if (mymap[p->val]>1)
            {
                ListNode * tmp = p;
                p = p->next;
                if (res == tmp)
                {
                    res = p;
                }
                if (pre != nullptr)
                    pre->next = p;

                delete tmp;
            }
            else
            {
                pre = p;

                p = p->next;
            }
        }

        return res;
    }
};