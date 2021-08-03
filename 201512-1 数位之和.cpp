#include <iostream>
#include <cstring>
using namespace std;

int n;
int main(){
	cin>>n;
	int res=0;
	while(n>0){
		res+=(n%10);
		n/=10;
	}
	cout<<res<<endl;
	return 0;
}
