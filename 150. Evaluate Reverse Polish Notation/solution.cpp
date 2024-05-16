class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        vector<string> s;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+")
            {
                pair<int, int> op = getOperators(s);
                s.push_back(to_string(op.first+op.second));
            }

            else if (tokens[i] == "-")
            {
                pair<int, int> op = getOperators(s);
                s.push_back(to_string(op.second-op.first));
            }
            else if (tokens[i] == "*")
            {
                pair<int, int> op = getOperators(s);
                s.push_back(to_string(op.first * op.second));
            }
            else if (tokens[i] == "/")
            {
                pair<int, int> op = getOperators(s);
                s.push_back(to_string(op.second/op.first));
            }
            else
            {
                s.push_back(tokens[i]);
            }
        }
        return stoi(s[0]);
    }
    pair<int, int> getOperators(vector<string> & s)
    {
        pair<int, int> op = {stoi(s[s.size()-1]), stoi(s[s.size()-2])};
        s.pop_back();s.pop_back();
        return op;
    }
};