// Link : https://leetcode.com/problems/validate-binary-search-tree/

/*struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };*/

class Solution {
public:
    bool isWithinRange(TreeNode* root, long mini, long maxi) {
        if(!root) return true;
        
        if(root->val >= maxi || root->val <= mini) {
            return false;
        }
        // else return true; Don't do this as if true, we need to check till leaf    
        
        bool left_child = isWithinRange(root->left, mini, root->val);
        bool right_child = isWithinRange(root->right, root->val, maxi);
        
        return left_child && right_child;
    }
    bool isValidBST(TreeNode* root) {
        
        return isWithinRange(root, LONG_MIN, LONG_MAX);
    }
};


/* 2 nd method ------------------------------------------------------------------------------------------------
                                                BOTTOM TO TOP 

class Solution {
private:
    void inorder(TreeNode* root, TreeNode*& prev, bool& flag) {
        if(!root) return;
        
        inorder(root->left, prev, flag);
        
        if(prev != NULL && (root->val <= prev->val)) {
            flag = false;
            return;
        }  
        prev = root;
        
        inorder(root->right, prev, flag);
    }
    
public:     
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        TreeNode * prev = NULL;
        
        inorder(root, prev, flag);
        
        return flag;
    }
};
-----------------------------------------------------------------------------------------------------------------
*/