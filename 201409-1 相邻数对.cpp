#include <iostream>
#include <algorithm>
using namespace std;

const int N=1000+10;
int a[N],n;
int main(){
	int res=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		if(a[i]-a[i-1]==1)
			res++;
	}
	cout<<res<<endl;
	return 0;
}
