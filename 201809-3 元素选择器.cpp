#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

const int N = 1e2+20;
struct E{  // elementԪ�� 
	string nm, id;
	vector<int> child;  // ��Ԫ������ 
	E(){}
	E(string _nm, string _id)
		:nm(_nm), id(_id){ child.clear(); }
}e[N];
int n, m, root[N], num, ans[N], cnt;
string s, str[N];

void dfs(int u, int depth, bool isID){
	if(isID && e[u].id == str[depth] || !isID && e[u].nm == str[depth]){
		depth++;  // �ҵ�һ�㣬������1 
	}
	if(depth > num){  // ȫ���ҵ� 
		ans[cnt++] = u;
		depth = num;  // ������ ������Ŀ��ʾ������̰�� 
	}
	for(int i = 0; i < e[u].child.size(); ++i){
		dfs(e[u].child[i], depth, str[depth][0] == '#');
	} 
}

int main(){
	scanf("%d%d ", &n, &m);
	memset(root, 0, sizeof(root));
	for(int i = 1; i <= n; ++i){
		getline(cin, s);
		
		int pcnt = 0;  // ������ 
		string nm = "", id = "";
		bool isID = 0;
		//  ..xxx #xxx
		for(int j = 0; j < s.size(); ++j){
			if(s[j] == '.'){
				pcnt++;
			}else if(s[j] == ' '){  // �ո�����id 
				isID = 1;
			}else{
				if(isID) id += s[j];
				else nm += tolower(s[j]);  // ��Сд�����У�ȫ��ת��ΪСд 
			}
		}
		if(pcnt/2-1 >= 0){
			e[root[pcnt/2-1]].child.push_back(i);  // ��һ����º���
		}
		root[pcnt/2] = i;  // ���¸� 
		e[i] = E(nm, id);
	}
	for(int i = 0; i < m; ++i){
		getline(cin, s);
		num = 0; str[num] = "";
		for(int j = 0; j < s.size(); ++j){
			if(s[j] == ' '){  // Ҫ��ѯ�Ĳ�ֹһ�� 
				num++; str[num] = "";
			}else{
				str[num] += s[j];
			}
		}
		for(int j = 0; j <= num; ++j){
			if(str[j][0] != '#'){
				for(int k = 0; k < str[j].size(); ++k){
					str[j][k] = tolower(str[j][k]);
				}
			}
		}
		cnt = 0;  // ��ʼ�� 
		if(num == 0){  // ֻ��1�� 
			if(str[num][0] == '#'){  // ��ѯid 
				for(int j = 1; j <= n; ++j){
					if(e[j].id == str[num]) ans[cnt++] = j;
				}
			}else{  // ��ѯnm 
				for(int j = 1; j <= n; ++j){
					if(e[j].nm == str[num]) ans[cnt++] = j;
				}
			}
		}else{  // ����1������dfs���� 
			dfs(1, 0, str[0][0] == '#');
		}
		sort(ans, ans+cnt);  // dfs����ans˳���ң���С��������
		printf("%d", cnt);
		for(int j = 0; j < cnt; ++j) printf(" %d", ans[j]);
		printf("\n"); 
	}
	return 0;
}
