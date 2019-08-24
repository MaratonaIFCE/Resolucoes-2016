#include <iostream>
#include <algorithm>  

using namespace std;


int visitados[200][200];
int matriz[200][200];
int h, l;


int valido(int x, int y) {
	if(x < h && x >= 0 && y < l && y >= 0) return 1;
	return 0;		
}

int dfs(int x, int y, int v);

int main() {
	cin>>h>>l;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < l; j++) {
			cin>>matriz[i][j];
			
		}
	}
	
	int inf = 200*200;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < l; j++) {
			if(visitados[i][j] == 0)
				inf = min(inf, dfs(i, j, matriz[i][j]));
			
		}
	}
	cout<<inf<<endl;			
		
	return 0;
}

int dfs(int x, int y, int v) {
	int tam = 1;
	int	dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
	visitados[x][y] = 1;
	for(int i = 0; i < 4; i++) {
		int newX  = x + dir[i][0];
		int newY = y + dir[i][1];
		if(valido(newX, newY) && matriz[newX][newY] == v && visitados[newX][newY] == 0) {
			tam += dfs(newX, newY, v);
		}
	}
	return tam;
}
