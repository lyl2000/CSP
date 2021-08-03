#include <iostream>
#include <string.h>
#include <map> 
#include <algorithm>
using namespace std;
bool isRen(int y){
	if(!(y%4)&&(y%100)||!(y%400)) return true;
	return false;
}
int main(){
	int y,d,b=1,c;
	cin>>y>>d;
	int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(isRen(y))
		a[1]++;
	for(int i=0;i<12;i++){
		if(d-a[i]<=0){
			c=d;
			break;
		}
		d-=a[i];
		b++;
	}
	cout<<b<<"\n"<<c<<endl;
	return 0;
} 
