#include <bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;
};
int countLeaves(node* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    else{
        int l = countLeaves(root->left);
        int r = countLeaves(root->right);
        return (l+r);
    }
}
node* newNode(int data){
	node *Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	return Node;
}
int main(){
	node *root = newNode(1);
	root->left = newNode(10);
	root->right = newNode(39);
	root->left->left = newNode(5);
	cout << "Leaves of tree is " << countLeaves(root);
	return 0;
}
