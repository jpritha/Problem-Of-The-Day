// Link : https://leetcode.com/problems/binary-tree-pruning/

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
        
        // Go to the bottom of the tree first.
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        
        // We only trim if the node's value is 0 and it doesn't have kids
        if(!root->left && !root->right && root->val == 0) return NULL;
        
        return root;                //Otherwise we leave the node the way it is
    }
};