#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity:-  O(n*m^2) 
Space Complexity:- O(n*m)
*/

class Trie;

class TrieNode
{

private:
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    // Constructor
    TrieNode(char data)
    {
        this->data = data;
        isTerminal = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
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

public:
    // Constructor.
    Trie(char ch)
    {
        // allocate memory of root node.
        root = new TrieNode(ch);
    }
    // Methods,

    /* Method to insert word in a Trie. */
    void insertWord(string word)
    {
        // function call to insert word(character by character) in a Trie.
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
    {
        // Base Case
        if (curr->isTerminal == true)
        {
            temp.push_back(prefix);
        }

        // Recursive case
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];
            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);

                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++)
        {
            char lastChar = str[i];

            prefix.push_back(lastChar);

            // check if last character is present or not.
            TrieNode *curr = prev->children[lastChar - 'a'];

            // if not present break the loop.
            if (curr == NULL)
            {
                break;
            }

            // if present, traverse the entire trie (from current Node) and store all words.
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }

        return output;
    }
};
vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    // creation for trie
    Trie *t = new Trie('\0');

    // insert all contacts into trie.
    for (int i = 0; i < contactList.size(); i++)
    {
        t->insertWord(contactList[i]);
    }

    // return ans
    return t->getSuggestions(queryStr);
}


int main()
{
}