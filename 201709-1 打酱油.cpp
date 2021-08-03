#include <iostream>
using namespace std;

int main(){
	int N,p=10,c1=5,d1=2,c2=3,d2=1,res=0;
	cin>>N;
	N/=p;
	while(N/c1){
		res+=(c1+d1)*(N/c1);
		N%=c1;
	}
	while(N/c2){
		res+=(c2+d2)*(N/c2);
		N%=c2;
	}
	res+=N;
	cout<<res<<endl;
	return 0;
}
