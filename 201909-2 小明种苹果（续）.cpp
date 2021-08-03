#include <iostream>
#include <string.h>
using namespace std;
int a[1005],b[1005];
int main(){
	int N,m,T=0,D=0,E=0,temp;
	memset(b,0,sizeof(b));
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>m;
		bool isOne=true;
		for(int j=0;j<m;j++){
			cin>>a[j];
			if(a[j]>0&&isOne){
				temp=a[j];
				isOne=!isOne;
			}else if(a[j]>0&&!isOne){
				if(a[j]<temp&&!b[i]){
					b[i]=1;  //µÚi¿ÃÊ÷µô¹û×Ó
					D++;
				}
				temp=a[j];
			}else{
				temp+=a[j];
			}
		}
		T+=temp;
	}
	if(b[N-1]&&b[0]&&b[1]) E++;
	if(b[N-2]&&b[N-1]&&b[0]) E++;
	for(int i=1;i<N-1;i++)
		if(b[i-1]&&b[i]&&b[i+1]) E++;
	cout<<T<<' '<<D<<' '<<E<<endl;
	return 0;
}
/*
5
4 10 0 9 0
4 10 -2 7 0
2 10 0
4 10 -3 5 0
4 10 -1 8 0
39 4 2

4
4 74 -7 -12 -5
5 73 -8 -6 59 -4
5 76 -5 -10 60 -2
5 80 -6 -15 59 0

*/
