#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int MAX = 110;

int n, m;
char M[MAX][MAX];
int vis[MAX][MAX];

ii mov[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool val(int i, int j){
	return i >= 0 && j >= 0 && i < n && j < m && !vis[i][j] && M[i][j] == 'H';
}

ii bfs(int i, int j){
	queue<ii> q;
	q.push({i, j});
	vis[i][j] = 1;

	ii ret;
	while(!q.empty()){
		ret = q.front(); q.pop();
		for(int k=0; k<4; k++){
			int new_i = ret.first+mov[k].first, new_j = ret.second+mov[k].second;
			if(val(new_i, new_j))
				q.push({new_i, new_j}), vis[new_i][new_j]=1;
		}
	}
	return ret;
}

int main() { 

	memset(vis, 0, sizeof vis);

	cin >> n >> m;
	for(int i=0;i <n; i++) {
        for(int j=0; j<m; j++) cin >> M[i][j];
    } 

	ii ans;
	for(int i=0;i <n; i++) {
        for(int j=0; j<m; j++){
            if(M[i][j] == 'o') ans = bfs(i, j);
        } 
    }
	
	cout << ans.first + 1 << " " << ans.second + 1 << endl;
	return 0;
}