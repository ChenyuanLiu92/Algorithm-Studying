class LRUCache {
private:
    int capacity;
    int size;
    struct ListNode{
        int key;
        int value;
        ListNode * next;
        ListNode * pre;
        ListNode(int _key, int _value) : key(_key), value(_value) {}
    };
    ListNode * head;
    ListNode * tail;
    map<int, ListNode *> mymap;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (!mymap.count(key))
        {
            return -1;
        }
        else
        {
            // 插入头部
            ListNode * node = mymap[key];
            moveToHead(node);
            return node->value;
        }
    }

    void put(int key, int value) {
        if (mymap.count(key))
        {
            // 存在，则更新值,插入头部
            ListNode * tmp = mymap[key];
            tmp->value = value;
            moveToHead(tmp);
        }
        else
        {
            // 不存在，查看LRU是否已满
            if (size != capacity)
            {
                // LRU未满
                ListNode * tmp = new ListNode(key, value);
                addToHead(tmp);
                size++;

                mymap[key] = tmp;
            }
            else
            {
                // 已满，移除末尾元素，并更新map，然后插入新元素，再次更新map
                ListNode* tmp = removeTail();
                mymap.erase(tmp->key);
                delete tmp;

                ListNode * insert_node = new ListNode(key, value);
                addToHead(insert_node);
                mymap[key] = insert_node;
            }
        }
    }

    // 处理双向链表的操作
    //插入头部
    void moveToHead(ListNode * node)
    {
        removeNode(node);
        addToHead(node);
    }
    void addToHead(ListNode * node)
    {
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }

    void removeNode(ListNode * node)
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    ListNode *  removeTail()
    {
        ListNode * res = tail->pre;
        removeNode(res);
        return res;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */