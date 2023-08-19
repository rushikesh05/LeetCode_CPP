// Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

// Example 1:


// Input: root = [1,null,2,3]
// Output: [1,2,3]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]
 

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
 

// Follow up: Recursive solution is trivial, could you do it iteratively?


#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Recursive approach
    vector<int> preorderTraversalRecursive(TreeNode* root) {
        vector<int> result;
        preorderRecursive(root, result);
        return result;
    }
    
    void preorderRecursive(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        result.push_back(root->val);
        preorderRecursive(root->left, result);
        preorderRecursive(root->right, result);
    }
    
    // Iterative approach
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodes;
        if (root != nullptr) {
            nodes.push(root);
        }
        
        while (!nodes.empty()) {
            TreeNode* node = nodes.top();
            nodes.pop();
            result.push_back(node->val);
            
            if (node->right != nullptr) {
                nodes.push(node->right);
            }
            if (node->left != nullptr) {
                nodes.push(node->left);
            }
        }
        
        return result;
    }
};

// Explanation:

// The preorderTraversalRecursive function performs the preorder traversal of the binary tree using a recursive approach. It initializes an empty result vector and calls the helper function preorderRecursive.
// The preorderRecursive function recursively traverses the tree, pushing the values of the nodes into the result vector in the order of the preorder traversal.
// The preorderTraversal function performs the preorder traversal iteratively using a stack. It initializes an empty result vector and a stack nodes to keep track of nodes to be visited.
// We start by pushing the root node onto the stack (if it exists).
// In the loop, we pop a node from the stack, push its value into the result vector, and then push its right and left children (if they exist) onto the stack. This ensures that the right child is processed before the left child, as required by the preorder traversal.