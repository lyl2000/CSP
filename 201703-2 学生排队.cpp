#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3+20;
int n, m, p, q, a[N], b[N];
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) a[i] = b[i] = i;
	while(m--) {
		scanf("%d%d", &p, &q);
		int pos = b[p];
		if(q < 0) {
			for(int i = pos; i > pos + q; --i) {
				a[i] = a[i-1]; b[a[i]]++;
			} a[pos + q] = p; b[p] = pos + q;
		} else {
			for(int i = pos; i < pos + q; ++i) {
				a[i] = a[i+1]; b[a[i]]--;
			} a[pos + q] = p; b[p] = pos + q;
		}
	}
	for(int i = 1; i <= n; ++i) {
		printf("%d%c", a[i], i == n ? '\n' : ' ');
	}
	return 0;
}
