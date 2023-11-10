#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;
vector<list<int>> graph;
unordered_set<int> visited;

void add_edge(int source, int destination, bool undir = true) {
    graph[source].push_back(destination);

    if(undir) {
        graph[destination].push_back(source);
    }
}

void display() {
    for(int i = 0;i < graph.size();i++) {
        cout << i << " -> ";
        for(auto element : graph[i]) {
            cout << element << " ";
        }
        cout << endl;
    }
}

bool depthFirstSearch(int source, int destination) {
    
    if(source == destination) return true;
    visited.insert(source);

    for(auto neighbour : graph[source]) {
        if(not visited.count(neighbour)) {
            bool result = depthFirstSearch(neighbour, destination);
            if(result) return true;
        }
    }

    return false;
}

bool anyPath(int source, int destination) {
    return depthFirstSearch(source, destination);
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    graph.resize(vertices+1, list<int> ());
    while(edges--) {
        int source, destination;
        cin >> source >> destination;
        add_edge(source, destination);
    }

    cout << "Enter source and destination vertex to check for :" << endl;
    int source, destination;
    cin >> source >> destination;

    if(anyPath(source, destination)) {
        cout << "Path Exists! " << endl;
    }
    else {
        cout << "Path does not Exists! " << endl;
    }

    return 0;
    
}
