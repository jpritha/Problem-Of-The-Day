// Link : https://practice.geeksforgeeks.org/problems/next-right-node/1

/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    Node *nextRight(Node *root, int key)
    {
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i=0; i<size; i++) {
                Node* node = q.front();
                q.pop();
                
                if(node->data == key) {
                    if(i == size-1) {
                        return new Node(-1);
                    }
                    else {                      // i < size-1
                        return q.front();
                    }
                }
                
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
        }
        return new Node(-1);
    }
};