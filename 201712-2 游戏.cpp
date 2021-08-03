#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2+20;
int n, k;
queue<int> q;
int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		q.push(i);
	}
	int ans, t = 1;
	while(q.size()) {
		ans = q.front(); q.pop();
		if(t % k == 0 || t % 10 == k);
		else q.push(ans);
		t++;
	}
	printf("%d\n", ans);
	return 0;
}
