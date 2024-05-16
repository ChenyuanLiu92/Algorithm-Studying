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

        Node* res;
        Node* tmp;
        map<Node*, Node*> nodeMap;
        Node* p = head;
        while (p != NULL)
        {
            tmp = new Node(p->val);
            nodeMap[p] = tmp;
            p = p->next;
        }
        res  = nodeMap[head];
        Node * q = head;
        while (q != NULL)
        {
            nodeMap[q]->next = nodeMap[q->next];
            nodeMap[q]->random = nodeMap[q->random];
            q = q->next;
        }
        return res;
    }
};