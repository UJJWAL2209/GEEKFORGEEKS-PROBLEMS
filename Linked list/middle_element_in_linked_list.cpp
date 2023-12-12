#include <iostream>

/* Link list node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

int getMiddle(Node *head) {
    if (head == NULL)
        return -1; // No nodes in the linked list

    Node *slowPtr = head;
    Node *fastPtr = head;

    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    return slowPtr->data;
}

// Example usage
int main() {
    struct Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Output: " << getMiddle(head) << std::endl;

    return 0;
}
