#include <bits/stdc++.h>
using namespace std;

/*
                Time Complexity
Insertion:-         O(l), length of word.
Searching:-         O(l), length of word.
Deletion:-          O(l), length of word.
*/



/* Forward decleration of class trie. */
class Trie;

class TrieNode
{

private:
    char data;              // Each node has character type of data.
    TrieNode *children[26]; // characters are form A to Z, so each node has atmax 26 childrens.
    bool isTerminal;        // to track the last character of inserted word.
public:
    // Constructor
    TrieNode(char data)
    {
        this->data = data;
        isTerminal = false;
        // initially all child nodes are NULL.
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }

    friend class Trie;
};

class Trie
{
private:
    TrieNode *root;

    /* Recursive Method to insert word(char by char) into Trie. */
    void insertUtil(TrieNode *root, string word)
    {
        // Base Case
        if (word.length() == 0)
        {
            // if all character of a word inserted, set terminal node as true.
            root->isTerminal = true;
            return;
        }

        // Recursive Case

        // step 1:- find index, where you want to insert character in array.
        int index;
        if (word[0] >= 'A' && word[0] <= 'Z')
        {
            // if character is in uppercase.
            index = word[0] - 'A';
        }
        else
        {
            // if character is in lowercase.
            index = word[0] - 'a';
        }

        // step 2:- check if character is already present or not.
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            // if already present, then move ahead and search for next character in word.
            child = root->children[index];
        }
        else
        {
            // if not present, then create a node.
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // make a recursiva call for rest of the characters.
        insertUtil(child, word.substr(1));
    }

    /* Recursive Method to search word(char by char) in Trie. */
    bool searchUtil(TrieNode *root, string word)
    {
        // Base Case
        if (word.length() == 0)
        {
            // if last character is terminal node, it means word is present, else not.
            if (root->isTerminal == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        // Recursive Case,

        // Step 1:- find index of 1st character.
        int index;
        if (word[0] >= 'A' && word[0] <= 'Z')
        {
            // if character is in uppercase.
            index = word[0] - 'A';
        }
        else
        {
            // if character is in lowercase.
            index = word[0] - 'a';
        }

        // Step 2:- if character is present then search of next character.
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            // if character is present then search of next character.
            child = root->children[index];
        }
        else
        {
            // if not present return false.
            return false;
        }

        // make a recursive call for rest of the characters.
        return searchUtil(child, word.substr(1));
    }

    /* Recursive Method to remove word(char by char) from a Trie. */
    void removeUtil(TrieNode *root, string word)
    {
        // Base Case
        if (word.length() == 0)
        {
            // to remove a word, set its terminal node to false.
            root->isTerminal = false;
            return;
        }

        // Recursive Case,

        // Step 1:- find index of 1st character.
        int index;
        if (word[0] >= 'A' && word[0] <= 'Z')
        {
            // if character is in uppercase.
            index = word[0] - 'A';
        }
        else
        {
            // if character is in lowercase.
            index = word[0] - 'a';
        }

        // Step 2:- if character is present then search of next character.
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            // if character is present then search of next character.
            child = root->children[index];
        }

        // make a recursive call for rest of the characters.
        removeUtil(child, word.substr(1));
    }

public:
    // Constructor.
    Trie()
    {
        // allocate memory of root node.
        root = new TrieNode('\0');
    }
    // Methods,

    /* Method to insert word in a Trie. */
    void insertWord(string word)
    {
        // function call to insert word(character by character) in a Trie.
        insertUtil(root, word);
    }

    /* Method to search a word in a Trie. */
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    /* Method to remove a word form a Trie. */
    void removeWord(string word)
    {
        if(searchWord(word) == true){
            removeUtil(root, word);
            cout<<"Word Removed.\n";
        }
        else{
            cout<<word<<" is not present in the Trie, So. How can we remove it.\n";
        }
    }
};