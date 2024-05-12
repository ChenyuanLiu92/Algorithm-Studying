/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;

        Node * res;
        Node * p1 = head;
        Node * q1;

        // 构造顺序结构
        res = new Node(p1->val);
        q1 = res;
        p1 = p1->next;

        while (p1 != NULL)
        {
            q1->next = new Node(p1->val);
            q1 = q1->next;
            p1 = p1->next;
        }

        // 构建随机顺序
        // 用两个map，一个map为节点对应的序号，一个为序号对应结点
        map<Node*, int> map1;
        map<int, Node*> map2;
        // 构建第一个map
        Node* p2 = head;
        int idx = 0;
        map1[NULL] = -1;
        while (p2 != NULL)
        {
            map1[p2] = idx++;
            p2 = p2->next;
        }
        // 构建第二个map
        map2[-1] = NULL;
        Node* p3 = res;
        idx = 0;
        while (p3 != NULL)
        {
            map2[idx++] = p3;
            p3 = p3->next;
        }

        Node * p = head;
        Node * q = res;

        while (p != NULL)
        {
            q->random = map2[map1[p->random]];
            q = q->next;
            p = p->next;
        }
        return res;
    }
};