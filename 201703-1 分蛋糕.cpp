#include <iostream>
#include <algorithm>
using namespace std;

const int N=1000+10;
int a[N];
int main(){
	int n,k,res=1,temp=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		temp+=a[i];
		if(temp>=k&&i<n-1){
			temp=0;
			res++;
		}
	}
	cout<<res<<endl;
	return 0;
}
