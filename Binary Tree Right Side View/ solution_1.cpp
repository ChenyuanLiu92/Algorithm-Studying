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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        vector<TreeNode *> queue;
        // BFS
        if (root != nullptr)
        {
            queue.push_back(root);
        }
        while (queue.size() != 0)
        {
            int size = queue.size();
            // 每次都将队尾（最右边的元素）的元素的值加入res
            res.push_back(queue[size-1]->val);
            // 清空队列，并将各自的子结点入队
            for (int i = 0; i < size; i++)
            {
                if (queue[0]->left != nullptr)
                    queue.push_back(queue[0]->left);
                if (queue[0]->right != nullptr)
                    queue.push_back(queue[0]->right);
                queue.erase(queue.begin());
            }
        }
        return res;
    }
};