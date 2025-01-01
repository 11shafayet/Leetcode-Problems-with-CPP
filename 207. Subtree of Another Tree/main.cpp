// https://leetcode.com/problems/subtree-of-another-tree/

#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool preOrder(TreeNode* root, TreeNode* subRoot) {
       if(!root && !subRoot) return true;
       if(!root || !subRoot) return false;

       return (root->val == subRoot->val) &&
              (preOrder(root->left, subRoot->left)) &&
              (preOrder(root->right, subRoot->right));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(!subRoot) return true;

        if(preOrder(root, subRoot)) return true;

        return (preOrder(root->left, subRoot) || preOrder(root->right, subRoot));
    }
};

// Helper function to create a binary tree from a vector
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty()) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Create left child
        if (nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        // Create right child
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Helper function to delete a tree and free memory
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Main function for testing
int main() {
    vector<int> rootNodes = {3, 4, 5, 1, 2};
    vector<int> subRootNodes = {4, 1, 2};

    TreeNode* root = buildTree(rootNodes);
    TreeNode* subRoot = buildTree(subRootNodes);

    Solution solution;
    bool result = solution.isSubtree(root, subRoot);
    cout << (result ? "True" : "False") << endl;

    // Clean up memory
    deleteTree(root);
    deleteTree(subRoot);

    return 0;
}
