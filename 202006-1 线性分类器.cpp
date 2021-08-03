#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+20;
struct Point{
	int x, y;
	char type;
}p[N];
int n, m; 
int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) {
		scanf("%d %d %c", &p[i].x, &p[i].y, &p[i].type);
	}
	for(int i = 0; i < m; ++i) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		if(t3 < 0) {
			t1 = -t1; t2 = -t2; t3 = -t3;
		}
		int a = 0, b = 0;
		bool has = 0;
		for(int j = 0; j < n; ++j) {
//			printf("x=%d y=%d type=%c\n", p[j].x, p[j].y, p[j].type);
			int tmp = t1 + t2 * p[j].x + t3 * p[j].y;
			if(p[j].type == 'A') {
				if(a != 0 && a * tmp < 0) has = 1;
				else a = (tmp > 0) ? 1 : -1; 
			} else if(p[j].type == 'B') {
				if(b != 0 && b * tmp < 0) has = 1;
				else b = (tmp > 0) ? 1 : -1; 
			}
//			printf("tmp=%d a=%d b=%d has=%d\n\n", tmp, a, b, has);
		}
		if(has) printf("No\n");
		else printf("Yes\n");
	}
    return 0;
}
/*
9 3
1 1 A
1 0 A
1 -1 A
2 2 B
2 3 B
0 1 A
3 1 B
1 3 B
2 0 A
0 2 -3
-3 0 2
-3 1 1

*/
