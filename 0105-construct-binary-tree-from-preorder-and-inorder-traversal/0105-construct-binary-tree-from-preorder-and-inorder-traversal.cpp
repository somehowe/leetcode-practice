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
    // inRight is the farthest that we can go
    TreeNode *helper(int preStart, int inLeft, int inRight, vector<int>& preorder, vector<int>& inorder) {
        if (inLeft > inRight) return nullptr;
        // we have at least one to make
        TreeNode *head = new TreeNode(preorder[preStart]);
        // we need to find the divider for the left
        ++preStart; // we will always have to move on to the next one
        int mid = inLeft;
        while (inorder[mid] != head->val) ++mid; // we could make this faster with a lookup table
        int leftSize = mid - inLeft;
        head->left = helper(preStart, inLeft, mid - 1, preorder, inorder);
        head->right = helper(preStart + leftSize, mid + 1, inRight, preorder, inorder);
        return head;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // need quick lookups of where index are
        return helper(0, 0, preorder.size() - 1, preorder, inorder);
    }
};