#include <iostream>
#include <cstring>
using namespace std;
/*3 3
73 -8 -6 -4
76 -5 -10 -8
80 -6 -15 0*/
int main(){
	int N, M, T = 0, k = 0, P = 0;
	cin >> N >> M;
	int *apple_sum = new int [M+1];
	int *cut_num = new int [N];
	int *last_num = new int [N];
	memset(cut_num, 0, sizeof(cut_num[0])*N);
	memset(last_num, 0, sizeof(last_num[0])*N);
	for(int i = 0; i < N; i++){
		cin >> apple_sum[0];
		for(int j = 1; j <= M; j++){
			cin >> apple_sum[j];
			cut_num[i] -= apple_sum[j];
			apple_sum[0] += apple_sum[j];
		}
		last_num[i] = apple_sum[0];
	}
	for(int i = 0; i < N; i++){
		T += last_num[i];
		if(cut_num[i] > P){
			k = i;
			P = cut_num[i];
		}
	}
	cout << T << " " << k+1 << " " << P << endl;
	delete [] apple_sum;
	delete [] cut_num;
	delete [] last_num;
	return 0;
}
