#include <iostream>
using namespace std;
struct Node{
	int data;
	struct Node *next;
};
Node* Reverse(struct Node *head){
    struct Node *current = head;
    struct Node *prev = NULL, *next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
void print(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void push(struct Node** head,int d){
    struct Node *temp = new Node();
    temp->data = d;
    temp->next = (*head);
    (*head) = temp;
}
int main(){
	struct Node *head = NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	cout << "Given linked list\n";
	print(head);
	struct Node *R = Reverse(head);
	cout << "\nReversed Linked list\n";
	print(R);
	return 0;
}
