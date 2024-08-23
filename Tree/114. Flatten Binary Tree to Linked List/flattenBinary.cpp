class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;

        // preorder traversal vector
        vector<TreeNode*> preorder;
        preOrder(root, preorder);

       // create the linked list
       for(int i = 1; i < preorder.size(); i++) {
        root->left = nullptr;
        root->right = preorder[i];
        root = root->right;
       }
    }

    void preOrder(TreeNode* root, vector<TreeNode*>& vec) {
        if(!root) {
             return;
        }
        vec.push_back(root);
        preOrder(root->left, vec);
        preOrder(root->right, vec);     
    }
};