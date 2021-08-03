#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int r, y, g, n;
int main() {
	scanf("%d %d %d", &r, &y, &g);
	ll tot = r + y + g;
	scanf("%d", &n);
	ll now = 0;
	for(int i = 0; i < n; ++i) {
		int k, t; scanf("%d %d", &k, &t);
		if(k == 0) {
			now = now + t;
			continue;
		}
		ll tmp;
		if(k == 1) tmp = ((now-t-g)%tot+tot)%tot;
		else if(k == 2) tmp = ((now-t-r-g)%tot+tot)%tot;
		else if(k == 3) tmp = ((now-t)%tot+tot)%tot;
		now += max(0ll, y+r-tmp);
//		printf("now = %lld\n", now);
	}
	printf("%lld\n", now);
    return 0;
}
/*
30 3 30
8
0 73
1 5
0 11
2 2
0 6
0 3
3 10
0 3

*/
