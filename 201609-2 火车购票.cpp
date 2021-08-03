#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, p, a[20];
int main(){
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	while(n--) {
		scanf("%d", &p);
		for(int i = 0; i < 20 && p; ++i) {
			if(5 - a[i] >= p) {
				for(int j = a[i] + 1; j <= a[i] + p; ++j) {
					printf("%d ", i*5+j);
				}
				a[i] += p; p = 0;
			}
		}
		for(int i = 0; i < 20 && p; ++i) {
			int tmp = 5 - a[i];
			if(tmp <= p) {
				for(int j = a[i] + 1; j <= 5; ++j) {
					printf("%d ", i*5+j);
				}
				a[i] += tmp; p -= tmp;
			} else {
				for(int j = a[i] + 1; j <= a[i] + p; ++j) {
					printf("%d ", i*5+j);
				}
				a[i] += p; p = 0;
			}
		}
		printf("\n");
	}
	return 0;
}#include <bits/stdc++.h>
using namespace std;

int main() {

    return 0;
}

