// Link : https://leetcode.com/problems/n-ary-tree-level-order-traversal/

/*class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};*/
                                        // BFS
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        
        vector<vector<int>> ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> currlevel;
            
            for(int i=0; i<size; i++) {
                Node* node = q.front();
                q.pop();
                
                currlevel.push_back(node->val);
                for(auto n : node->children) {
                    q.push(n);
                }
            }
            ans.push_back(currlevel);
        }
        
        return ans;
    }
};