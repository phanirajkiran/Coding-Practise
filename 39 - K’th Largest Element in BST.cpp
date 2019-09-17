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
// Right - Root - Left
void kLargestElement(Node *root,int k,int *cnt){
    if(root == NULL || *cnt >= k) return;
    kLargestElement(root->right,k,cnt);
    *cnt = (*cnt) + 1;
    if(k == *cnt){
        cout<<root->data<<endl;
        return;
    }
    kLargestElement(root->left,k,cnt);
}
int main(){
	struct Node *root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	int k,cnt = 0;
	cin>>k;
	kLargestElement(root,k,&cnt);
	return 0;
}
