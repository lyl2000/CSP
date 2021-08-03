#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 5e4+20;
const int M = 1e5+20;
struct Edge {
    int u, v, w;
    bool operator < (const Edge& e) const {
        return w < e.w;
    }
}edge[M];
int root[N], sz[N], n, m;
int fd(int x) {
    if(root[x] == x) return x;
    return root[x] = fd(root[x]);
}
bool unite(int a, int b) {
    a = fd(a); b = fd(b);
    if(a == b) return false;
    if(sz[a] < sz[b]) { root[a] = b; sz[b] += sz[a]; }
    else { root[b] = a; sz[a] += sz[b]; }
    return true;
}
bool check(int mid) {
    for(int i = 1; i <= n; ++i) {
        root[i] = i; sz[i] = 1;
    }
    int num = n;
    for(int i = 1; i <= m; ++i) {
        Edge e = edge[i];
        if(e.w > mid) break;
        if(unite(e.u, e.v)) num--;
        if(num == 1) break;
    }
    return num == 1;
}
int main() {
    int r, maxw = 0; scanf("%d%d%d" ,&n, &m, &r);
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
        maxw = max(maxw, edge[i].w);
    }
    sort(edge + 1, edge + m + 1);
    int le = 1, ri = maxw, ans = maxw;
    while(le <= ri) {
        int mid = (le + ri) >> 1;
        if(check(mid)) { ri = mid - 1; ans = mid; }
        else { le = mid + 1; }
    }
    printf("%d\n", ans);
    return 0;
}
