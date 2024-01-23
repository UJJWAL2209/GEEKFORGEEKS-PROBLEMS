#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<int> result;
    
    vector<vector<int>> graph(n);
    vector<int> inDegree(n, 0);
    
    // Build the graph and calculate in-degrees
    for (auto& prerequisite : prerequisites) {
        graph[prerequisite[1]].push_back(prerequisite[0]);
        inDegree[prerequisite[0]]++;
    }
    
    // Initialize a queue for BFS
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    // Perform BFS
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);
        
        for (int neighbor : graph[current]) {
            if (--inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    // Check if all tasks are visited
    if (result.size() != n) {
        return {}; // Empty array indicates it's impossible to finish all tasks
    }
    
    return result;
}

int main() {
    int n1 = 2, m1 = 1;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    
    vector<int> result1 = findOrder(n1, prerequisites1);
    if (result1.empty()) {
        cout << "No Ordering Possible" << endl;
    } else {
        cout << "Ordering: ";
        for (int task : result1) {
            cout << task << " ";
        }
        cout << endl;
    }
    
    int n2 = 4, m2 = 4;
    vector<vector<int>> prerequisites2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    
    vector<int> result2 = findOrder(n2, prerequisites2);
    if (result2.empty()) {
        cout << "No Ordering Possible" << endl;
    } else {
        cout << "Ordering: ";
        for (int task : result2) {
            cout << task << " ";
        }
        cout << endl;
    }

    return 0;
}
