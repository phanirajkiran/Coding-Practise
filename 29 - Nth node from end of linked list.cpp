#include <iostream>
using namespace std;
struct Node{
	int data;
	struct Node *next;
};
int getNthFromLast(Node *head,int n){
    struct Node *temp = head;
    int cnt = 0;
    while(temp != NULL){
        temp = temp->next;
        ++cnt;
    }
    cnt -= (n-1);
    temp = head;
    if(cnt < 1) return -1;
    while(cnt != 1){
        temp = temp->next;
        --cnt;
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
	int n = 6;
	cout<<getNthFromLast(head,n);
	return 0;
}
