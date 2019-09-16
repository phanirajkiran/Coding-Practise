#include <iostream>
using namespace std;
struct Node{
	int data;
	struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
void push(int data){
	struct Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(front == NULL) front = rear = temp;
    else{
      rear->next = temp;
      rear = temp;
    }
}
int isEmpty(){
	return front == NULL;
}
int Front(){
	if(!isEmpty()) return front->data;
	else exit(1);
}
void pop(){
	struct Node *temp;
	if(front == NULL) exit(1);
	else{
		temp = front;
		front = front->next;
		temp->next = NULL;
		free(temp);
	}
}
void display(){
	struct Node *temp;
	if(front == NULL) exit(1);
	else{
		temp = front;
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
	cout << "\nTop element is " << Front() <<endl;
	pop();
	pop();
	display();
	cout << "\nTop element is " << Front() <<endl;
	push(3);
	display();
	return 0;
}
