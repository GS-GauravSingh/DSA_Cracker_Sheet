
#include <bits/stdc++.h>
using namespace std;

// Time Complexity:- O(1)
// Space Complexity:- O(n)

class LRUCache
{
private:
    unordered_map<int, int> m;                       // map is used to store key, value pairs.
    unordered_map<int, list<int>::iterator> address; // this map is used to store address of DLL nodes corresponding to node value.
    list<int> l;                           // STL implementation of Doubly Linked List.
    // most recently used data is present at the head of DLL, and least recently used data is present at the tail of DLL.
    int cap;  // total capacity of cache.
    int size; // number of elements present in cache.

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        this->cap = cap;
        this->size = 0;
    }

    // Function to return value corresponding to the key.
    int get(int key)
    {
        if (m.find(key) == m.end())
        {
            // if key doesn't exist return -1.
            return -1;
        }
        // // if key is present return the value but Before returning the value, you have to make this value most recently used in DLL.
        // To make this value most recently used in DLL, we have to know in which node, this value is present.
        // Approach 1:- To find the node of this value, you need to taverse the DLL, which take O(n) Time in worst case.
        // Approach 2:- Is to used map and store tha address of each node corresponding to the key present at particular node.

        // Using Approach 2:-
        // As we're using STL implementation of DLL,
        auto it = address[key]; // got the iterator of the node (ye woh node hai jiski value hume return krni hai).
        // so we have to make this node most recently used in DLL.
        // To make this value most recently used in DLL, put this node at the head of DLL.
        // As we know Most Recently Used data is present at the head of DLL,
        // and Least Recently Used data is present at the tail of DLL.
        l.erase(it);        // deleting the node from its original position.
        address.erase(key); // deleting original address of node.

        l.push_front(key);        // making this node as Most recently used (Placed this node at head).
        address[key] = l.begin(); // storing the new address of node.

        // now you're free to retun the value.
        return m[key];
    }

    // Function for storing key-value pair.
    void set(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            // if key already exist, delete the key.
            // because key is present and it is storing some value corresponding to it,
            // and now we have to store a new value corresponding to this key.
            // So delete this key from everywhere.
            auto it = address[key]; // getting the node of this key from DLL.
            l.erase(it);            // deleting key from DLL.
            address.erase(key);     // deleting node for address map.
            m.erase(key);           // deleting key from our key, value map.
            // now we deleted this key from everywhere, so our size will be decreased by one.
            size--;
        }

        // if space is not present,
        if (size == cap)
        {
            // means, you need to delete least recently used data.
            // and least recently used data is present at tail of DLL.
            int key = l.back();
            l.pop_back();
            address.erase(key);
            m.erase(key);
            size--;
        }

        size++; // we are going to insert a key,value pair. So,our size will be increased.
        // but before incrementing the size, you need to check if there is space present for insertion,
        // if space is present insert the key, value pair.
        // if space is not present, in this case you need to delete least recently used data.

        // after deleting the key is exist is exist, or if we get the new key, value pair.
        // insert the key, value pair, and make this key, value pair Most Recently Used.
        l.push_front(key);        // making this key as most recently used.
        address[key] = l.begin(); // storing the address of this key.
        m[key] = value;           // storing the value corresponds to key.
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends