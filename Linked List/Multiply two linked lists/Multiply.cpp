/* Linked list node structure
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

/*The method multiplies
two  linked lists l1 and l2
and returns their product*/

/* Multiply contents of two linked lists */
class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long int num1 = 0, num2 = 0, mod = 1000000007;
        struct Node *p1, *p2;
        p1 = first;
        p2 = second;
        
        while(p1 != NULL){
            num1=(num1*10+(p1->data))%mod;
            p1=p1->next;
        }
        
        while(p2 != NULL){
            num2=(num2*10+(p2->data))%mod;
            p2=p2->next;
        }
        
        return (num1*num2)%mod;
    }
};

