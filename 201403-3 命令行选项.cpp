#include <bits/stdc++.h>
using namespace std;
const int N = 30;
string cmd, cs[N];
int n, vis[N], op[N];
int main(){
	cin >> cmd;
	memset(op, 0, sizeof(op));
	for(int i = 0; i < cmd.size(); ++i) {
		if(cmd[i] <= 'z' && cmd[i] >= 'a') {
			if(i+1 < cmd.size() && cmd[i+1] == ':') op[cmd[i++] - 'a'] = 2;
			else op[cmd[i] - 'a'] = 1;
		}
	}
	scanf("%d", &n); getchar();
	for(int i = 1; i <= n; ++i) {
		getline(cin, cmd);
		memset(vis, 0, sizeof(vis));
		int now = -1, idx = 0;
		while(idx < cmd.size() && cmd[idx++] != ' ');
		for(int j = idx; j < cmd.size(); ++j) {
			string tmp;
			while(j < cmd.size() && cmd[j] != ' ') tmp.push_back(cmd[j++]);
			if(now == -1) {
				if(tmp.size() == 2 && tmp[0] == '-' && tmp[1] <= 'z' && tmp[1] >= 'a') {
					now = tmp[1] - 'a';
					if(!op[now]) break;  // 没有出现过
					if(!vis[now]) vis[now] = 1;
					if(op[now] == 1) now = -1;
				} else break;
			} else {
				cs[now] = tmp;
				now = -1;
			}
		}
		printf("Case %d:", i);
		for(int i = 0; i < 26; ++i) {
			if(vis[i]) {
				printf(" -%c", i+'a');
				if(op[i] == 2) cout << " " << cs[i];
			}
		}
		printf("\n");
	}
	return 0;
} 
