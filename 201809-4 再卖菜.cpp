#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int N = 3e2+10;
const int inf = 1e8;
int n, a[N], b[N], dis[N], vis[N];
vector<pair<int, int> > g[N];
queue<int> inq;
/*
2*b[1]<=s[2]-s[0]<=2*b[1]+1
3*b[i]<=s[i+1]-s[i-2]<=3*b[i]+2
2*b[n]<=s[n]-s[n-2]<=2*b[n]+1
a[i]>=1 ==> s[i]-s[i-1]>=1
求最小解 ==> 构造>=不等式跑最长路
*/
void addEdge(int u, int v, int w) {
    g[u].push_back({v, w});
}
void spfa(int s) {
    for(int i = 0; i <= n; ++i) {
        dis[i] = -inf; vis[i] = 0;
    }
    inq.push(s); dis[s] = 0; vis[s] = 1;
    while(inq.size()) {
        int u = inq.front(); inq.pop(); vis[u] = 0;
        for(auto e : g[u]) {
            int v = e.first, w = e.second;
            if(dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                if(!vis[v]) {
                    inq.push(v); vis[v] = 1;
                }
            }
        }
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    addEdge(0, 2, 2 * b[1]);
    addEdge(2, 0, -(2 * b[1] + 1));
    for(int i = 2; i <= n - 1; ++i) {
        addEdge(i - 2, i + 1, 3 * b[i]);
        addEdge(i + 1, i - 2, -(3 * b[i] + 2));
    }
    addEdge(n - 2, n, 2 * b[n]);
    addEdge(n, n - 2, -(2 * b[n] + 1));
    for(int i = 1; i <= n; ++i) addEdge(i - 1, i, 1);
    spfa(0);
    for(int i = 1; i <= n; ++i) printf("%d ", dis[i] - dis[i - 1]);
    printf("\n");
    return 0;
}
