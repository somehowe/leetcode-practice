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
    int helper(TreeNode *node, int maxSoFar) {
        if (!node) return 0;
        int newMax = max(maxSoFar, node->val);
        int count = helper(node->left, newMax) + helper(node->right, newMax);
        return count + (node->val >= maxSoFar);
    }
    int goodNodes(TreeNode* root) {
        return helper(root, root->val);
    }
};