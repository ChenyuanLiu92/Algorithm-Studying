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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        vector<TreeNode *> queue;
        queue.push_back(root);

        while (queue.size()>0)
        {
            // 计算均值
            double sum = 0;
            for (int i = 0; i < queue.size(); i++)
                sum += queue[i]->val;

            double average = sum / queue.size();
            res.push_back(average);

            // 将这层的结点的子结点入队列
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                if (queue[0]->left != nullptr)
                {
                    queue.push_back(queue[0]->left);
                }

                if (queue[0]->right != nullptr)
                {
                    queue.push_back(queue[0]->right);
                }
                queue.erase(queue.begin());
            }
        }
        return res;
    }
};