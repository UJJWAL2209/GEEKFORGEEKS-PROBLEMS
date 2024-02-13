#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
};

class Solution {
public:
    Node* ansNode(Node* node, unordered_map<Node*, Node*>& visited) {
        if (!node) return nullptr;
        if (visited.find(node) != visited.end())
            return visited[node];
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(ansNode(neighbor, visited));
        }
        return cloneNode;
    }
    
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> visited;
        return ansNode(node, visited);
    }
};

// Utility function to print a graph
void printGraph(Node* node, unordered_map<Node*, bool>& visited) {
    if (!node) return;
    if (visited[node]) return;
    visited[node] = true;
    cout << "Node: " << node->val << " Neighbors: ";
    for (Node* neighbor : node->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;
    for (Node* neighbor : node->neighbors) {
        printGraph(neighbor, visited);
    }
}

int main() {
    Solution solution;

    // Create a sample graph
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);

    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);

    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);

    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    // Clone the graph
    Node* clonedGraph = solution.cloneGraph(node1);

    // Print the original graph
    unordered_map<Node*, bool> visitedOriginal;
    cout << "Original Graph:" << endl;
    printGraph(node1, visitedOriginal);

    // Print the cloned graph
    unordered_map<Node*, bool> visitedCloned;
    cout << "\nCloned Graph:" << endl;
    printGraph(clonedGraph, visitedCloned);

    return 0;
}
