// Link : https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1

/*
typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
*/

class Solution{
public:
    Node* BST(int& ind, int pre[], int mini, int maxi, int& n) {
        if(ind >= n) return NULL;
        
        if(pre[ind] < mini || pre[ind] > maxi) return NULL;
        
        Node* root = newNode(pre[ind++]);
        
        root->left = BST(ind, pre, mini, root->data, n);
        root->right = BST(ind, pre, root->data, maxi, n);
        
        return root;
    }
    //Function that constructs BST from its preorder traversal.
    Node* post_order(int pre[], int size)
    {
        int ind = 0;
        
        return BST(ind, pre, 0, INT_MAX, size);
    }
};

//Since this ind is going over array hence int& ind and newNode[pre[ind++]], its because we never have to go back to previous index.
//We could also use a loop through the array in the main function.
