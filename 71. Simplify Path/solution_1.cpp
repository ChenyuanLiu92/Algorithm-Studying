class Solution {
public:
    string simplifyPath(string path) {

        // 定义变量：
        vector<string> stack;
        string tmp;
        string res;

        // 算法流程
        for(int i = 1; i < path.size(); i++)
        {
            if (path[i] != '/')
            {
                tmp += path[i];
            }
            else
            {
                if (tmp == ".")
                {

                }
                else if (tmp == "..")
                {
                    pop(stack);
                }
                else if (tmp == "")
                {

                }
                else
                {
                    push(stack, tmp);
                }
                tmp = "";
            }
        }

        // 构造最后一个字符串
        if (tmp == ".")
        {
            // 什么都不做
        }
        else if (tmp == "..")
        {
            pop(stack);
        }
        else if (tmp == "")
        {
            // 什么都不做
        }
        else
        {
            push(stack, tmp);
        }

        res = buildStr(stack);

        return res;
    }

    // 构建字符串，但不建议这样做，这里偷懒用了vector可以按序遍历的特性，实际上应该按照栈的规则从子目录向根目录的方向构造
    string buildStr(vector<string> stack)
    {
        if (stack.size() == 0)
           return "/";

        string res;
        for (int i = 0; i<stack.size(); i++)
        {
            res += '/';
            res += stack[i];
        }
        return res;
    }

    bool isEmpty(vector<string> & stack)
    {
        return stack.size() == 0 ? true : false;
    }

    void push(vector<string> & stack, string & str)
    {
        stack.push_back(str);
    }

    string pop(vector<string> & stack)
    {
        string res;
        if (!isEmpty(stack))
        {
            res = stack[stack.size()-1];
            stack.erase(stack.end());
        }
        return res;
    }

};