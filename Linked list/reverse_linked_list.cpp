#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;  // new head after reversing
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example 1
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(6);

    cout << "Original List 1: ";
    printList(head1);

    head1 = reverseList(head1);

    cout << "Reversed List 1: ";
    printList(head1);

    // Example 2
    Node* head2 = new Node(2);
    head2->next = new Node(7);
    head2->next->next = new Node(8);
    head2->next->next->next = new Node(9);
    head2->next->next->next->next = new Node(10);

    cout << "\nOriginal List 2: ";
    printList(head2);

    head2 = reverseList(head2);

    cout << "Reversed List 2: ";
    printList(head2);

    return 0;
}
