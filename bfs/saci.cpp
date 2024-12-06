#include"bits/stdc++.h"
#define MAX 1002

int mat[MAX][MAX]={0};
int resp=10000000;
using namespace std;

void bfs(int i, int j, int dist){
	
	if(mat[i+1][j] == 1){
		mat[i+1][j] = 0;
		bfs(i + 1, j, dist + 1);
		mat[i+1][j] = 1;
	}
	else if(mat[i+1][j] == 3)
		resp = min(resp, dist);
	
	
	if(mat[i-1][j] == 1){
		mat[i-1][j] = 0;
		bfs(i - 1, j, dist + 1);
		mat[i-1][j] = 1;
	}
	else if(mat[i-1][j] == 3)
		resp = min(resp, dist);
	
	if(mat[i][j-1] == 1){
		mat[i][j-1] = 0;
		bfs(i, j - 1, dist + 1);
		mat[i][j-1] = 1;
	}
	else if(mat[i][j-1] == 3)
		resp = min(resp, dist);
	
	if(mat[i][j+1] == 1){
		mat[i][j+1] = 0;
		bfs(i, j + 1, dist + 1);
		mat[i][j+1] = 1;
	}
	else if(mat[i][j+1] == 3)
		resp = min(resp, dist);
	
}

int main(){
	int N, M;
	int x,y;
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cin >> mat[i][j];
			
			if(mat[i][j] == 2){
				x = i;
				y = j;	
			}
			
		}
	}
	
	bfs(x, y, 0);
	cout << resp + 2 << endl;
	return 0;
}