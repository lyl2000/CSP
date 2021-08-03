#include <iostream>
using namespace std;
const int N=1000+5;
int a[N],b[N],n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		if(i==0)
			b[0]=(a[0]+a[1])/2;
		else if(i==n-1)
			b[n-1]=(a[n-2]+a[n-1])/2;
		else
			b[i]=(a[i-1]+a[i]+a[i+1])/3;
		cout<<b[i]<<' ';
	}
	cout<<endl;
	return 0;
} 
