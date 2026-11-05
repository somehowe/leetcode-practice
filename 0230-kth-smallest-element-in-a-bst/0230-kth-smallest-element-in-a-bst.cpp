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
        // if BST is modified often and we need to find the kth smallest frequently
        //   well augmenting it with how many values are on the left of it may not be great
        //   because then we would have to go through and update all of these each times
        //   well inserting and delete are alreda log(n) operations so then we could go back up and update
        //   so we would't have to explore useless branches, instead of O(n) search like we are doing now
        //   we could make this a log(n) serach as well
    }
};