// Link : GFG:  https://practice.geeksforgeeks.org/problems/complete-binary-tree/1
//   Leetcode: https://leetcode.com/problems/check-completeness-of-a-binary-tree/


class GfG
{
    bool isCompleteBT(Node* root){
        queue<Node*> q;
        q.push(root);
        
        bool flag = true;
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i=0; i<size; i++) {
                Node * node = q.front();
                q.pop();
                
                if(node->left && !flag) return false;  //check for completion of previous level
                
                if(!node->left && node->right) return false;
                
                if(node->left) {
                    q.push(node->left);
                }
                if(node->left && node->right) {
                    q.push(node->right);
                }
                else if(!node->right) {          //If previous level is not completed 
                    flag = false;
                }
            }
        }
        return true;
    }
};


/*------------------------------------------------------------------------------------------------------------
Leetcode :

 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        bool flag = true;
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                //check for completion of previous level
                if(node->left && !flag) return false; 
                
                if(!node->left && node->right) return false;
                
                if(node->left) {
                    q.push(node->left);
                }
                if(node->left && node->right) {
                    q.push(node->right);
                }
                else if(!node->right) {      //If previous level is not completed 
                    flag = false;
                }
            }
        }
        return true;
    }
};
*/