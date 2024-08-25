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
    // Helper function to compute the maximum path sum at each node
    private:
        int findMaxPathSum(TreeNode* root, int& maximum) {
            // Base case: if the current node is null, return 0 (no contribution to the path sum)
            if (!root) return 0;

            // Recursively calculate the maximum path sum of the left subtree
            // Use Math.max(0, ...) to ignore any negative contributions from the subtree
            int leftSum = max(0, findMaxPathSum(root->left, maximum));

            // Recursively calculate the maximum path sum of the right subtree
            // Also use Math.max(0, ...) to ignore negative contributions
            int rightSum = max(0, findMaxPathSum(root->right, maximum));

            // Update the overall maximum path sum that includes the current node
            // This is the sum of the current node's value and the maximum path sums from both left and right subtrees
            maximum = max(maximum, leftSum + rightSum + root->val);

            // Return the maximum path sum including the current node and either its left or right subtree
            // This will help build up the maximum path as we traverse upwards in the tree
            return root->val + max(leftSum, rightSum);
        }

    // Main function to find the maximum path sum in the binary tree
    public:
        int maxPathSum(TreeNode* root) {
            // Initialize an array to store the overall maximum path sum
            // We use an array to hold the result because Java uses pass-by-value, and we need to maintain
            // a global reference to the maximum value as we recurse through the tree
            // Set the initial maximum path sum to the smallest possible integer value
            int maximum = INT_MIN;
            // Call the helper function to compute the maximum path sum starting from the root
            findMaxPathSum(root, maximum);
            // Return the overall maximum path sum found
            return maximum;
        }
};