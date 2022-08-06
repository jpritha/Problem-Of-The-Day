// Link : https://practice.geeksforgeeks.org/problems/quicksort-on-doubly-linked-list/1

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
  
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

struct Node *lastNode(Node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}

void swap(int* a, int* b )
{   
    int t = *a;
    *a = *b;
    *b = t;
}
/********************************MAIN************************************************************************/
class Solution{
public:
    Node* partition(Node *first, Node *last){
        Node* i = first;
        while(first != last) {
            if(first->data <= last->data) {
                swap(i->data, first->data);
                i = i->next;
            }
            first = first->next;
        }
        swap(i->data, last->data);
        return i;
    }
};
/********************************MAIN***********************************************************************/

void _quickSort(struct Node* first, struct Node *last)
{
    if (last != NULL && first != last && first != last->next)
    {
        Solution ob;
        struct Node *p = ob.partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}

void quickSort(struct Node *head)
{
    // Find last Node
    struct Node *h = lastNode(head);
 
    // Call the recursive QuickSort
    _quickSort(head, h);
}

// A utility function to print contents of linkedlist
void printList(struct Node *head)
{
    while (head)
    {
        cout << head->data << "  ";
        head = head->next;
    }
    cout << endl;
}

/* Driver program to test above function */
int main() {
    int n;
    cin>>n;
    int x;
    cin>>x;
    struct Node* head = new Node(x);
    struct Node* p = head, *temp = NULL;
    for(int i=0; i<n-1; i++) {
        cin>>x;
        temp = new Node(x);
        p->next = temp;
        temp->prev = p;
        p = p->next;
    }
	
    quickSort(head);
   
    printList(head);     

    /* delete Nodes from the doubly linked list */   
    /* Modified linked list will be NULL<-8->NULL */  
    while(head->next!=NULL)
    {
	  temp = head;
	  head = head->next;
	  free(temp);
	}
	  free(head);
	}
    return 0;
}