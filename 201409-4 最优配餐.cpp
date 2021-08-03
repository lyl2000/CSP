#include <stdio.h>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 1e3+20;
int n, a[N][N], b[N][N], cnt;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
struct Point{
	int x, y;
	Point() {}
	Point(int _x, int _y) : x(_x), y(_y) {}
}h[N * N];
queue<Point> q;
ll bfs() {
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			b[i][j] = -1;  // 没走过 
		}
	}
	ll ans = 0;
	for(int i = 0; i < cnt; ++i) {
		q.push(h[i]); b[h[i].x][h[i].y] = 0;
	}
	while(q.size()) {
		Point p = q.front(); q.pop();
		int x = p.x, y = p.y;
		if(a[x][y] > 0) ans = ans + b[x][y] * a[x][y];
		for(int i = 0; i < 4; ++i) {
			int Dx = x + dx[i], Dy = y + dy[i];
			if(Dx >= 1 && Dx <= n && Dy >= 1 && Dy <= n) {
				if(a[Dx][Dy] != -2 && b[Dx][Dy] == -1) {
					b[Dx][Dy] = b[x][y] + 1;
					q.push(Point(Dx, Dy));
				}
			}
		}
	}
	return ans;
}
int main() {
	int m, k, d, x, y, c;
	scanf("%d%d%d%d", &n, &m, &k, &d);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			a[i][j] = -1;  // 空白 
		}
	}
	cnt = 0;
	for(int i = 0; i < m; ++i) {
		scanf("%d%d", &x, &y);
		a[x][y] = 0;  // 分店 
		h[cnt++] = Point(x, y);
	}
	for(int i = 0; i < k; ++i) {
		scanf("%d%d%d", &x, &y, &c);
		a[x][y] = c;
	}
	for(int i = 0; i < d; ++i) {
		scanf("%d%d", &x, &y);
		a[x][y] = -2;  // 有障碍 
	}
	printf("%lld\n", bfs());
	return 0;
} 
