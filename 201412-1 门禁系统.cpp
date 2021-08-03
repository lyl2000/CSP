#include <iostream>
#include <cstring>
using namespace std;

const int N=1000+10;
int a[N],n;
int main(){
	memset(a,0,sizeof(a));
	int temp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		a[temp]++;
		cout<<a[temp]<<' ';
	}
	cout<<endl;
	return 0;
}
