#include <iostream>
#include <string>
#include <stack>
using namespace std;

int level(char op){
	if(op=='+'||op=='-') return 1;
	else if(op=='x'||op=='/') return 2;
	return 0;
}

int main(){
	int n;
	cin>>n;
	while(n--){
		string str;
		cin>>str;
		stack<char> op;
		stack<int> num;
		int i=0,len=str.length();
		while(!op.empty()||i<len){
			if(str[i]>='0'&&str[i]<='9'){
				num.push(str[i]-'0');
				i++;
			}else{
				if(op.empty()||level(op.top())<level(str[i])){
					op.push(str[i]);
					i++;
				}else if(i==len&&!op.empty()||level(op.top())>=level(str[i])){
					int b=num.top(); num.pop();
					int a=num.top(); num.pop();
					char oper=op.top(); op.pop();
					if(oper=='+') num.push(a+b);
					else if(oper=='-') num.push(a-b);
					else if(oper=='x') num.push(a*b);
					else if(oper=='/') num.push(a/b); 
				}
			}
		}
		cout<<((num.top()==24)?"Yes":"No")<<endl;
	}
	return 0;
}
