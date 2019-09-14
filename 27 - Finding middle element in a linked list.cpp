#include <iostream>
using namespace std;
struct Node{
	int data;
	struct Node *next;
};
int getMiddle(Node *head){
    struct Node *temp = head;
    int cnt = -1;
    while(temp != NULL){
        ++cnt;
        temp = temp->next;
    }
    temp = head;
    if(cnt%2 == 0) --cnt;
    for(int i=0; i<=cnt/2; i++){
        temp = temp->next;
    }
    return temp->data;
}
void push(struct Node** head,int d){
    struct Node *temp = new Node();
    temp->data = d;
    temp->next = (*head);
    (*head) = temp;
}
int main(){
	struct Node *head = NULL;
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	cout<<getMiddle(head);
	return 0;
}
