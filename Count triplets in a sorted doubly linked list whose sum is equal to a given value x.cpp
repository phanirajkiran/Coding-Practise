#include <iostream>
using namespace std;
struct Node{
	int data;
	struct Node *next, *prev;
};
int countTriplets(struct Node *head,int x){
	struct Node *ptr1, *ptr2, *ptr3;
	int count = 0;
	// generate all possible triplets
	for(ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next){
		for(ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next){
			for(ptr3 = ptr2->next; ptr3 != NULL; ptr3 = ptr3->next){
				if((ptr1->data + ptr2->data + ptr3->data) == x){
					// increment count
					count++;
				}
			}
		}
	}
	return count;
}
void push(Node** head,int d){
	Node *node = new Node();
	node->data = d;
	node->next = (*head);
	(*head) = node;
}
int main(){
	struct Node *head = NULL;
	push(&head,9);
	push(&head,8);
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,2);
	push(&head,1);
	int x = 17;
	cout << "Count = "<< countTriplets(head,x);
	return 0;
}
