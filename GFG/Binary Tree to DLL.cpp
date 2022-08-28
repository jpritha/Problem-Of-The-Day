// Link : https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
                                    //    Binary Tree to DLL

/* Structure for tree and linked list
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
// This function should return head to the DLL
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        if(!root) return root;
        
        Node* head = bToDLL(root->left);
        if(head == NULL) {
            head = root;
            root->left = NULL;
        }
        else {
            Node* temp = head;
            while(temp->right != NULL) {
                temp = temp->right;
            }
            temp->right = root;
            root->left = temp;
        }
        
        Node* tail = bToDLL(root->right);
        if(tail == NULL) {
            root->right = NULL;
        }
        else {
            tail->left = root;
            root->right = tail;
        }
        
        return head;
    }
};

/*                      2 nd method
class Solution {
    public:
                                    
    Node * bToDLL(Node *root) 
    {
        if(!root) return nullptr;     //or root
        
        Node* L = bToDLL(root->left);
        Node* R = bToDLL(root->right);
        
        root->right = R;      //Both if root is NULL or exists
        if(R) {
            R->left = root;
        }
        
        if(L) {
            Node* temp = L;
            while(temp->right != NULL)
                temp = temp->right;
            
            temp->right = root;
            root->left = temp;
            return L;
        }
        
        return root;
    }
}
*/