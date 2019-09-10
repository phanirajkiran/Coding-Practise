#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
};
Node* newNode(int d){
    Node *node = new Node();
    node->data = d;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int toSumTree(Node *node){
    if(node == NULL) return 0;
    int oldValue = node->data;
    node->data = toSumTree(node->left) + toSumTree(node->right);
    return oldValue+node->data;
}
void InorderTraversal(Node *node){
    if(node == NULL) return;
    InorderTraversal(node->left);
    cout<<node->data<<" ";
    InorderTraversal(node->right);
}
int main(){
    Node *root = newNode(10);
    root->left = newNode(-2);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right = newNode(6);
    root->right->left = newNode(7);
    root->right->right = newNode(5);
    InorderTraversal(root);
    toSumTree(root);
    cout<<endl;
    InorderTraversal(root);
}
