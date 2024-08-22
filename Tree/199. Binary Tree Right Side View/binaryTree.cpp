//we did (level order traversing + BFS)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        queue<TreeNode*> q;
        vector<int> res;

        q.push(root);

        while(!q.empty()){
            int l = q.size();
            for(int i = 0; i<l; i++){
                //queue only have data in level wise order
                TreeNode* temp=q.front();
                q.pop();
                //we have to check if we at the last level of tree node
                if(i == l-1) res.push_back(temp->val);
                //now do the simple bfs
                if(temp->left) q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        return res;
    }
};