class MinStack {
private:
    vector<pair<int, int>> s;
public:
    MinStack() {

    }

    void push(int val) {
        if (s.size() == 0)
            s.push_back({val, val});
        else
        {
            s.push_back({val,min(val,s[s.size()-1].second)});
        }
    }

    void pop() {
        s.pop_back();
    }

    int top() {
        if (s.size()>0)
            return s[s.size()-1].first;
        else
            return NULL;
    }

    int getMin() {
        return s[s.size()-1].second;
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