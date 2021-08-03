#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3+20;
struct Ky{
	int t, op, no;  // 还0 取1  还的优先级高 
	Ky() {}
	Ky(int _t, int _op, int _no) : t(_t), op(_op), no(_no) {}
	bool operator < (const Ky& ky) const {
		if(t != ky.t) return t > ky.t;
		if(op != ky.op) return op > ky.op;
		return no > ky.no;
	}
};
int n, k, w, s, c, ans[N];
priority_queue<Ky> heap;
int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) ans[i] = i;
	for(int i = 0; i < k; ++i) {
		scanf("%d%d%d", &w, &s, &c);
		heap.push(Ky(s, 1, w));
		heap.push(Ky(s+c, 0, w));
	}
	while(heap.size()) {
		auto now = heap.top(); heap.pop();
		if(now.op) {
			for(int i = 1; i <= n; ++i) {
				if(ans[i] == now.no) {
					ans[i] = -1; break;
				}
			}
		} else {
			for(int i = 1; i <= n; ++i) {
				if(ans[i] == -1) {
					ans[i] = now.no; break;
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		printf("%d%c", ans[i], (i == n) ? '\n' : ' ');
	}
	return 0;
}
