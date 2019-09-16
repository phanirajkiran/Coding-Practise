#include <iostream>
using namespace std;
class Node{
public:
	int data;
	Node *next;
};
void push(Node** head,int d){
	Node *node = new Node();
	node->data = d;
	node->next = (*head);
	(*head) = node;
}
int getCount(Node *head){
	int count = 0;
	Node *current = head;
	while(current != NULL){
		count++;
		current = current->next;
	}
	return count;
}
int main(){
	Node* head = NULL;
	/* 1->2->1->3->1 */
	push(&head,1);
	push(&head,3);
	push(&head,1);
	push(&head,2);
	push(&head,1);
	cout<<"count of nodes is "<< getCount(head);
	return 0;
}
