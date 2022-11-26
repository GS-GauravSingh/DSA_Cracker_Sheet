/*
HashTable Implementation:- We're going to use a table array to implement HashTable. And we're using Seperate chaining for Collision Handling.

*/

#include <bits/stdc++.h>
using namespace std;

/*
Our Table array will store value in the form of Linked list and if collision happen we extend that list.
So, our table array is a collection of pointers.
tableArray = {Node*, Node* , Node*, Node*, - - - - so on.};
*/
template <typename T>
class Node
{
public:
    string key;
    T value;
    Node<T> *next;

    // Constructor.
    Node(string key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    // Destructor.
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

/* HashTable Class */
template <typename T>
class HashTable
{
private:
    Node<T> **table; // because our hashtable can grow in size, so we have to create dynamic array.
    int cs;          // total entries that already inserted in our hashtable.
    int ts;          // size of table.

    /* HashFunction (convert string key to int) */
    int hashFn(string key)
    {
        int idx = 0;
        int power = 1;
        // just trying any random method to generate index.
        for (auto ch : key)
        {
            idx = (idx + ch * power) % ts; // % to avoid overflow, index must be in the range of 0 to tablesize - 1.
            power = (power * 29) % ts;
        }

        return idx;
    }

    /*
    ReHashing :- It is a technique that dynamically expands the size of the HashTable.

    This is the worst case of Insertion:- TC:- O(n)
    */
    void reHash()
    {
        // cout<<"In ReHash method.\n";

        // Step 1:- save the pointer of old table and make insertion oin the new table.
        Node<T> **oldTable = table;

        // Step 2:- setup new table size.
        cs = 0; // on new table there is no key,value pair.
        int oldTs = ts;
        ts = 2 * ts + 1;

        // Step 3:- allocate the memory of new Table.
        table = new Node<T> *[ts];

        // Step 4:- copy data from oldtable to newtable.
        // Step 4.1:- first initialize new table.
        for (int i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }

        // Step 4.2:- copy elements from old table to new table..
        for (int i = 0; i < oldTs; i++)
        {
            Node<T> *temp = oldTable[i];

            while (temp != NULL)
            {
                string key = temp->key;
                T value = temp->value;

                // this insertion happen in a new table.
                insert(key, value);

                temp = temp->next;
            }

            // destroy the entire ith linked list.
            if (oldTable[i] != NULL)
            {
                delete oldTable[i];
            }
        }

        // Now, delete entire oldTable.
        delete[] oldTable;
    }

public:
    // Constructor.

    // table size is good if it is a prime number.
    HashTable(int default_size = 7)
    {
        cs = 0;            // initially there is no key,value pair inseted.
        ts = default_size; // setting up default size.

        // allocate array.
        // Node<T>* arr = new Node<T>[ts];
        // table = arr;

        table = new Node<T> *[ts];

        // initialize table.
        for (int i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }
    }

    // method to insert key,value pair (where key is of type string).
    // Time Complexity:- O(1), in worst Case O(n).
    void insert(string key, T value)
    {
        // Step 1:- give the key to HashFunction, so it will return the index to insert it's value.
        int idx = hashFn(key);

        // Step 2:- create a new Node to insert at index return by HashFunction.
        Node<T> *newNode = new Node<T>(key, value);

        // Step 3:- insert (insert at head) new node at index.
        // we're inserting at head because we have to make this operation in O(1) time.

        // newNode -> next = table[idx];
        // table[idx] = newNode;

        Node<T> *&head = table[idx];
        newNode->next = head;
        head = newNode;

        cs++; // increment the count of key,value pair.

        // setting the limit (to expand our table arr) for insertion
        float loadFactor = cs / float(ts);
        if (loadFactor > 0.7)
        {
            reHash();
        }
    }

    /*
    Method to Search in for a key HashTable.
    if(key,value) pair existsm we return the address of the object,
    else we return NULL.
    */

    bool isPresent(string key)
    {
        // Step 1:- find index of key.
        int idx = hashFn(key);

        // Step 2:- on that index find the key.
        Node<T> *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return true;
            }
            temp = temp->next;
        }

        return false;
    }

    T *search(string key)
    {

        if (isPresent(key) == true)
        {
            // Step 1:- find index of key.
            int idx = hashFn(key);

            // Step 2:- on that index find the key.
            Node<T> *temp = table[idx];
            while (temp != NULL)
            {
                if (temp->key == key)
                {
                    return &temp->value; // return the address of the value.
                }
                temp = temp->next;
            }
        }
        else
        {
            // if key, value pair doesn't exists return NULL.
            return NULL;
        }
    }

    /* Method to erase a particular entry from HashTable. */
    void erase(string key)
    {
        // Step 1:- find index of key.
        int idx = hashFn(key);
        // cout<<idx<<endl;

        // Step 2:- on that index find the key and erase it.
        Node<T> *temp = table[idx];
        // cout<<temp->key;
        Node<T> *prev = NULL;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                // it means the key is present at head.
                if (prev == NULL)
                {
                    Node<T> *del = temp;
                    if (temp->next == NULL)
                    {

                        table[idx] = NULL;
                        return;
                    }
                    temp = temp->next;
                    del->next = NULL;
                    delete del;
                }

                prev->next = temp->next;
                if (temp->next != NULL)
                {
                    temp->next = NULL;
                }
                delete temp;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
    }




    /* Method to print HashTable. */
    void print()
    {
        for (int i = 0; i < ts; i++)
        {
            cout << "Bucket " << i << ",\n";
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << "->";
                cout << temp->value;
                cout << endl;
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
