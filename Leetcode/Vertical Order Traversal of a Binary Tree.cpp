// Link : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Video : https://www.youtube.com/watch?v=q_a6lpbKJdw&ab_channel=takeUforward


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int ,  map<int , multiset<int>>> mp;
       //Vertical  //Level  //multiple nodes(same or different) in same level
        
        queue< pair<TreeNode* , pair<int , int>>> q;
               //Node         //Vertical  //Level
        
        q.push({root, {0, 0}});        //vertical 0 and level 0 on root
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            TreeNode * node = p.first;            
            int vertical = p.second.first ;     //Vertical
            int level = p.second.second;        //Level
                         
            mp[vertical][level].insert(node->val);
            
            if(node->left){
                q.push({node->left, {vertical-1, level+1}});
            }
            if(node->right){
                q.push({node->right, {vertical+1, level+1}});
            }
        }
        
        //Now Traverse through our Map and store in our ans vector<vector<int>> ans
        vector<vector<int>> ans;
        
        for(auto v : mp) {                  //v = vertical
            vector<int> col;
            
            for(auto level : v.second) {              
                col.insert(col.end(), level.second.begin(), level.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};