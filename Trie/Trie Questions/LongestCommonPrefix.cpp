#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity:-  O(m*n)
Space Complexity:-  O(m*n)
*/

/// Trie implementation
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int childCount;

    // Constructor
    TrieNode(char data)
    {
        this->data = data;
        isTerminal = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
    }
};

class Trie
{
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
            root->childCount++;
            root->children[index] = child;
        }

        // make a recursiva call for rest of the characters.
        insertUtil(child, word.substr(1));
    }

public:
    TrieNode *root;

    // constructor
    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    /* Method to insert word in a Trie. */
    void insertWord(string word)
    {
        // function call to insert word(character by character) in a Trie.
        insertUtil(root, word);
    }

    // longest common prefix
    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (root->childCount == 1)
            {
                ans.push_back(ch);

                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
            {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *t = new Trie('\0');

    // step 1:- insert all string words into Trie.
    for (int i = 0; i < n; i++)
    {
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";
    t->lcp(first, ans);
    return ans;
}

int main()
{
}