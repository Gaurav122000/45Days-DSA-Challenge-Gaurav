/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        if( root == nullptr || root->next == nullptr)//base case
            return root; // goes till 28 then 19, then 10 
            
        root->next = flatten(root->next);// rescursion return 28
        
        root = merge(root, root->next);// merge function call
        
        return root;
    }
    
    
    Node* merge(Node* l1, Node* l2){
        Node* res = new Node(0); // create new node for storing the list
        Node* temp = res; // for traversing we created a variable
        
        while(l1 != nullptr && l2 != nullptr){// runing the loop 
            if(l1->data < l2->data){ // now pushing the small element at the end so that we can arrange the list in asscending order
                temp->bottom = l1;
                temp = temp->bottom;// increasing temp
                l1 = l1->bottom;// increasing l1
            }else{
                temp->bottom = l2;
                temp = temp->bottom;// increasing temp
                l2 = l2->bottom;// increasing l2
            }
        }
        if(l1 != nullptr){// here we are checking if any node left but it's possible that one list is small then other that have stop the loop
            temp->bottom = l1;
        }
        else{
            temp->bottom =l2;
        }
        
        return res->bottom;// now returning the list 
            
    }
};