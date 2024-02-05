#include <bits/stdc++.h>
using namespace std;

// Definition for a Node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* sortedInsert(Node* head, int data) {
    Node* newNode = new Node(data);

    if (!head) {
        newNode->next = newNode;
        return newNode;
    }

    Node* current = head;

    do {
        // If data is smaller than the first node's data
        if (data < current->data) {
            newNode->next = current;
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = newNode;
            return newNode;
        }

        // If data is to be inserted between two nodes
        if (data >= current->data && data <= current->next->data) {
            newNode->next = current->next;
            current->next = newNode;
            return head;
        }

        // If data is greater than the last node's data
        if (current->data > current->next->data && data >= current->data) {
            newNode->next = current->next;
            current->next = newNode;
            return head;
        }

        current = current->next;
    } while (current != head);

    // If data is smaller than all nodes, insert at the end
    newNode->next = current->next;
    current->next = newNode;
    return (data < head->data) ? newNode : head;
}

// Function to print the circular linked list
void printList(Node* head) {
    if (!head) return;

    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);

    cout << endl;
}

// Driver code
int main() {
    int n = 6;
    Node* head = new Node(-15);
    head->next = new Node(-9);
    head->next->next = new Node(-6);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(7);
    head->next->next->next->next->next = new Node(14);
    head->next->next->next->next->next->next = head;

    cout << "Original list: ";
    printList(head);

    int data = -19;
    head = sortedInsert(head, data);

    cout << "List after inserting " << data << ": ";
    printList(head);

    return 0;
}
