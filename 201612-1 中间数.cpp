#include <iostream>
#include <algorithm>
using namespace std;

const int N=1000+10;
int a[N];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int res=-1,s,e;
	s=e=n/2;
	while(a[s]==a[n/2]) s--;
	while(a[e]==a[n/2]) e++;
	if(s+1==n-e) res=a[n/2];
	cout<<res<<endl;
	return 0;
}
