#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3+20;
int a[N], heap[N], p, le[N], ri[N];
int n;
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		le[i] = 0; ri[i] = n - 1;
	}
	p = 0;
	for(int i = 0; i < n; ++i) {
		while(p > 0 && a[heap[p]] > a[i]) {
			ri[heap[p--]] = i - 1;
		}
		heap[++p] = i;
	}
	p = 0;
	for(int i = n - 1; i >= 0; --i) {
		while(p > 0 && a[heap[p]] > a[i]) {
			le[heap[p--]] = i + 1;
		}
		heap[++p] = i;
	}
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		ans = max(ans, a[i] * (ri[i] - le[i] + 1));
	}
	printf("%d\n", ans);
	return 0;
}
