#include <iostream>
using namespace std;
struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};
struct Node* newNode(int data){
	struct Node *node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
// finding lowest common ancestor
Node* findLCA(Node *root,int a,int b){
	if(root == NULL) return NULL;
	if(root->data == a || root->data == b) return root;
	Node *l = findLCA(root->left,a,b);
	Node *r = findLCA(root->right,a,b);
	if(l && r) return root;
	return (l == NULL ? r : l);
}
int main(){
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	struct Node *node = findLCA(root,2,4);
	cout << "LCA is " << node->data;
	return 0;
}
