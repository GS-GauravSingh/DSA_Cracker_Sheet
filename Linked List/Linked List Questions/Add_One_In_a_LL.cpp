#include <bits/stdc++.h>
using namespace std;

// Ques:- A number N is represented in Linked List such that each digit corresponds to a node in linked list.
// You need to add 1 to it.

class Solution
{

// Time Complexity:- O(n)
// Space Complexity:- O(1)

private:
    //----- Reverse Function -------
    Node *reverse(Node *head)
    {
        Node *currNode = head;
        Node *prevNode = NULL;
        Node *nextNode = NULL;

        while (currNode != NULL)
        {
            nextNode = currNode->next;
            currNode->next = prevNode;

            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }
    //-------------------------------

    //------- Function to add one in a Linked List-----------
    Node *add_One_In_LL(Node *head)
    {
        // 4->5->6
        // we already reversed the LL.
        // We got, 6->5->4
        // and we have to add 1 to it.
        // add 1 to value at first node and break the loop, 7->5->4 done.

        // Case 1:
        // if value at first node in not 9 then,
        // add 1 to value at first node and break the loop our ans is ready.

        // Case 2: if value at first node or any other node = 9,
        //  but a single node is present with value < 9 then,
        //  jis node pe value 9 is usko 0 krdo or uske aage vali node pe 1 add krdo
        //  ex1. 1->9, reverse => 9->1 ==> jis node pe 9 hai usko 0 krdo or aage wali node pe 1 add krdo.
        //  it will become ==>  0->2 =>reverse ==> 2->0, 19+1 = 20

        // ex2. 1->9->9 reverse ==> 9->9->1 ==> 0->0->2 =>reverse ==> 2->0->0
        //  199+1 = 200;

        // Case 3: if all values are 9
        // ex 9, 99, 999, 9999, etc.
        // to check this case, we havt tp put a conditiond i.e.,
        //  if curr->data = 9 and curr->next == NULL;
        //  agar program is condition me aaya iska matlab saare 9 present hai LL me.
        //  is case me last node ki value 1 krdo,
        //  ek extra node bnao with data 0 or is node ko head se point krka ke head bna do.
        //  ex 9 =>reverse ==> 9 => 0->1
        //  ex 99 ==> 9->9 ==> 0->0->1

        Node *currNode = head;
        while (currNode != NULL)
        {

            if (currNode->next == NULL && currNode->data == 9)
            {
                // is condition me jab aap aaoge tab aap last node pe hi hoge.

                // create a new node
                Node *newNode = new Node(0);

                // point it to head
                newNode->next = head;

                // make newNode as your new Head.
                head = newNode;

                // set value at last node = 1
                currNode->data = 1;

                // move pointer
                currNode = currNode->next;
            }

            else if (currNode->data == 9)
            {
                // if value at first node or any other node = 9
                // set it to 0.
                currNode->data = 0;

                // move pointer
                currNode = currNode->next;
            }
            else
            {
                // ye vo case hai jha pe aapko ek aise value mili hai,
                // jo < 9 hai.

                // increment it and break the loop.
                currNode->data = currNode->data + 1;
                break;
            }
        }

        return head;
    }

//-------------------------------------------------------


public:
    Node *addOne(Node *head)
    {

        // Step 1: reverse linked list (because we perform addition from right).
        head = reverse(head);

        // Step 2: perform addition from left (because LL is reversed).
        Node *ans = add_One_In_LL(head);

        // Step 3: reverse ans LL and return.
        //  ex = 4->5->6, after reverse it will become 6->5->4
        //  and after adding one it will become 7->5->4
        //  for ans you have to reverse the linked list one more time
        //  and it will become 4->5->7.

        ans = reverse(ans);
        return ans;
    }
};
