#include <iostream>
using namespace std;
struct Node{
	int data;
	struct Node *next;
};
void push(struct Node** head,int d){
    struct Node *temp = new Node();
    temp->data = d;
    temp->next = (*head);
    (*head) = temp;
}
int detectLoop(struct Node *h){
    struct Node *slow = h, *fast = h;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return 1;
    }
    return 0;
}
int main(){
	struct Node* head = NULL;
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	head->next->next->next->next->next = head->next;
	if(detectLoop(head)) cout << "Loop found";
	else cout << "No Loop";
	return 0;
}
