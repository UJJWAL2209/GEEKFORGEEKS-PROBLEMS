#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool check(TreeNode* root) {
    if (root == nullptr)
        return true;

    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    int leafLevel = -1;

    while (!q.empty()) {
        int size = q.size();
        level++;

        while (size--) {
            TreeNode* node = q.front();
            q.pop();

            // Check if current node is a leaf
            if (node->left == nullptr && node->right == nullptr) {
                // If it's the first leaf node encountered, store its level
                if (leafLevel == -1)
                    leafLevel = level;
                // If leaf node level is not same as previous leaf nodes' level, return false
                else if (leafLevel != level)
                    return false;
            }

            // Enqueue child nodes if they exist
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return true;
}

// Test the function
int main() {
    // Example 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    cout << (check(root1) ? "true" : "false") << endl;

    // Example 2
    TreeNode* root2 = new TreeNode(10);
    root2->left = new TreeNode(20);
    root2->right = new TreeNode(30);
    root2->left->left = new TreeNode(10);
    root2->left->right = new TreeNode(15);
    cout << (check(root2) ? "true" : "false") << endl;

    return 0;
}
