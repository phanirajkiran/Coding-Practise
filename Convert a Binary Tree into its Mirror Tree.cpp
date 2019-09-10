#include <bits/stdc++.h>
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
/* Change a tree so that the roles of the left and
   right pointers are swapped at every node.
So the tree...
	 1
	/ \
   2   3
  / \
 4   5
is changed to...
	 1
	/ \
   3   2
      / \
     5   4
*/
void mirror(struct Node *node){
	if(node == NULL) return;
	else{
		struct Node *temp;
		mirror(node->left);
		mirror(node->right);
		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}
/* Helper function to print
In-order traversal.*/
void inOrder(struct Node *node){
	if(node == NULL) return;
	inOrder(node->left);
	cout << node->data << " ";
	inOrder(node->right);
}
int main(){
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	cout << "In-order traversal of the constructed tree is" << endl;
	inOrder(root);
	mirror(root);
	cout << "\nIn-order traversal of the mirror tree is" << endl;
	inOrder(root);
	return 0;
}
