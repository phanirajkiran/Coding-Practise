#include <iostream>
using namespace std;
const int MAX = 100;
int directionX[4] = { 0,-1,0,1 };
int directionY[4] = { 1,0,-1,0 };
struct Cell {
	int a;
	int b;
};
struct Queue {
	int x;
	int y;
	Queue *next;
};
struct Queue *Front = NULL;
struct Queue *Rear = NULL;
void push(int x, int y) {
	struct Queue *temp = new Queue();
	temp->x = x;
	temp->y = y;
	temp->next = NULL;
	if (Front == NULL) Front = Rear = temp;
	else {
		Rear->next = temp;
		Rear = temp;
	}
}
void pop() {
	struct Queue *temp = new Queue();
	temp = Front;
	Front = Front->next;
	temp->next = NULL;
	free(temp);
}
Cell front() {
	Cell c;
	c.a = Front->x;
	c.b = Front->y;
	return c;
}
int isEmpty() {
	return Front == NULL;
}
bool isValid(int tx, int ty, int n) {
	return (tx >= 0 && tx < n && ty >= 0 && ty < n);
}
void BFS(char Grid[MAX][MAX], int n, Cell src, Cell des) {
	bool vis[MAX][MAX];
	Cell Par[MAX][MAX];
	push(src.a, src.b);
	vis[src.a][src.b] = true;
	while (!isEmpty()) {
		Cell c = front();
		pop();
		int p = c.a;
		int q = c.b;
		for (int i = 0; i < 4; i++) {
			int tx = p + directionX[i];
			int ty = q + directionY[i];
			if (!vis[tx][ty] && (Grid[tx][ty] == '*' || Grid[tx][ty] == 'd') && isValid(tx, ty, n)) {
				push(tx, ty);
				vis[tx][ty] = true;
				Par[tx][ty].a = p;
				Par[tx][ty].b = q;
			}
		}
	}
	if (!vis[des.a][des.b]) {
		cout << -1 << endl;
	}
	else {
		int p = des.a;
		int q = des.b;
		cout << p << " ";
		cout << q << "\n";
		while (p != src.a && q != src.b) {
			int s = Par[p][q].a;
			int t = Par[p][q].b;
			cout << s << " ";
			cout << t << "\n";
			p = s;
			q = t;
		}
	}
}
int main() {
	int n;
	cin >> n;
	char Grid[MAX][MAX];
	Cell src, des;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Grid[i][j];
			if (Grid[i][j] == 's') {
				src.a = i;
				src.b = j;
			}
			else if (Grid[i][j] == 'd') {
				des.a = i;
				des.b = j;
			}
		}
	}
	BFS(Grid, n, src, des);
	return 0;
}
