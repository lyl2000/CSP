#include <iostream>
#include <string.h>
#include <map> 
#include <algorithm>
using namespace std;
const int N=1005;
struct num{
	int a,b;
	bool operator<(const num &d){
		if(b!=d.b) return b>d.b;
		return a<d.a;
	}
}c[N];
int main(){
	int n,temp;
	cin>>n;
	for(int i=0;i<N;i++){
		c[i].a=i;
		c[i].b=0;
	}
	for(int i=0;i<n;i++){
		cin>>temp;
		c[temp].b++;
	}
	sort(c,c+N);
	for(int i=0;i<N;i++){
		if(c[i].b==0) break;
		cout<<c[i].a<<' '<<c[i].b<<endl;
	}
	return 0;
} 
