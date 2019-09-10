#include <bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node *left;
	node *right;
};
node* newNode(int data){
	node *Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	return Node;
}
void printKDistant(node *root,int k){
	if(root == NULL) return;
	if(k == 0){
		cout << root->data << " ";
		return;
	}
	else{
		printKDistant(root->left,k-1);
		printKDistant(root->right,k-1);
	}
}
int main(){
	/* Constructed binary tree is
			 1
           /   \
          2     3
         / \   /
        4   5 8
	*/
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(8);
	printKDistant(root,2);
	return 0;
}
