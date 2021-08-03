#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int a[500][500];
int main(){
	int n,x=0,y=0;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	cout<<a[x][y]<<' ';
	y++;
	//start with a[0][1]
	int step=1,sign=1,mark=1;
	for(int cnt=0;cnt<2*n-2;cnt++){
		cout<<a[x][y]<<' ';
		//内部循环 
		for(int i=0;i<step;i++){
			x+=sign;
			y-=sign;
			cout<<a[x][y]<<' ';
		}
		step+=mark;
		//只执行一次 
		if(step==n){
			step-=2;
			mark=-mark;
		}
		if(sign==mark){
			x++;
		}else if(sign==-mark){
			y++; 
		}
		sign=-sign;
	}
	return 0;
} 
