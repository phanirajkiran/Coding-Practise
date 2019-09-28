#include <iostream>
const int MAX = 100;
struct Stack {
	int data;
	struct Stack *next;
};
struct Stack *top = NULL;
void push(int d) {
	struct Stack *temp = new Stack();
	temp->data = d;
	temp->next = top;
	top = temp;
}
int isEmpty() {
	return top == NULL;
}
void pop() {
	struct Stack *temp = new Stack();
	temp = top;
	top = top->next;
	temp->next = NULL;
	free(temp);
}
int Top() {
	return top->data;
}
void DFS(bool G[MAX][MAX], int i, bool vis[MAX], int n) {
	vis[i] = true;
	for (int j = 0; j < n; j++) {
		if (G[i][j] && !vis[j]) {
			DFS(G, j, vis, n);
		}
	}
	push(i);
}
void topologicalSort(bool G[MAX][MAX], int n) {
	bool vis[MAX] = {0};
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			DFS(G, i, vis, n);
		}
	}
	while (!isEmpty()){
		std::cout << Top() << " ";
		pop();
	}
}
int main(){
	int n;
	std::cin >> n;
	bool G[MAX][MAX];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> G[i][j];
		}
	}
	topologicalSort(G, n);
	return 0;
}
