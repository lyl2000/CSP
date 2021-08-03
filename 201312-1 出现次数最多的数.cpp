#include <iostream>
#include <cstring>
using namespace std;

const int N=10000+10;
int a[N];
int main(){
	memset(a,0,sizeof(a));
	int n,temp;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>temp;
		a[temp]++;
	}
	int num=0,res=0;
	for(int i=0;i<N;i++){
		if(a[i]>num){
			num=a[i];
			res=i;
		}
	}
	cout<<res<<endl;
	return 0;
}
