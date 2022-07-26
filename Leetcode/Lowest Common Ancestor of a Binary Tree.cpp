// Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
//Video : https://www.youtube.com/watch?v=_-QHfMDde90&ab_channel=takeUforward

class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        if(root == p || root == q) {
            return root;
        }
        
        TreeNode* leftChild = dfs(root->left, p, q);
        TreeNode* rightChild = dfs(root->right, p, q);
        
        //If both the given nodes are a child of root, then only return root
        if(leftChild != NULL && rightChild != NULL) {
            return root;
        }
        else if(!leftChild && !rightChild) { 
            return NULL;
        }
        else {
            return leftChild != NULL? leftChild : rightChild;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};


/*-----------------------------------------------------------------------------------
Whenever we get a p or q, return the root right there, no need to go beyond and search.

1.If both leftChild and rightChild is not NULL , then its root is the Common Ancestor
2.If any path does not contain p or q , it should not be considered and hence returns NULL.
3.Hence if one child is Null and one is not NUll, we should return the child that is not NUll .
-------------------------------------------------------------------------------------
*/
