// C++ program to arrange linked list in zigzag fashion 
#include <bits/stdc++.h> 
using namespace std; 
  
/* Link list Node */
struct Node { 
    int data; 
    struct Node* next; 
}; 

class Solution {
  public:
    Node* zigZag(Node* head) {
        // your code goes here
        // If flag is true, then next node should be greater in 
        // the desired output.
        if(!head || !head->next){
            return head;
        }
        bool flag = true;
        Node* curr = head;
        // Traverse linked list starting from head.
        while(curr->next != NULL){
            if(flag){/* "<" relation expected */
                // If we have a situation like A > B > C where 
                // A, B and C are consecutive Nodes in list we 
                // get A > B < C by swapping B and C 
                if(curr->data > curr->next->data)
                    swap(curr->data, curr->next->data);
            }
            else{/* ">" relation expected */
                // If we have a situation like A < B < C where 
                // A, B and C  are consecutive Nodes in list we 
                // get A < C > B by swapping B and C 
                if(curr->data < curr->next->data)
                    swap(curr->data, curr->next->data);
            }
            curr = curr->next;
            flag = !flag; /* flip flag for reverse checking */
        }
        return head;
    }
};