#include <iostream>
#include <vector>
#include <list>
#define pp pair<int, int>
#include <queue>
#include <climits>
#include <string>
using namespace std;

// adjacency list
vector<list<pp>> graph;

void add_edge(int source, int destination, int weight, bool undir = true) {
    graph[source].push_back({destination, weight});

    if(undir) {
        graph[destination].push_back({source, weight});
    }
}

vector<int> dijkstra(int source) {
    priority_queue<pp, vector<pp>, greater<pp>> pqueue;
    vector<int> shortestPaths(graph.size(),INT_MAX);

    shortestPaths[source] = 0;
    pqueue.push({shortestPaths[source], source});

    while(!pqueue.empty()) {
        pp top = pqueue.top();
        int dist = top.first;
        int node = top.second;

        pqueue.pop();
        for(auto neighbour : graph[node]) {
            if(dist + neighbour.second < shortestPaths[neighbour.first]) {
                shortestPaths[neighbour.first] = dist + neighbour.second;
                pqueue.push({shortestPaths[neighbour.first], neighbour.first});
            }
        }
    }

    return shortestPaths;
}

int main() {
    int vertices;
    int edges;
    
    // Please enter vertices starting from 0 onwards
    cin >> vertices >> edges;

    graph.resize(vertices+1, list<pair<int, int>> ());

    while(edges--) {
    
        int source, destination, weight;
        cin >> source >> destination >> weight;

        add_edge(source, destination, weight);
    }

    cout << "Enter Source Vertex: ";
    int source;
    cin >> source;

    vector<int> shortestPath = dijkstra(source);
    for(int x : shortestPath) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}
