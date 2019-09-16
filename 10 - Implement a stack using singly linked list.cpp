#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node *next;
};
struct Node *top = NULL;
void push(int data){
	struct Node *temp = new Node();
	temp->data = data;
	temp->next = top;
	top = temp;
}
int isEmpty(){
	return top == NULL;
}
int peek(){
	if(!isEmpty()) return top->data;
	else exit(1);
}
void pop(){
	struct Node *temp;
	if(top == NULL){
		cout << "\nStack Underflow" << endl;
		exit(1);
	}
	else{
		temp = top;
		top = top->next;
		temp->next = NULL;
		free(temp);
	}
}
void display(){
	struct Node *temp;
	if(top == NULL){
		cout << "\nStack Underflow";
		exit(1);
	}
	else{
		temp = top;
		while(temp != NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
}
int main(){
	push(11);
	push(22);
	push(33);
	push(44);
	display();
	cout << "\nTop element is " << peek() <<endl;
	pop();
	pop();
	display();
	cout << "\nTop element is " << peek() <<endl;
	push(3);
	display();
	return 0;
}
