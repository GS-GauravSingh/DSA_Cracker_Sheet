#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
private:
    int adjMatix[26][26] = {0};

public:
    /* Methods. */
    /* Method to add edge in a graph. */
    void add_edge(T u, T v, bool undirected = true)
    {
        // in undirected graph, edge can be from u to v and v to u.
        // in directed graph, edge is from u to v.

        // if u and v is character.
        if (u >= 'a' && u <= 'z')
        {
            adjMatix[u - 'a'][v - 'a'] = 1;
            if (undirected)
            {
                adjMatix[v - 'a'][u - 'a'] = 1;
            }
        }
        else
        {
            // if u and v is integer.
            adjMatix[u][v] = 1;
            if (undirected)
            {
                adjMatix[v][u] = 1;
            }
        }
    }

    /* Method to display Adjacency Matrix. */
    void display(int numberOfNodes)
    {
        for (int i = 0; i < numberOfNodes; i++)
        {
            for (int j = 0; j < numberOfNodes; j++)
            {
                cout << adjMatix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};