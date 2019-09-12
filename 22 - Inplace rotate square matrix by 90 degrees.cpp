#include <iostream>
using namespace std;
const int MAX = 100;
int N,M[MAX][MAX];
void rotateMatrix(){
	// Consider all squares one by one
	for(int x=0; x<N/2; x++){
		// Consider elements in group of 4 in
		// current square
		for(int y=x; y<N-x-1; y++){
			// store current cell in temp variable
			int temp = M[x][y];
			// move values from right to top
			M[x][y] = M[y][N-x-1];
			// move values from bottom to right
			M[y][N-x-1] = M[N-x-1][N-y-1];
			// move values from left to bottom
			M[N-x-1][N-y-1] = M[N-y-1][x];
			// assign temp to left
			M[N-y-1][x] = temp;
		}
	}
}
// Function to print the matrix
void displayMatrix(){
    printf("\n");
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			printf("%d ",M[i][j]);
		}
		printf("\n");
	}
}
int main(){
    int t; cin>>t;
    while(t--){
        cin>>N;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>M[i][j];
            }
        }
        rotateMatrix();
        // Print rotated matrix
        displayMatrix();
    }
	return 0;
}
