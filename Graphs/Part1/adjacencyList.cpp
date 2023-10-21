#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<list <int>> graph;
int v;

// function to add the edge
void add_edge(int src, int dest, bool dir = true) {
    graph[src].push_back(dest);

    // in case of undirected push the other side also add the
    if(dir) {
        graph[dest].push_back(src);
    }
}

// display function
void display() {
    for(int i = 0;i < graph.size();i++) {
        cout << i << " -> ";
        for(auto element : graph[i]) {
            cout << element << " ";
        }
        cout << endl;
    }
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

    display();

    return 0;
}