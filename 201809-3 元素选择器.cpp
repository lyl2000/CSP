#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

const int N = 1e2+20;
struct E{  // element元素 
	string nm, id;
	vector<int> child;  // 子元素行数 
	E(){}
	E(string _nm, string _id)
		:nm(_nm), id(_id){ child.clear(); }
}e[N];
int n, m, root[N], num, ans[N], cnt;
string s, str[N];

void dfs(int u, int depth, bool isID){
	if(isID && e[u].id == str[depth] || !isID && e[u].nm == str[depth]){
		depth++;  // 找到一层，层数加1 
	}
	if(depth > num){  // 全部找到 
		ans[cnt++] = u;
		depth = num;  // 继续找 根据题目提示，采用贪心 
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
		
		int pcnt = 0;  // 缩进数 
		string nm = "", id = "";
		bool isID = 0;
		//  ..xxx #xxx
		for(int j = 0; j < s.size(); ++j){
			if(s[j] == '.'){
				pcnt++;
			}else if(s[j] == ' '){  // 空格后的是id 
				isID = 1;
			}else{
				if(isID) id += s[j];
				else nm += tolower(s[j]);  // 大小写不敏感，全部转化为小写 
			}
		}
		if(pcnt/2-1 >= 0){
			e[root[pcnt/2-1]].child.push_back(i);  // 上一层更新孩子
		}
		root[pcnt/2] = i;  // 更新根 
		e[i] = E(nm, id);
	}
	for(int i = 0; i < m; ++i){
		getline(cin, s);
		num = 0; str[num] = "";
		for(int j = 0; j < s.size(); ++j){
			if(s[j] == ' '){  // 要查询的不止一层 
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
		cnt = 0;  // 初始化 
		if(num == 0){  // 只有1个 
			if(str[num][0] == '#'){  // 查询id 
				for(int j = 1; j <= n; ++j){
					if(e[j].id == str[num]) ans[cnt++] = j;
				}
			}else{  // 查询nm 
				for(int j = 1; j <= n; ++j){
					if(e[j].nm == str[num]) ans[cnt++] = j;
				}
			}
		}else{  // 多于1个，用dfs查找 
			dfs(1, 0, str[0][0] == '#');
		}
		sort(ans, ans+cnt);  // dfs可能ans顺序乱，从小到大排序
		printf("%d", cnt);
		for(int j = 0; j < cnt; ++j) printf(" %d", ans[j]);
		printf("\n"); 
	}
	return 0;
}
