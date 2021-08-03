#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string s;
	cin>>s;
	string ss=s.substr(0,1)+s.substr(2,3)+s.substr(6,5);
	char target=s[s.size()-1];
	long res=0;
	for(int i=0;i<ss.size();i++)
		res+=((i+1)*(ss[i]-'0'));
	res%=11;
	if(res==10&&target=='X'||res==(target-'0'))
		cout<<"Right"<<endl;
	else{
		if(res==10)
			s[s.size()-1]='X';
		else
			s[s.size()-1]=res+'0';
		cout<<s<<endl;
	}
	return 0;
} 
