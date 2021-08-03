#include <bits/stdc++.h>
using namespace std;
int a[20][20], b[5][5], c;
int main() {
	for(int i = 0; i < 15; ++i)
		for(int j = 0; j < 10; ++j)
			scanf("%d", &a[i][j]);
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			scanf("%d", &b[i][j]);
	scanf("%d", &c); c--;
	int down = 15;
	for(int j = 0; j < 4; ++j) {
		int cnt = 0, i;
		for(i = 3; i >= 0; --i) {
			if(!b[i][j]) cnt++;
			else break;
		}
		if(i < 0) continue;
		for(i = 4; i < 15; ++i) {
			if(!a[i][c+j]) cnt++;
			else break;
		}
		down = min(down, cnt);
	}
	for(int i = 0; i < 4; ++i) {
		if(i + down >= 15) break;
		for(int j = 0; j < 4; ++j) {
			a[i + down][j+c] |= b[i][j];
		}
	}
	for(int i = 0; i < 15; ++i) {
		for(int j = 0; j < 10; ++j) printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}
/*
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 1 0 0 0
1 1 1 0 0 0 1 1 1 1
0 0 0 0 0 0 0 0 0 0
0 0 0 1
0 1 1 1
0 0 0 0
0 0 0 0
3

*/
