#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int N = 105;
struct Point{
	int x, y;
	Point(int _x, int _y):x(_x), y(_y){}
};
int fil[N][N];
int m, n, q;
queue<Point> qu;

void Fill(int x, int y, char sign){
	//(x, y)为起点填充整个画布 
	if(fil[x][y] >= -1 && fil[x][y] != sign-'A'){
		qu.push(Point(x, y));
		fil[x][y] = sign-'A';
	}
	while(!qu.empty()){
		Point p = qu.front();
		qu.pop();
		for(int i = 0; i < 4; ++i){
			int tx = p.x+dx[i], ty = p.y+dy[i];
			if(tx>=0 && tx<m && ty>=0 && ty<n && fil[tx][ty]>=-1 && fil[tx][ty]!=sign-'A'){
				qu.push(Point(tx, ty));
				fil[tx][ty] = sign-'A';
			}
		}
	}
}

void DrawLine(int x1, int y1, int x2, int y2){
	if(x1 == x2){
		if(y1 > y2){  //确保y1 < y2 
			int temp = y1;
			y1 = y2;
			y2 = temp;
		}
		for(int i = y1; i <= y2; ++i){
			if(fil[x1][i] == -3 || fil[x1][i] == -4) fil[x1][i] = -4;  //注意=-4时 
			else fil[x1][i] = -2;  //-2代表|
		}
	}else if(y1 ==y2){
		if(x1 > x2){  //确保x1 < x2 
			int temp = x1;
			x1 = x2;
			x2 = temp;
		}
		for(int i = x1; i <= x2; ++i){
			if(fil[i][y1] == -2 || fil[i][y1] == -4) fil[i][y1] = -4;  //-4代表+ 
			else fil[i][y1] = -3;  //-3代表-
		}
	}
}

int main(){
	scanf("%d %d %d", &m, &n, &q);
	memset(fil, -1, sizeof(fil));  //初始为-1 代表. 
	for(int i = 0; i < q; ++i){
		bool oper;
		scanf("%d", &oper);
		if(oper == 1){
			int x, y;
			char c;
			scanf("%d %d %c", &x, &y, &c);
			while(!qu.empty()) qu.pop();
			Fill(x, y, c);
		}else if(oper == 0){
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			DrawLine(x1, y1, x2, y2);
		}
	}
	for(int j = n-1; j >= 0; --j){
		for(int i = 0; i < m; ++i){
			if(fil[i][j] == -1) printf(".");
			else if(fil[i][j] == -2) printf("|");
			else if(fil[i][j] == -3) printf("-");
			else if(fil[i][j] == -4) printf("+");
			else printf("%c", fil[i][j]+'A');
		}
		printf("\n");
	}
	return 0;
} 
