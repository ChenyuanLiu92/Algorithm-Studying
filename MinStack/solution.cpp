class MinStack {
private:
    vector<int> s;
    int size;
    int min;


public:
    MinStack() {
        size = 0;
        min = INT_MAX;
    }

    void push(int val) {
        s.push_back(val);
        size++;
        refreshMin();
    }

    void pop() {
        s.pop_back();
        size--;
        refreshMin();
    }

    int top() {
        return s[size-1];

    }

    int getMin() {
        return min;
    }

    void refreshMin(){
        min = INT_MAX;
        for (int i = 0; i<size;i++)
        {
            if (s[i]<min)
                min = s[i];
        }
        if (size == 0)
            min = NULL;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */