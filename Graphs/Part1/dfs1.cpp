#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;

vector<list <int>> graph;
unordered_set<int> visited;
int v;

// function to add the edge
void add_edge(int src, int dest, bool dir = true) {
    graph[src].push_back(dest);

    // in case of undirected push the other side also add the
    if(dir) {
        graph[dest].push_back(src);
    }
}

bool depthFirstSearch(int curr_source, int destination) {

    if(curr_source == destination) return true;
    visited.insert(curr_source);

    for(auto neighbour : graph[curr_source]) {

        if(not visited.count(neighbour)) {
            bool result = depthFirstSearch(neighbour, destination);
            if (result) return true;
        }

    }
    // if path was not found
    return false;
}

bool anyPath(int source, int destination) {
    return depthFirstSearch(source, destination);
}

int main() {
    
    cin >> v;
    graph.resize(v+1, list<int> ());
    int e;
    cin >> e;

    while(e--) {
        int s, d;
        cin >> s >> d;
        add_edge(s,d);
    }   

    cout << " Enter source and destination vertex " << endl;
    int src, dest;
    cin >> src >> dest;
    if(anyPath(src,dest)) {
        cout << "Path Exists" << endl;
    }
    else {
        cout << "Path does not exists" << endl;
    }

    return 0;
}