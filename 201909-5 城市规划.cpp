#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 5e4+20;
const int K = 1e2+20;
const ll inf = 1e14;
bool tag[N];  // 重要结点 
vector<pair<int, int> > g[N];
int cnt[N], n, m, k;  // 存储以i为结点的子树中重要结点的个数 
ll dp[N][K];  // 以v为根的子树中选取s个结点的最小路径和 
void dfs(int v, int f) {
	dp[v][0] = 0;
	if(tag[v]) {
		dp[v][1] = 0;
		cnt[v]++;
	}
	for(int i = 0, len = g[v].size(); i < len; ++i) {
		int u = g[v][i].first, w = g[v][i].second;
		if(u == f) continue;  // 父节点
		dfs(u, v);
		cnt[v] += cnt[u];
		for(int j = min(k, cnt[v]); j >= 0; --j) {
			for(int l = 0; l <= j && l <= min(k, cnt[u]); ++l) {
				dp[v][j] = min(dp[v][j], dp[u][l] + dp[v][j - l] + (ll)l * (k - l) * w);
			}
		} 
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i) {
		tag[i] = 0; cnt[i] = 0;
		for(int j = 0; j < K; ++j) dp[i][j] = inf;
	}
	for(int i = 0; i < m; ++i) {
		int x; scanf("%d", &x); tag[x] = 1;
	}
	for(int i = 0; i < n - 1; ++i) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		g[a].push_back({b, c});
		g[b].push_back({a, c});  // 无向
	}
	dfs(1, -1);  // 默认根为1号结点 
	printf("%lld\n", dp[1][k]);
	return 0;
}
/*
5 3 2
1 3 5
1 2 4
1 3 5
1 4 3
4 5 1

*/
