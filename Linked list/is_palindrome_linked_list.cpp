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
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// Function to check if a linked list is palindrome
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true; // Empty list or single element list is always a palindrome
    }

    // Find the middle of the linked list
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    Node* reversedSecondHalf = reverseList(slow);

    // Compare the reversed second half with the first half
    Node* firstHalf = head;
    while (reversedSecondHalf != nullptr) {
        if (firstHalf->data != reversedSecondHalf->data) {
            return false; // Not a palindrome
        }
        firstHalf = firstHalf->next;
        reversedSecondHalf = reversedSecondHalf->next;
    }

    return true; // Palindrome
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
    head1->next->next = new Node(1);

    cout << "Example 1: ";
    printList(head1);
    cout << "Is Palindrome? " << (isPalindrome(head1) ? "Yes" : "No") << endl;

    // Example 2
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(4);

    cout << "Example 2: ";
    printList(head2);
    cout << "Is Palindrome? " << (isPalindrome(head2) ? "Yes" : "No") << endl;

    return 0;
}
