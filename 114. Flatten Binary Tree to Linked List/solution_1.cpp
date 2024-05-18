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
    void flatten(TreeNode* root) {
        // 在二叉树的先根遍历基础上，用一个队列保存遍历结果，然后进行连接
        vector<TreeNode *> q;
        flattenHelper(root, q);

        // 头结点方便调整
        TreeNode * head = new TreeNode(0);

        // 遍历队列，调整结点关系
        for (int i = 0;i < q.size(); i++)
        {
            head->left = nullptr;
            head->right = q[i];
            head = head->right;
        }
        head->left = nullptr;
        head->right = nullptr;

    }

    // 先根遍历，然后将结果入队列
    void flattenHelper(TreeNode* root, vector<TreeNode*> & q)
    {
        if (root != nullptr)
        {
            q.push_back(root);
            flattenHelper(root->left, q);
            flattenHelper(root->right, q);
        }
    }
};