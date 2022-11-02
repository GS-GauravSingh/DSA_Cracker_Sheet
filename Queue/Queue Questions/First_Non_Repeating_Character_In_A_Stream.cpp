/*

Input: A = "aabc"
Output: "a#bb"

Explanation: For every character first non
repeating character is as follow-

"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'


Approach :-

1st. we need a data structure to store the count of character.
2nd. we need a queue to check for non repeating character.
*/

#include <bits/stdc++.h>
using namespace std;

/* Function to find first non-repeating character.

Time Complexity:- O(26*n)
Space Complexity:- O(26)
*/
string FirstNonRepeating(string str)
{
    unordered_map<char, int> count;
    queue<char> q;
    string ans;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        // increment to count of ch.
        count[ch]++;

        // push ch into queue;
        q.push(ch);

        // find first non-repeating character from queue.
        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                // repeating character
                q.pop();
            }
            else
            {
                // non-repeating character
                ans.push_back(q.front());
                break;
            }
        }

        // if q is empty, then there is no non-repeating character
        if (q.empty())
        {
            ans.push_back('#');
        }
    }

    return ans;
}

int main(void)
{
    string str = "aabc";

    cout << "Answer => " << FirstNonRepeating(str) << endl;
}