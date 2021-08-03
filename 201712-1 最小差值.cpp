#include <iostream>
#include <algorithm>
using namespace std;
const int N=1000+5;
int a[N];
int main(){
	int n,ans=10001;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
		if((a[i+1]-a[i])<ans)
			ans=a[i+1]-a[i];
	cout<<ans<<endl;
	return 0;
} 
