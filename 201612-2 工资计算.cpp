#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, ans;
int main(){
	scanf("%d", &t);
	for(int i = 1; i <= 2000; ++i) {
		int s = i * 100, a = s - 3500;
		if(a <= 0) ans = s;
		else if(a <= 1500) ans = s - a * 3 / 100;
		else if(a <= 4500) ans = s - 45 - (a - 1500) / 10;
		else if(a <= 9000) ans = s - 45 - 300 - (a - 4500) / 5;
		else if(a <= 35000) ans = s - 45 - 300 - 900 - (a - 9000) / 4;
		else if(a <= 55000) ans = s - 45 - 300 - 900 - (35000 - 9000) / 4 - (a - 35000) * 3 / 10; 
		else if(a <= 80000) ans = s - 45 - 300 - 900 - (35000 - 9000) / 4 - 6000 - (a - 55000) * 35 / 100;
		else ans = s - 45 - 300 - 900 - (35000 - 9000) / 4 - 6000 - 250 * 35 - (a - 80000) * 45 / 100;
		if(ans == t) {
			printf("%d\n", s);
			break;
		}
	}
	return 0;
}
