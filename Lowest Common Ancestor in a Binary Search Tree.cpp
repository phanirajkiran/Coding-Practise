/*
The distance from n1 to n2 can be computed as the distance from the root to n1,
plus the distance from the root to n2,
minus twice the distance from the root to their lowest common ancestor.
*/
#include <stdio.h>
struct node{
	int data;
	struct node *left, *right;
};
struct node* LCA(struct node *root, int n1, int n2){
	if(root == NULL) return NULL;
	if(root->data > n1 && root->data > n2){
		return LCA(root->left, n1, n2);
	}
	if(root->data < n1 && root->data < n2){
		return LCA(root->right, n1, n2);
	}
	return root;
}
struct node* newNode(int data){
	struct node *Node = new node();
	Node->data = data;
	Node->left = Node->right = NULL;
	return Node;
}
int main(){
	struct node *root = newNode(20);
	root->left = newNode(8);
	root->right	= newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	int n1 = 10, n2 = 14;
	struct node *t = LCA(root, n1, n2);
	printf("LCA of %d and %d is %d \n", n1, n2, t->data);
	n1 = 14, n2 = 8;
	t = LCA(root, n1, n2);
	printf("LCA of %d and %d is %d \n", n1, n2, t->data);
	n1 = 10, n2 = 22;
	t = LCA(root, n1, n2);
	printf("LCA of %d and %d is %d \n", n1, n2, t->data);
	return 0;
}
