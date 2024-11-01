/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;   // Vector to hold the traversal result
        traverse(root, result);     // Start the recursive traversal
        return result;              // Return the result
    }
    
private:
    void traverse(TreeNode* node, std::vector<int>& result) {
        if (!node) return;          // If the node is null, return

        // Traverse left subtree
        traverse(node->left, result);
        // Visit the current node
        result.push_back(node->val);
        // Traverse right subtree
        traverse(node->right, result);
    }
};
