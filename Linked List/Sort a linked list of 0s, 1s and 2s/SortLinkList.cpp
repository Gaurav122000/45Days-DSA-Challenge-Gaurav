// C++ Program to sort a linked list 0s, 1s or 2s 
#include <bits/stdc++.h>
using namespace std;

class Node 
{ 
	public:
	int data; 
	Node* next; 
}; 
void sortList(Node *head) 
{ 
	int count[3] = {0, 0, 0}; // Initialize count of '0', '1' and '2' as 0 
	Node *ptr = head; 
	while (ptr != NULL) 
	{ 
		count[ptr->data] += 1; 
		ptr = ptr->next; 
	} 

	int i = 0; 
	ptr = head; 
	while (ptr != NULL) 
	{ 
		if (count[i] == 0) 
			++i; 
		else
		{ 
			ptr->data = i; 
			--count[i]; 
			ptr = ptr->next; 
		} 
	} 
} 

/* Function to push a node */
void push (Node** head_ref, int new_data) 
{ 
	Node* new_node = new Node();
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

/* Function to print linked list */
void printList(Node *node) 
{ 
	while (node != NULL) 
	{ 
		cout << node->data << " "; 
		node = node->next; 
	} 
	cout << endl; 
} 

/* Driver code*/
int main(void) 
{ 
	Node *head = NULL; 
	push(&head, 0); 
	push(&head, 1); 
	push(&head, 0); 
	push(&head, 2); 
	push(&head, 1); 
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 1); 
	push(&head, 2); 
    
	cout << "Linked List before Sorting\n"; 
	printList(head); 
	sortList(head); 
	cout << "Linked List after Sorting\n"; 
	printList(head); 
	return 0; 
} 
