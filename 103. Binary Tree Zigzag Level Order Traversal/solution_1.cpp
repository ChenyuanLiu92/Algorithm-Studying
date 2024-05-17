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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // 排除异常情况
        vector<vector<int>> res;
        if (root == nullptr)
            return res;

        vector<TreeNode *> queue;
        // 标识方向
        bool flag = true;
        queue.push_back(root);
        while(queue.size() != 0)
        {
            int size = queue.size();
            vector<int> tmp;

            if (flag)
            {
                for (int i = 0; i < size; i++)
                {
                    tmp.push_back(queue[i]->val);
                }
            }
            else
            {
                for (int i = 0; i < size; i++)
                {
                    tmp.push_back(queue[size-1-i]->val);
                }
            }
            res.push_back(tmp);
            for (int i = 0; i < size; i++)
            {
                if (queue[0]->left != nullptr)
                    queue.push_back(queue[0]->left);

                if  (queue[0]->right != nullptr)
                    queue.push_back(queue[0]->right);

                queue.erase(queue.begin());
            }
            flag = ! flag;
        }
        return res;
    }
};