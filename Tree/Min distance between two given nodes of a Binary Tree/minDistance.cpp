class Solution {
public:
    // Helper function to find the lowest common ancestor (LCA)
    Node* lowestCommonAncestor(Node* root, int a, int b) {
        if (!root || root->data == a || root->data == b) {
            return root;
        }
        Node* left = lowestCommonAncestor(root->left, a, b);
        Node* right = lowestCommonAncestor(root->right, a, b);
        if (left && right) {
            return root; // LCA found
        }
        return left ? left : right;
    }

    // Helper function to calculate the distance from root to a target node
    int distanceToNode(Node* root, int target, int dist) {
        if (!root) {
            return 0;
        }
        if (root->data == target) {
            return dist;
        }
        int leftDist = distanceToNode(root->left, target, dist + 1);
        int rightDist = distanceToNode(root->right, target, dist + 1);
        return leftDist + rightDist;
    }

    // Main function to find the minimum distance between nodes a and b
    int findDist(Node* root, int a, int b) {
        Node* lca = lowestCommonAncestor(root, a, b);
        int distA = distanceToNode(lca, a, 0);
        int distB = distanceToNode(lca, b, 0);
        return distA + distB;
    }
};