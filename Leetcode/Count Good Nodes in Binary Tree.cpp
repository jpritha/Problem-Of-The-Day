// Link : https://leetcode.com/problems/count-good-nodes-in-binary-tree/

/*struct TreeNode {
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
    void solve(TreeNode* root, int& cnt, int max_prev) {
        if(!root) return;
        
        if(root->val >= max_prev) {
            cnt++;
            max_prev = max(max_prev, root->val);
        }
        
        solve(root->left, cnt, max_prev);
        solve(root->right, cnt, max_prev);
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;                     
        
        int max_prev = root->val;
        
        solve(root, cnt, max_prev);
        
        return cnt;
    }
};