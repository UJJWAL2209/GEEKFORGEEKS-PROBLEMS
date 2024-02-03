#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int decimalValue(ListNode* head) {
        int result = 0;
        int mod = 1000000007; // Modulo value
        
        while (head != nullptr) {
            result = (result * 2 + head->val) % mod;
            head = head->next;
        }
        
        return result;
    }
};

// Function to create a new node
ListNode* createNode(int data) {
    ListNode* newNode = new ListNode(data);
    return newNode;
}

// Function to append a new node at the end of the list
void append(ListNode* &head, int data) {
    ListNode* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    Solution sol;

    // Example 1
    ListNode* head1 = nullptr;
    append(head1, 0);
    append(head1, 1);
    append(head1, 1);
    cout << "Example 1 Output: " << sol.decimalValue(head1) << endl;

    // Example 2
    ListNode* head2 = nullptr;
    append(head2, 1);
    append(head2, 1);
    append(head2, 1);
    append(head2, 0);
    cout << "Example 2 Output: " << sol.decimalValue(head2) << endl;

    return 0;
}
