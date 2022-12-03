/*
Depth First Search (DFS),

Example:- DFS means process current node and then adjacent nodes (if a node has multiple adjacent nodes the go in one direction).

Ex1:- Graph,
        0 -- 2 -- 1
             |    |
             4 -- 3

DFS:- 0, 2, 1, 3, 4

Time Complexity:- O(n)
Space Complexity:- O(n)
*/
#include <bits/stdc++.h>
using namespace std;

void DFS(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList, vector<int> &ans)
{
        // push current node in answer and mark as visited.
        ans.push_back(node);
        visited[node] = true;

        // make a recursive call for all adjacent node, if not visited.
        for (auto i : adjList[node])
        {
                if (!visited[i])
                {
                        DFS(i, visited, adjList, ans);
                }
        }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
        // prepare adjacency list.
        unordered_map<int, list<int>> adjList;
        for (int i = 0; i < edges.size(); i++)
        {
                int u = edges[i][0];
                int v = edges[i][1];

                // given graph is undirected.
                adjList[u].push_back(v);
                adjList[v].push_back(u);
        }

        // vector to store DFS.
        vector<vector<int>> ans;

        // map to store if element/node is visited or not.
        unordered_map<int, bool> visited;

        // given graph is undirected and disconnected, so traverse all the vertex.
        for (int i = 0; i < V; i++)
        {
                if (!visited[i])
                {
                        vector<int> temp;
                        DFS(i, visited, adjList, temp);
                        ans.push_back(temp);
                }
        }
        return ans;
}


int main()
{       
        int vertex = 5;
        int e = 4;

        vector<vector<int>> edges = {
                {0,2},
                {0,1},
                {1,2},
                {3,4},
        };

        vector<vector<int>> ans = depthFirstSearch(vertex, e, edges);
        for (auto row: ans)
        {
                for(auto col:row){
                        cout<<col<<" ";
                }
                cout<<endl;
        }
        

}