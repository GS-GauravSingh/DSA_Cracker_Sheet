#include<bits/stdc++.h>
#include"Trie_Implementation.h"
using namespace std;

int main()
{
    Trie *t = new Trie();

    t->insertWord("abcd");
    cout<<"Present or Not "<<t->searchWord("abcd")<<endl;
    t->removeWord("abcd");
    cout<<"Present or Not "<<t->searchWord("abcd")<<endl;
}