// Link : https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1


/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/
                            //TWO POINTERS
class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>> ans;
        
        
        Node* curr = head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        Node* start = head; 
        Node* last = curr;
        
        while(start->data < last->data) {
            int sum = start->data + last->data;
            
            if(sum > target) {
                last = last->prev;
            }
            else if(sum < target) {
                start = start->next;
            }
            else {
                ans.push_back({start->data, last->data});
                start = start->next;
                last = last->prev;
            }
        }
        return ans;
    }
};

/*----------------------------------------------------------------------------------------------
                                BRUTE FORCE
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>> ans;
        
        unordered_map<int, int> mp;
        
        Node* curr = head;
        while(curr) {
            if(mp.find(target-curr->data) != mp.end()) {
                ans.push_back({target-curr->data, curr->data});
            }
            
            mp[curr->data] = curr->data;
            
            curr = curr->next;
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
*/