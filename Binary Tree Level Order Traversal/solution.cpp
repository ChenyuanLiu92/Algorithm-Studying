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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        vector<TreeNode *> queue;

        queue.push_back(root);

        while (queue.size() != 0)
        {
            int size = queue.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++)
            {
                tmp.push_back(queue[i]->val);
            }
            res.push_back(tmp);

            for (int i = 0; i < size; i++)
            {
                TreeNode * tmp = queue[0];
                if (tmp->left != nullptr)
                {
                    queue.push_back(tmp->left);
                }

                if (tmp->right != nullptr)
                {
                    queue.push_back(tmp->right);
                }
                queue.erase(queue.begin());
            }
        }

        return res;
    }
};