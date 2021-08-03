#include <stdio.h>
#include <vector>
using namespace std;
const int N = 1e4+20;
int n, m, c[N], scc[N], dfn[N], vis[N], dcnt, scnt;
// scc编号 scc内数量 dfs后序列中点 用于dfs dfs序计数 scc计数
vector<int> g[N], g1[N];
void dfs1(int v) {  // 在正图里找dfs后序列
    vis[v] = 1;
    for(auto u : g[v]) {
        if(!vis[u]) dfs1(u);
    }
    dfn[++dcnt] = v;
}
void dfs2(int v) {  // 根据逆后序序列在反图里找scc
    c[v] = scnt;
    scc[scnt]++;
    for(auto u : g1[v]) {
        if(!c[u]) dfs2(u);
    }
}
void kosaraju() {
    dcnt = scnt = 0;
    for(int i = 1; i <= n; ++i) {
        c[i] = 0; vis[i] = 0; scc[i] = 0;
    }
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) dfs1(i);
    }
    for(int i = n; i >= 0; i--) {
        if(!c[dfn[i]]) {
            ++scnt;
            dfs2(dfn[i]);
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int a, b; scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g1[b].push_back(a);
    }
    kosaraju();
    int ans = 0;
    for(int i = 1; i <= scnt; ++i) {
        ans += scc[i] * (scc[i] - 1) / 2;
    }
    printf("%d\n", ans);
    return 0;
}
