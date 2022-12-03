#include <bits/stdc++.h>
// #include "Graph_Implementation_Using_Adjacency_Matrix.h"
#include "Graph_Implementation_Using_Adjacency_Lists.h"
using namespace std;

int main(void)
{

    Graph<int> g;

    cout << "Enter number of nodes:- ";
    int nodes;
    cin >> nodes;

    g.add_edge(0, 4);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(1, 4);
    g.add_edge(1, 5);
    g.add_edge(2, 3);
    g.add_edge(2, 5);
    g.add_edge(5, 3);
    g.add_edge(5, 4);

    // g.display(nodes);
    g.display();
}