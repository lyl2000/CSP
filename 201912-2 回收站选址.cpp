#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int dxx[] = {-1, -1, 1, 1};
const int dyy[] = {-1, 1, -1, 1};
int n;
map<pair<int, int>, bool> p, b;
int sc[5];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int x, y; scanf("%d %d", &x, &y);
		p[{x, y}] = 1; b[{x, y}] = 1;
	}
	memset(sc, 0, sizeof(sc));
	for(auto it : b) {
		auto pos = it.first;
		int x = pos.first, y = pos.second;
//		printf("%d %d %d %d\n", x, y, it.second, p.size());
		bool is = 1;
		for(int i = 0; i < 4; ++i) {
			int xx = x + dx[i], yy = y + dy[i];
			if(!p[{xx, yy}]) is = 0;
		}
		if(!is) continue;
		int cnt = 0;
		for(int i = 0; i < 4; ++i) {
			int xx = x + dxx[i], yy = y + dyy[i];
			if(p[{xx, yy}]) cnt++;
		}
		sc[cnt]++;
	}
	for(int i = 0; i < 5; ++i) {
		printf("%d\n", sc[i]);
	}
    return 0;
}
/*
7
1 2
2 1
0 0
1 1
1 0
2 0
0 1

2
0 0
-100000 10

11
9 10
10 10
11 10
12 10
13 10
11 9
11 8
12 9
10 9
10 11
12 11

*/
