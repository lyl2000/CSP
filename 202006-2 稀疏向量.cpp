#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a, b;
map<int, int> va;
int main() {
	scanf("%d %d %d", &n, &a, &b);
	ll ans = 0;
	for(int i = 0; i < a; ++i) {
		int idx, v; scanf("%d %d", &idx, &v);
		va[idx] = v;
	}
	for(int i = 0; i < b; ++i) {
		int idx, v; scanf("%d %d", &idx, &v);
		ans += v * va[idx];
	}
	printf("%lld\n", ans);
    return 0;
}
/*
10 3 4
4 5
7 -3
10 1
1 10
4 20
5 30
7 40

*/
