
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool result = false;
        DFS(root, 0, targetSum, result);
        return result;
    }

    void DFS(TreeNode* p, int now_sum, int targetSum, bool &result)
    {
        if (p != nullptr)
        {
            if (now_sum +  p->val == targetSum && p->left == nullptr && p->right == nullptr)
                result = true;
            DFS(p->left, now_sum+p->val,targetSum,result);
            DFS(p->right, now_sum+p->val,targetSum,result);
        }
    }
};