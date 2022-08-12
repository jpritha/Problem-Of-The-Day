// Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/


/*struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };*/

class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        if(p->val < root->val && q->val < root->val) {
            return dfs(root->left, p, q);
        }
        else if(p->val > root->val && q->val > root->val) {
            return dfs(root->right, p, q);
        }
        return root;             // for else cases
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};


        /*Iterative
        
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small = min(p->val, q->val);
        int large = max(p->val, q->val);
        while (root != nullptr) {
            if (root->val > large)      // p, q belong to the left subtree
                root = root->left;
            else if (root->val < small) // p, q belong to the right subtree
                root = root->right;
            else {                   // Now, small <= root.val <= large -> This root                                          is the LCA between p and q
                return root;
            }
        }
        return nullptr;
    }
};
*/
