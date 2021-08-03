#include <iostream>
using namespace std;

long long f(long long x){
	long long y = 2009731336725594113;
	return (x % y) % 2019;
}

int main(){
	long long U[5];
	U[0] = 314882150829468584, 
	U[1] = 427197303358170108, 
	U[2] = 1022292690726729920, 
	U[3] = 1698479428772363217, 
	U[4] = 2006101093849356424;
	
	int n, q, l, r;
	cin >> n >> q;
	long long a[n+1];
	for (int i = 1; i <= n; i++) a[i] = i;
	for (int i = 0; i < q; i++){
		cin >> l >> r;
		long long s = 0;
		for (int j = l; j <= r; j++){
			s += f(a[j]);
		}
		cout << s << endl;
		int t = (s % 5);
		for (int j = l; j <= r; j++){
			a[j] *= U[t];
		}
	}
	return 0;
}
