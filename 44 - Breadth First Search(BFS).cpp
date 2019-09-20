#include <iostream>
using namespace std;
bool visited[100];
bool edges[100][100];
int p[100];
struct Node{
	int data;
	struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
void push(int data){
	struct Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(front == NULL) front = rear = temp;
    else{
      rear->next = temp;
      rear = temp;
    }
}
int isEmpty(){
	return front == NULL;
}
int Front(){
	if(!isEmpty()) return front->data;
	else exit(1);
}
void pop(){
	struct Node *temp;
	if(front == NULL) exit(1);
	else{
		temp = front;
		front = front->next;
		temp->next = NULL;
		free(temp);
	}
}
void bfs(int s,int d){
    push(s);
    visited[s] = 1;
    while(!isEmpty()){
        int u = Front();
        cout<<u<<endl;
        pop();
        for(int i=1; i<100; i++){
            if(edges[u][i]){
                if(!visited[i]){
                    visited[i] = 1;
                    p[i] = u;
                    push(i);
                }
            }
            if(visited[d]) break;
        }
    }
    int b = d;
    cout<<b<<" ";
    while(b != s){
        b = p[b];
        cout<<b<<" ";
    }
}
int main()
{
    int n,e,u,v,start,des;
    cin>>n>>e;
    for(int i=1; i<=e; i++){
        cin>>u>>v;
        edges[u][v] = 1;
        edges[v][u] = 1;
    }
    cin>>start>>des;
    bfs(start,des);
    return 0;
}
