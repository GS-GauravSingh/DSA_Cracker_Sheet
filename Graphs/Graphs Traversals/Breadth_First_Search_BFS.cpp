/*
Breadth-First Traversal (or Search) for a graph is similar to Breadth-First Traversal of a tree (Level Order Traversal).

The only catch here is, that, unlike trees, graphs may contain cycles, so we may come to the same node again. To avoid processing a node more than once, we divide the vertices into two categories:
1. Visited and
2. Not visited.

A boolean visited array is used to mark the visited vertices. For simplicity, it is assumed that all vertices are reachable from the starting vertex. BFS uses a queue data structure for traversal.


Algorithm:-

1. Declare a queue and insert the starting vertex.
2. Initialize a visited array or you can use map also and mark the starting vertex as visited.
3. Follow the below process till the queue becomes empty:
    3.1. Remove the first vertex of the queue.
    3.2. Mark that vertex as visited.
    3.3. Insert all the unvisited neighbours of the vertex into the queue.

Note:- if you want answer in sorted order use set instead of list while creating adjacency list.

Example:- BFS means proces current node and then print all adjacent nodes(but check is node is already printed or not).

Ex1:- Graph,
        0 -- 2 -- 1
             |    |
             4 -- 3

BFS => start from 0:- 0, 2, 4, 1, 3

Time Complexity:- O(v+e)
Space Complexity:- O(v+e)
*/

#include <bits/stdc++.h>
using namespace std;

/* Function to create Adjacency List. */
void createAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        // given graph is undirected and disconnected.
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

/* Breadth First Search (BFS) Code. */
void BreadthFirstSearch(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    
    queue<int> q;

    // push start node into queue.
    q.push(node);

    // mark this node as visited.
    visited[node] = true;


    while (!q.empty())
    {
        // extract frontnode from queue.
        int frontNode = q.front();

        // pop it.
        q.pop();

        // store frontnode in  answer.
        ans.push_back(frontNode);

        // push all adjacent nodes of frontnode into queue if it is not previously visited.
        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

/* Breadth First Search (BFS) Main Function. */
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> ans;                  // vector to store BFS Traversal.
    unordered_map<int, bool> visited; // map to check if element/Node is visited or not.

    // creating adjacency list.
    unordered_map<int, list<int>> adjList;
    createAdjList(adjList, edges);

    // given graph is disconnected so you need to traverse all the vertex.
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            BreadthFirstSearch(adjList, visited, ans, i);
        }
    }

    return ans;
}

/* Function to print vector. */
void printVec(vector<int> arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

int main()
{
    int vertex = 4;
    vector<pair<int, int>> edges = {
        {0,1},
        {0,3},
        {1,2},
        {2,3},
    };

    vector<int> ans = BFS(vertex, edges);
    printVec(ans);
}