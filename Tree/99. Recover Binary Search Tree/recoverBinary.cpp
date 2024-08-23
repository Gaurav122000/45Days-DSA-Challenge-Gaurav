//O(1) Space Complexity
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;  // First out-of-order node
        TreeNode* second = nullptr; // Second out-of-order node
        TreeNode* prev = nullptr;   // Previous node during in-order traversal

        std::stack<TreeNode*> stk;

        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();

            if (prev && root->val < prev->val) {
                if (!first) {
                    first = prev;
                }
                second = root;
            }

            prev = root;
            root = root->right;
        }

        // Swap the values of the two out-of-order nodes
        swap(first->val, second->val);
    }
};