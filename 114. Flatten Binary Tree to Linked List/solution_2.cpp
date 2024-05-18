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
    TreeNode * pre = nullptr;
public:
    void flatten(TreeNode* root) {
        // 根据先根遍历的性质，在遍历完上一个结点后，其left指针不会使用；
        // 则可以根据这条性质，先用left指针连接链表，然后再进行一轮循环去调整指针。
        flattenHelper(root);
        reverseTree(root);
    }
    void flattenHelper(TreeNode* root)
    {
        if (root != nullptr)
        {
            if (pre != nullptr)
            {
                pre->left = root;
                pre = pre ->left;
            }
            else
            {
                pre = root;
            }
            flattenHelper(root->left);
            flattenHelper(root->right);
        }
    }
    void reverseTree(TreeNode * root)
    {
        while (root != nullptr)
        {
            root->right = root->left;
            root->left = nullptr;
            root = root->right;
        }
    }
};