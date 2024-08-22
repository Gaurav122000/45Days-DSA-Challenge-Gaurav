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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        queue<TreeNode*> q;
        vector<vector<int>> traversal;

        q.push(root);

        while (!q.empty()) {
            int currSize = q.size();
            vector<int> currLevel;

            for (int i = 0; i < currSize; ++i) {
                TreeNode* currNode = q.front();
                q.pop();

                currLevel.push_back(currNode->val);

                if (currNode->left) {
                    q.push(currNode->left);
                }
                if (currNode->right) {
                    q.push(currNode->right);
                }
            }

            traversal.push_back(currLevel);
        }

        return traversal;
    }
};
