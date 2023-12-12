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

int getNthFromLast(struct Node *head, int n) {
    struct Node *mainPtr = head;
    struct Node *refPtr = head;

    int count = 0;
    while (count < n) {
        if (refPtr == NULL) {
            return -1; // n is greater than the number of nodes
        }
        refPtr = refPtr->next;
        count++;
    }

    while (refPtr != NULL) {
        refPtr = refPtr->next;
        mainPtr = mainPtr->next;
    }

    return mainPtr->data;
}

// Example usage
int main() {
    struct Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int n = 2;
    std::cout << "Output: " << getNthFromLast(head, n) << std::endl;

    return 0;
}
