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
    int helper(TreeNode *node, int root_val) {
        if (!node) return 0;
        int node_val = max(root_val, node->val);
        int count = helper(node->left, node_val) + helper(node->right, node_val);
        if (node->val >= root_val) return 1 + count;
        else return count;
    }
    int goodNodes(TreeNode* root) {
        return helper(root, root->val);
    }
};