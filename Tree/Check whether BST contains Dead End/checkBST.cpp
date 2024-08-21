/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
    bool isDeadEnd(Node *root)
    {
        //Your code here
        bool present[10002];
        int i, j;
        
        for(i = 0; i<=10001; i++){
            present[i] = false;
        }
        
        fillPresent(root, present);// first we fill this array
        
        bool ans = false;// we willl assume that their will not any deadEnd
        
        checkDeadEnd(root, ans, present);
        
        return ans;
    }
    
    void checkDeadEnd(Node *root, bool& ans, bool present[]){
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            if(root->data == 1){
                if(present[2] == true){
                    ans = true;
                }
            }else{
                if(present[root->data-1] == true && present[root->data+1] == true){
                    ans=true;
                }
            }
        }else{
            checkDeadEnd(root->left, ans, present);
            checkDeadEnd(root->right, ans, present);
        }
    }
    
    void fillPresent(Node *root, bool present[]){
        if(root == NULL){
            return;
        }
        
        present[root->data]++;
        
        fillPresent(root->left, present);
        fillPresent(root->right, present);
    }
};