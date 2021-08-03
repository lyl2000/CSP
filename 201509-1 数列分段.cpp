#include <iostream>
#include <cstring>
using namespace std;

const int N=1000+10;
int a[N],n;
int main(){
	cin>>n;
	int res=1;
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1])
			res++;
	}
	cout<<res<<endl;
	return 0;
}
