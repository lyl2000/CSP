#include <iostream>
#include <string.h>
#include <map> 
#include <algorithm>
using namespace std;
const int N=30+5;
struct qizi{
	int color,mark;
}a[N][N];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j].color;
			a[i][j].mark=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0&&j==0||i==0&&j==m-1||i==n-1&&j==0||i==n-1&&j==m-1) continue;
			if(i>0&&a[i][j].color==a[i-1][j].color&&i<n-1&&a[i][j].color==a[i+1][j].color){
				a[i][j].mark=1;
				a[i-1][j].mark=1;
				a[i+1][j].mark=1;
			}
			if(j>0&&a[i][j].color==a[i][j-1].color&&j<m-1&&a[i][j].color==a[i][j+1].color){
				a[i][j].mark=1;
				a[i][j-1].mark=1;
				a[i][j+1].mark=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j].mark) a[i][j].color=0;
			cout<<a[i][j].color<<' ';
		}
		cout<<endl;
	}
	return 0;
} 
