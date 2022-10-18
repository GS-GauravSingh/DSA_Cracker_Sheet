// Time Complexity:- O(m+n), m and n are size of both linked lists.
// Space Complexity:- O(1)


const int mod = 1e9+7;

long long  multiplyTwoLists (Node* l1, Node* l2)
{
    // initializing variable to store integers from linked lists
    long long num1 = 0, num2 = 0;
    
    // Extracting 1st numbers from Linked list
    while(l1 != NULL){
        num1 = ((num1 * 10) + l1-> data) % mod;
        l1 = l1 -> next;
    }
    
    // Extracting 2nd numbers from Linked list
    while(l2 != NULL){
        num2 = ((num2 * 10) + l2-> data) % mod;
        l2 = l2 -> next;
    }
    
    // calculating ans
    long long ans = ((num1 % mod) * (num2 % mod)) % mod;
    
    // return ans
    return ans;
}