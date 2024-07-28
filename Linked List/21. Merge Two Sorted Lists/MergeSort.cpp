class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *result = new ListNode(0);
        ListNode *track = result;

        while (list1 || list2) {
            if (list1 && list2) {
                ListNode **smaller = list1->val < list2->val ? &list1 : &list2;
                track->next = (*smaller);
                (*smaller) = (*smaller)->next;
            } else {
                ListNode **valid = list1 ? &list1 : &list2;
                track->next = (*valid);
                break;
            }
            track = track->next;
        }

        return result->next;
    }
};