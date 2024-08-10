class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return 0;
            
            int left = dfs(node->left);
            int right = dfs(node->right);
            
            maxDiameter = max(maxDiameter, left + right);
            
            return max(left, right) + 1;
        };
        
        dfs(root);
        return maxDiameter;
    }
};