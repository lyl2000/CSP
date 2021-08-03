#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int a[100][100];
int main(){
	memset(a,0,sizeof(a));
	int n,x1,y1,x2,y2,ans=0;
	cin>>n;
	while(n--){
		cin>>x1>>y1>>x2>>y2;
		for(int i=x1;i<x2;i++)
			for(int j=y1;j<y2;j++)
				if(!a[i][j]){
					a[i][j]=1;
					ans++;
				}
	}
	cout<<ans<<endl;
	return 0;
} 
