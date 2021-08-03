#include <stdio.h>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 1e2+10;
const int T = 1e4+10;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
struct Point{
	int x, y, t;
};
int s[T], e[T], a[N][N], n, m;
bool b[N][N][T];
queue<Point> q;
int bfs() {
	q.push({1, 1, 0}); b[1][1][0] = 1;
	while(q.size()) {
		Point p = q.front(); q.pop();  // printf("%d %d %d\n", p.x, p.y, p.t);
		if(p.x == n && p.y == m) return p.t;
		for(int i = 0; i < 4; ++i) {
			int x = p.x + dx[i], y = p.y + dy[i], t = p.t + 1;
			if(x >= 1 && x <= n && y >= 1 && y <= m) {
				int dt = a[x][y];
				if(!b[x][y][t] && (dt == -1 || (dt >= 0 && (t < s[dt] || t > e[dt])))) {
					b[x][y][t] = 1; q.push({x, y, t});
				}
			}
		}
	}
	return -1;
}
int main() {
	int t; scanf("%d%d%d", &n, &m, &t);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			a[i][j] = -1;
			for(int k = 0; k < T; ++k) {
				b[i][j][k] = 0;
			}
		}
	}
	for(int i = 0; i < t; ++i) {
		int r, c; scanf("%d%d%d%d", &r, &c, &s[i], &e[i]);
		a[r][c] = i;
	}
	printf("%d\n", bfs());
	return 0;
}
