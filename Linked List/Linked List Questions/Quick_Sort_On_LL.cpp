// Quick Sort.
//Time Complexity:- Best Case O(n log n) and in Worst Case O(n^2)
//Space Complexity:- O(log n)

node* partition(node* head, node* end){
    
    // setting pivot element as head
    node* pivot = head;
    
    // variable to traverse LL (starting from head->next because we choose head as our pivot element).
    node* curr = head -> next;
    
    while(curr != NULL){
        //ex 20->9->7->6->10
        //pivot = 20, curr points to 9
        
        // Note:- saara khel yahi hai,pivot ko uski sahi position me le jaane ke liye.
        // whenever you find value which is less or equal to (<=) than pivot, just swap it with pivot.
        // in above ex:- 
        // 9<20 swap(curr -> data, pivot -> data) ==> 9->20->7->6->10
        //pivot = 20, curr points to 7
        
        // 7<20 swap(curr -> data, pivot -> data) ==> 9->7->20->6->10
        //pivot = 20,  curr points to 6
        
        // 6<20 swap(curr -> data, pivot -> data) ==> 9->7->6->20->10
        //pivot = 20, curr points to 10
        
        // 10<20 swap(curr -> data, pivot -> data) ==> 9->7->6->10->20
        //pivot = 20, curr points to NULL
        
        // pivot placed to its correct position. 
        
        if(curr -> data <= pivot -> data){
            swap(curr -> data, pivot -> data);
        }
        curr = curr -> next;
    }
    return pivot;
}


void Quick_Sort(node* head, node* end = NULL){
    //Base case
    if(head == NULL || head -> next == NULL || head == end){
        return;
    }
    
    // Partition
    node* p = partition(head, end);
    
    // recursive call on left half
    Quick_Sort(head, p);
    
    // recursive call on left half
    Quick_Sort(p -> next, end);

}

void quickSort(struct node **headRef) {
    
    Quick_Sort(*headRef);
    
}