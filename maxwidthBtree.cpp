#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxWidth(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int maxWidth = 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        int levelSize = q.size();
        pair<TreeNode*, int> firstNode = q.front();
        pair<TreeNode*, int> lastNode;

        for (int i = 0; i < levelSize; i++) {
            lastNode = q.front();
            q.pop();
            TreeNode* node = lastNode.first;
            int index = lastNode.second;

            if (node->left) {
                q.push({node->left, 2 * index});
            }
            if (node->right) {
                q.push({node->right, 2 * index + 1});
            }
        }

        // Calculate the width at this level and update maxWidth
        int width = lastNode.second - firstNode.second + 1;
        maxWidth = max(maxWidth, width);
    }

    return maxWidth;
}

int main() {
    // Create a binary tree (example)
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    int width = maxWidth(root);
    cout << "Maximum width of the binary tree is: " << width << endl;

    return 0;
}
