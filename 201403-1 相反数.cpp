#include <iostream>
#include <cstring>
using namespace std;

const int N=1000+10;
bool a[N];
int main(){
	memset(a,0,sizeof(a));
	int n,temp,res=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		temp=(temp>0)?temp:-temp;
		if(a[temp])
			res++;
		else
			a[temp]=true;
	}
	cout<<res<<endl;
	return 0;
}
