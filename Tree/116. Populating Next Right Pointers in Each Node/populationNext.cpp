class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr; 

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            Node* prevNode = nullptr;

            for (int i = 0; i < levelSize; ++i) {
                Node* currNode = q.front();
                q.pop();

                if (prevNode) {
                    prevNode->next = currNode;
                }

                if (currNode->left) {
                    q.push(currNode->left);
                }
                if (currNode->right) {
                    q.push(currNode->right);
                }

                prevNode = currNode;
            }
        }

        return root; 
    }
};
