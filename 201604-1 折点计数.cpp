#include <iostream>
#include <cstring>
using namespace std;

const int N=1000+10;
int a[N],n;
int main(){
	int res=0;
	cin>>n;
	if(n>=3){
		cin>>a[0]>>a[1];
		for(int i=2;i<n;i++){
			cin>>a[i];
			if((a[i-1]-a[i-2])*(a[i]-a[i-1])<0)
				res++;
		}
	}
	cout<<res<<endl;
	return 0;
}
