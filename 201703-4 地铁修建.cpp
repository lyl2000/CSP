#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5+20;
const int M = 2e5+20;
const int INF = 1e8;
vector<pair<int, int> > g[N];
priority_queue<pair<int, int> > heap;
int vis[N], dis[N], n, m;
void dij(int s) {
    for(int i = 1; i <= n; ++i) {
        vis[i] = 0; dis[i] = INF;
    }
    heap.push({0, s}); dis[s] = 0;
    while(heap.size()) {
        auto e = heap.top(); heap.pop();
        if(vis[e.second]) continue;
        vis[e.second] = 1;
        for(auto v : g[e.second]) {
            if(dis[v.first] > max(dis[e.second], v.second)) {
                dis[v.first] = max(dis[e.second], v.second);
                heap.push({-dis[v.first], v.first});
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    dij(1);
    printf("%d\n", dis[n]);
    return 0;
}
