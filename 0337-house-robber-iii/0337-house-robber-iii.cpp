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
    // we will return with and w/out our current node
    // {best total when robbing this node, best total when skipping this node}
    pair<int, int> dfs(TreeNode *root) {
        if (!root) return {0, 0};
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        // we can go with either the first or the next one down
        int skip_node = max(left.first, left.second) + max(right.first, right.second);
        int keep_node = root->val + left.second + right.second;
        return {keep_node, skip_node};
    }
    int rob(TreeNode* root) {
        auto p = dfs(root);
        return max(p.first, p.second);
    }
};