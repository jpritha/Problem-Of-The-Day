// Link : https://practice.geeksforgeeks.org/problems/game-with-nos3123/1

int* game_with_number(int arr[], int n)
{
    
    for(int i=0; i<n-1; i++) {
        arr[i] = arr[i] ^ arr[i+1];
    }
    
    return arr;
}