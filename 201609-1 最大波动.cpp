#include <iostream>
#include <cmath>
using namespace std;

const int N=1000+10;
int a[N],n;
int main(){
	int res=0;
	cin>>n;
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		int temp=abs(a[i]-a[i-1]);
		if(temp>res)
			res=temp;
	}
	cout<<res<<endl;
	return 0;
}
