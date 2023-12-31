// This can be used to find shrortest paths in unweighted graph
// For weighte Graphs, more algorithms are there like Dijkstra's Algorithm.
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
#include <climits>
using namespace std;

// requirements
vector<list<int>> graph;
unordered_set<int> visited;

void add_edge(int source, int destination, bool undir = true) {
    graph[source].push_back(destination);

    if(undir) {
        graph[destination].push_back(source);
    }
}

void breadthFirstSearch(int source, vector<int>& distance) {
    
    queue<int> que;
    visited.clear();
    distance[source] = 0;
    visited.insert(source);
    que.push(source);

    while(!que.empty()) {
        int curr_source = que.front();
        que.pop();

        for(auto neighbour: graph[curr_source]) {
            if(not visited.count(neighbour)) {
                que.push(neighbour);
                visited.insert(neighbour);
                distance[neighbour] = distance[curr_source] + 1;
            }
        }
    }
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

    cout << "Enter source to start with :" << endl;
    int source;
    cin >> source;

    vector<int> distance;
    distance.resize(vertices+1, INT_MAX);
    breadthFirstSearch(source, distance);

    for(int i = 1;i < distance.size(); i++) {
        cout << distance[i] << " ";
    }
    cout << endl;
}