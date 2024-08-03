/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* result = dummy;

        int total = 0, carry = 0;

        while(l1 || l2 || carry){
            total = carry;

            if(l1){
                total += l1->val;
                l1 = l1->next;
            }
            //added l1 and l2 till here
            if(l2){
                total += l2->val;
                l2 = l2->next;
            }

            int num = total % 10; //take the value from total and store in num
            carry = total / 10; //checking for any carry
            dummy -> next = new ListNode(num);
            dummy = dummy->next;

        }
        return result->next;
    }
};