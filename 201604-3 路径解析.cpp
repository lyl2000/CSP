#include <iostream>
#include <string>
using namespace std;

const int N = 1000+5;
string nowPath[N], ndPath[N];  //��ǰĿ¼ 
int n;

int main(){
	string getstr, tempstr;
	int p, len; cin >> p;  //���� 
	
	cin >> getstr; n = 0;
	len = getstr.length();
	for(int i = 1; i < len; ++i){  //��1��ʼ��0--/ 
		if(getstr[i] == '/'){
			nowPath[n++] = tempstr;
			tempstr = "";
		}else{
			tempstr += getstr[i];
		}
	}
	if(tempstr.length()) nowPath[n++] = tempstr;
//	for(int i = 0; i < n; ++i) cout<<nowPath[i]<<"\n";
	getchar();
	while(p--){
		int m = 0;
		getline(cin, getstr);
		len = getstr.length();
		
		if(!len || getstr[0] != '/'){
			//���ַ��� ���·�� 
			for(int i = 0; i < n; ++i)
				ndPath[i] = nowPath[i];
			m = n;
		}else m = 0;  //��ͷ��ʼ 
		tempstr = "";
		for(int i = 0; i < len; ++i){
			if(getstr[i] == '/'){
				if(tempstr == "."); //��ǰĿ¼���� 
				else if(tempstr == ".."){
					m = (m==0?m:m-1);  //�ϼ�Ŀ¼ 
				}else if(tempstr == ""){
					continue;  //������ 
				}else ndPath[m++] = tempstr;
				tempstr = "";
			}else{
				tempstr += getstr[i];
			}
		}
		if(tempstr.length()){
			if(tempstr == "."); //��ǰĿ¼���� 
			else if(tempstr == ".."){
				m = (m==0?m:m-1);  //�ϼ�Ŀ¼ 
			}else ndPath[m++] = tempstr;
		}
		
		if(!m) cout << "/";
		for(int i = 0; i < m; ++i){
			cout << "/" << ndPath[i];
		}cout << endl;
	}
	return 0;
}
