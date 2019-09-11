#include <iostream>
using namespace std;
class Node{
public:
	int data;
	Node *next;
};
void push(Node** head,int data){
	Node *newNode = new Node();
	newNode->data = data;
	newNode->next = (*head);
	(*head) = newNode;
}
Node* SortedMerge(Node *a,Node *b){
	Node *result = NULL;
	if(a == NULL) return b;
	else if(b == NULL) return a;
	if(a->data <= b->data){
		result = a;
		result->next = SortedMerge(a->next,b);
	}
	else{
		result = b;
		result->next = SortedMerge(a,b->next);
	}
	return result;
}
void printList(Node *node){
	while(node != NULL){
		cout<<node->data<<" ";
		node = node->next;
	}
}
int main(){
	Node *a = NULL;
	Node *b = NULL;
	/* a: 5->10->15, b: 2->3->20 */
	push(&a,15);
	push(&a,10);
	push(&a,5);
	push(&b,20);
	push(&b,3);
	push(&b,2);
	Node *res = SortedMerge(a,b);
	cout << "Merged Linked List is: \n";
	printList(res);
	return 0;
}
