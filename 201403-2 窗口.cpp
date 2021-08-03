#include <iostream>
#include <algorithm>
using namespace std;
int a[10][4],b[10];
int main(){
	int N,M,x,y;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
		b[i]=i;
	}
	for(int i=0;i<M;i++){
		cin>>x>>y;
		bool isFound=false;
		for(int j=N-1;j>=0;j--){
			if(x>=a[b[j]][0]&&y>=a[b[j]][1]&&x<=a[b[j]][2]&&y<=a[b[j]][3]){
				cout<<b[j]+1<<endl;
				int temp=b[j];
				for(int k=j+1;k<N;k++)
					b[k-1]=b[k];
				b[N-1]=temp;
				isFound=true;
				break;
			}
		}
		if(!isFound) cout<<"IGNORED"<<endl;
	}
	return 0;
} 
