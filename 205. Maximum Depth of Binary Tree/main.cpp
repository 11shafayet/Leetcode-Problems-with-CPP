// https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return (1 + max(leftDepth, rightDepth));
    }
};

// Function to create a binary tree from a vector input
TreeNode* createTree(const vector<int>& nodes) {
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int index = 1;
    
    while (!q.empty() && index < nodes.size()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (nodes[index] != -1) {
            node->left = new TreeNode(nodes[index]);
            q.push(node->left);
        }
        index++;
        
        if (index < nodes.size() && nodes[index] != -1) {
            node->right = new TreeNode(nodes[index]);
            q.push(node->right);
        }
        index++;
    }
    return root;
}

int main() {
    vector<int> input = {3, 9, 20, -1, -1, 15, 7};  // Example input: root = [3,9,20,null,null,15,7]
    TreeNode* root = createTree(input);
    Solution solution;
    int result = solution.maxDepth(root);
    cout << "Maximum Depth: " << result << endl;
    return 0;
}
