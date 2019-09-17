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
void printLeftView(Node *root,int level,int *maxLevel){
    if(root == NULL) return;
    if(level > *maxLevel){
        cout<<root->data<<" ";
        *maxLevel = level;
    }
    printLeftView(root->left,level+1,maxLevel);
    printLeftView(root->right,level+1,maxLevel);
}
int main(){
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	int maxLevel = 0;
	printLeftView(root,1,&maxLevel);
	return 0;
}
