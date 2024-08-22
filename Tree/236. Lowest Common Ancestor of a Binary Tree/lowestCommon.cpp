/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || root == NULL)
            return root;

        TreeNode* lca_from_left = lowestCommonAncestor(root->left, p, q);//it give us Lowest Comman Ancestor
        TreeNode* lca_from_right = lowestCommonAncestor(root->right, p, q);//it give us lowest Comman Ancestor

        if(lca_from_left && lca_from_right){
            return root;
        }
        else{
            return lca_from_left ? lca_from_left : lca_from_right;
        }
    }
};