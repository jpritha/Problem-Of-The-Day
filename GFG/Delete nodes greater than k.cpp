// Link : https://practice.geeksforgeeks.org/problems/delete-nodes-greater-than-k/1

//The node structure
struct Node {
int data;
Node * right, * left;
};

class Solution{
  public:
    /*The function should return the root of the modified tree*/
    Node* deleteNode(Node* root, int k)
    {
        if(!root) return root;
        
        if(root->data >= k) {
            root->left = deleteNode(root->left, k);
            return root->left;
        }
        else {                  //root->data < k
            root->right = deleteNode(root->right, k);
            return root;
        }
    }
};