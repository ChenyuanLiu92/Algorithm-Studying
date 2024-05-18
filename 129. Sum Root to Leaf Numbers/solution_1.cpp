/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int res = 0;

public:
    int sumNumbers(TreeNode* root) {
        // 在先根遍历的基础上， 用一个容器来存储遍历的结果；
        // 当遍历到叶子结点时候，进行计算；
        // 注意，这个容器在回溯过程中需要保证不同状态，因此，这个容器不可以是引用类型。
        if (root == nullptr)
            return 0;
        vector<string> q;
        sumNumbersHelper(root, q);
        return res;

        }

    void sumNumbersHelper(TreeNode* root, vector<string> q)
    {
        if (root != nullptr)
        {
            q.push_back(to_string(root->val));
            if (root->left == nullptr && root->right == nullptr)
            {
                string sum = "";
                for (int i = 0; i < q.size(); i++)
                {
                    sum += q[i];
                }
                int int_sum = stoi(sum);
                cout<<int_sum<<endl;
                res += int_sum;
            }
            sumNumbersHelper(root->left, q);
            sumNumbersHelper(root->right, q);
        }
    }

};