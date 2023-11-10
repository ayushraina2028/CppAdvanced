#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<list<pair<int, int>>> graph;

void add_edge(int source, int destination, int weight, bool dir = true) {
    graph[source].push_back({destination, weight});

    if(dir) {
        graph[destination].push_back({source, weight});
    }
}

void display() {
    for(int i = 0;i < graph.size(); i++) {
        for(auto pair : graph[i]) {
            cout << "(" << i << " -> " << pair.first  << ") : " << pair.second << "   "; 
        }
        cout << endl;
    }
}

int main() {
    int vertices;
    int edges;
    cin >> vertices >> edges;

    graph.resize(vertices+1, list<pair<int, int>> ());

    while(edges--) {
        int source, destination, weight;
        cin >> source >> destination >> weight;

        add_edge(source, destination, weight);
    }

    display();
    return 0;
}