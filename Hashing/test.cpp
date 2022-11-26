#include <bits/stdc++.h>
#include "HashTable.h"
using namespace std;

int main()
{
    HashTable<int> h;

    // insert
    h.insert("Mango", 100);
    h.insert("Apple", 120);
    h.insert("Banana", 140);
    h.insert("Orange", 160);
    // h.insert("kiwi", 200);
    // h.insert("Papaya", 130);
    // h.insert("Litchi", 210);
    
    // Search
    string fruit;
    getline(cin, fruit);

    int *price = h.search(fruit);
    if(price != NULL){
        cout<<"Price of " << fruit <<" is "<<*price<<endl;
    }
    else{
        cout<<fruit<<" is not present."<<endl;

    }


    
}