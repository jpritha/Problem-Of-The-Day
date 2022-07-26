// Link : https://practice.geeksforgeeks.org/problems/length-of-longest-palindrome-in-linked-list/1



/* The Node is defined 
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};*/

int count(Node * a, Node * b) {
    int cnt = 0;
    
    while(a != NULL && b != NULL) {
        
        if(a->data == b->data) {
            cnt++;
            a = a->next;        //that is its previous , since till prev it is already reversed
            b = b->next;        //that is to the forward of list
        }
        else {
            break;
        }
    }
    return cnt;
}

/*The function below returns an int denoting the length of the longest palindrome list. */
int maxPalindrome(Node *head)
{
    int maxLen = 0;
    Node * curr = head;
    Node * prev = NULL, *next = NULL;
    
    while(curr !=  NULL) {
        next = curr->next;
        curr->next = prev;          //We would have to reverse the ll till the prev to count
        
        //For EVEN Length Palindrome
        maxLen = max(maxLen , 2*count(curr,next));     

        //For ODD Length Palindrome
        maxLen = max(maxLen , 2*count(prev,next)+1);                

        
        prev = curr;
        curr = next;
    }
    return maxLen;
}