// Link : https://practice.geeksforgeeks.org/problems/foldable-binary-tree/1

                                //Foldable Binary Tree
                            // -------------------------
/* A binary tree node has data, pointer to left child
and a pointer to right child */
/*struct node
{
    int data;
    struct node* left;
    struct node* right;
    
    node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

bool solve(Node* L, Node* R) {
    
    if(!L && !R) return true;        //If both of them are NULL, return true already
 
    if((!L && R) || (L && !R)) return false;
    
    //If both of them are not NULL , check further
    return solve(L->left, R->right) && solve(L->right , R->left);
    
}

//Function to check whether a binary tree is foldable or not.
bool IsFoldable(Node* root)
{
    if(!root) return true;
    
    return solve(root->left, root->right);
}