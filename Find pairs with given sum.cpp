#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int d;
    Node *next;
};
void Insert(Node **head, int v){
    Node *newNode = new Node();
    newNode->d = v;
    newNode->next = (*head);
    (*head) = newNode;
}
void printList(Node *node){
    while(node != NULL){
        cout<<node->d<<" ";
        node = node->next;
    }
}
int countPairSum(Node *head, int x){
    Node *ptr1, *ptr2;
    int cnt = 0;
    for(ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next){
        for(ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next){
            if(ptr1->d + ptr2->d == x){
                ++cnt;
            }
        }
    }
    return cnt;
}
int main(){
    Node *head = NULL;
    int n,a,x;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        Insert(&head,a);
    }
    cin>>x;
    cout<<countPairSum(head,x)<<endl;
    return 0;
}
