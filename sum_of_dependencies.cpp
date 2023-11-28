#include <iostream>
#include <vector>
using namespace std;

int sumOfDependencies(vector<int> adj[], int V) {
    int sum = 0;

    for (int i = 0; i < V; ++i) {
        sum += adj[i].size();
    }

    return sum;
}

int main() {
    int V = 4;
    int E = 4;
    vector<int> adj[V];

    // Example graph
    int Edges[][2] = {{0, 2}, {0, 3}, {1, 3}, {2, 3}};

    for (int i = 0; i < E; ++i) {
        int a = Edges[i][0];
        int b = Edges[i][1];
        adj[a].push_back(b);
    }

    int result = sumOfDependencies(adj, V);
    cout << "Sum of Dependencies: " << result << endl;

    return 0;
}
