#include <iostream>
using namespace std;

bool isSkip(int n){
	if (n % 7 == 0) return true;
	else{
		while(n != 0){
			int m = n % 10;
			n /= 10;
			if (m == 7) return true;
		}
	}
	return false;
}

int main(){
	int size = 4;
	int m, a[size];
	for (int i = 0; i < size; i++) a[i] = 0;
	cin >> m;
	int n = 0, b = -1, no = 1;
	while (n < m){
		b = (b + 1) % size;
		if (isSkip(no++)){
			a[b]++;
		}else{
			n++;
		}
	}
	for (int i = 0; i < size; i++){
		cout << a[i] << endl;
	}
	return 0;
}
