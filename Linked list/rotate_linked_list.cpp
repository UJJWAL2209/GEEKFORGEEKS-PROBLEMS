#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* leftShiftLinkedList(Node* head, int k) {
    if (head == nullptr || k <= 0) {
        return head;
    }

    int length = 0;
    Node* current = head;

    // Calculate the length of the linked list
    while (current != nullptr) {
        length++;
        current = current->next;
    }

    // Adjust the value of k to avoid unnecessary rotations
    k = k % length;

    if (k == 0) {
        return head; // No need to rotate if k is a multiple of the length
    }

    // Find the new head and the node at the new tail position
    current = head;
    for (int i = 1; i < k; i++) {
        current = current->next;
    }

    Node* newHead = current->next;
    current->next = nullptr; // Break the link at the new tail

    // Traverse to the end of the original list and link it to the original head
    current = newHead;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = head;

    return newHead;
}

// Function to print a linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    // Example 1
    Node* head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(7);
    head1->next->next->next = new Node(8);
    head1->next->next->next->next = new Node(9);

    int k1 = 3;
    cout << "Original List 1: ";
    printList(head1);
    Node* result1 = leftShiftLinkedList(head1, k1);
    cout << "Rotated List 1: ";
    printList(result1);

    // Example 2
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(4);
    head2->next->next->next->next = new Node(5);
    head2->next->next->next->next->next = new Node(6);
    head2->next->next->next->next->next->next = new Node(7);
    head2->next->next->next->next->next->next->next = new Node(8);

    int k2 = 4;
    cout << "Original List 2: ";
    printList(head2);
    Node* result2 = leftShiftLinkedList(head2, k2);
    cout << "Rotated List 2: ";
    printList(result2);

    return 0;
}
