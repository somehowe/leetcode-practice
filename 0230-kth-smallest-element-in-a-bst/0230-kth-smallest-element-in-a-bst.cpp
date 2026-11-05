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
    TreeNode *search(TreeNode *root, int &k) {
        if (root->left) {
            TreeNode *left_res = search(root->left, k);
            if (left_res) return left_res; 
        }
        if (k == 1) return root;
        // not this node
        k -= 1;
        if (root->right) {
            TreeNode *right_res = search(root->right, k);
            if (right_res) return right_res;
        }
        return nullptr; // we couldn't find any
    }
    int kthSmallest(TreeNode* root, int k) {
        // get down to the bottom left one and search 
        // there will be at elast one node
        return search(root, k)->val;
    }
};