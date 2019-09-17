#include <iostream>
using namespace std;
class Node{
public:
	int data;
	Node *left;
	Node *right;
};
Node* findLCA(Node *root,int a,int b){
	if(root == NULL) return NULL;
	if(root->data == a || root->data == b) return root;
	Node *l = findLCA(root->left,a,b);
	Node *r = findLCA(root->right,a,b);
	if(l && r) return root;
	return (l == NULL ? r : l);
}
int findDist(Node *root,int a,int depth){
	if(root == NULL) return -1;
	if(root->data == a) return depth;
	int l = findDist(root->left,a,depth+1);
	int r = findDist(root->right,a,depth+1);
	return (l == -1 ? r : l);
}
Node* newNode(int data){
	Node *node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
int main(){
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	int a,b;
	cin>>a>>b;
	Node *LCA = findLCA(root,a,b);
	int dis1 = findDist(root,a,0);
	int dis2 = findDist(root,b,0);
	int dis3 = findDist(root,LCA->data,0);
	cout << (dis1+dis2) - (2*dis3);
	return 0;
}
