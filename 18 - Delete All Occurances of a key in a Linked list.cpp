#include <iostream>
using namespace std;
struct Node{
	int data;
	struct Node *next;
};
Node* deleteAllOccurances(Node *head,int x){
    struct Node *curr = head;
    struct Node *prev = NULL;
    while(curr != NULL){
        if(curr->data == x){
            if(prev != NULL){
                prev->next = curr->next;
                curr->next = NULL;
                free(curr);
                curr = prev->next;
            }
            else{
                head = curr->next;
                curr->next = NULL;
                free(curr);
                curr = head;
            }
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
void print(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<"\n";
}
void push(struct Node** head,int d){
    struct Node *temp = new Node();
    temp->data = d;
    temp->next = (*head);
    (*head) = temp;
}
int main(){
	struct Node *head = NULL;
	push(&head,2);
	push(&head,2);
	push(&head,1);
	push(&head,2);
	cout << "Given linked list\n";
	print(head);
	int x; cin>>x;
	struct Node *R = deleteAllOccurances(head,x);
	cout << "Modified Linked list\n";
	print(R);
	return 0;
}
