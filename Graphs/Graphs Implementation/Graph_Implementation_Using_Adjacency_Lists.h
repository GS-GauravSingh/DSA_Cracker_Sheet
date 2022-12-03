#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
private:
    unordered_map<T, list<T>> adjList;

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
            adjList[u].push_back(v);
            if (undirected)
            {
                adjList[v].push_back(u);
            }
        }
        else
        {
            // if u and v is integer.
            adjList[u].push_back(v);
            if (undirected)
            {
                adjList[v].push_back(u);
            }
        }
    }

    /* Method to display Adjacency List. */
    void display()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";

            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};