#include <iostream>
#include <cstring>
using namespace std;

const int N=1000+10;
int a[N][N],m,n;
int main(){
	cin>>m>>n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	for(int j=n-1;j>=0;j--){
		for(int i=0;i<m;i++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
