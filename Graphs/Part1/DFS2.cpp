#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;
vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> answer;

void add_edge(int source, int destination, bool undir = true) {
    graph[source].push_back(destination);

    if(undir) {
        graph[destination].push_back(source);
    }
}

void depthFirstSearch(int source, int destination, vector<int>& path) {
    
    if(source == destination) {
        path.push_back(source);
        answer.push_back(path);
        path.pop_back();
    }

    visited.insert(source);
    path.push_back(source);

    for(auto neighbour : graph[source]) {
        if(not visited.count(neighbour)) {
            depthFirstSearch(neighbour, destination, path);
        }
    }

    path.pop_back();
    visited.erase(source);

    return;
}

void allPaths(int source, int destination) {
    vector<int> v;
    depthFirstSearch(source, destination, v);
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

    allPaths(source, destination);
    
    for(auto path : answer) {
        for(auto element : path) {
            cout << element << " ";
        }
        cout << endl;
    }

}