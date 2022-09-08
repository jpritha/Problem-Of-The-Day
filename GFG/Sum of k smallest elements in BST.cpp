// Link: https://practice.geeksforgeeks.org/problems/sum-of-k-smallest-elements-in-bst3029/1

/*
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
void inorder(Node* root, int& k, int& sum) {
    if(!root) return ;
    
    inorder(root->left, k, sum);
    
    if(k != 0) {
        sum += root->data;
        k--;
    }

    inorder(root->right, k, sum);
}
// Function to find ceil of a given input in BST. If input is more 
// than the max key in BST, return -1 
int sum(Node* root, int k) 
{ 
  
    int sum = 0;
    inorder(root, k, sum);
    
    return sum;
}