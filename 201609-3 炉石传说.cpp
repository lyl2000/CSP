#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

struct Summon{
	int h, a;  // 血量 攻击力 
	Summon(){}
	Summon(int _h, int _a):h(_h), a(_a){}
};

struct Player{
	int hp;  // 英雄生命值
	vector<Summon> s;  // 随从 
	Player(){
		hp = 30;
//		s = vector<Summon>(10);
	}
}player[2];
int isEnd;

void print(){
	printf("%d\n", isEnd);
	printf("%d\n", player[0].hp);
	printf("%d ", player[0].s.size());
	for(int i = 0; i < player[0].s.size(); ++i)
		printf("%d ", player[0].s[i].h);
	printf("\n");
	printf("%d\n", player[1].hp);
	printf("%d ", player[1].s.size());
	for(int i = 0; i < player[1].s.size(); ++i)
		printf("%d ", player[1].s[i].h);
	printf("\n");
}

void ack(int a, int d, int nowPlayer){
	int enemy = 1 - nowPlayer;  // 敌人编号 
	int Hx = player[nowPlayer].s[a-1].h;
	int Hy = (d == 0 ? player[enemy].hp : player[enemy].s[d-1].h);
	int Ax = player[nowPlayer].s[a-1].a;
	int Ay = (d == 0 ? 0 : player[enemy].s[d-1].a);
	Hx -= Ay; Hy -= Ax;
	if(Hx <= 0){
		player[nowPlayer].s.erase(player[nowPlayer].s.begin()+a-1);
	}else{
		player[nowPlayer].s[a-1].h = Hx;
	}
	if(Hy <= 0){
		if(d == 0){
			isEnd = (enemy ? 1 : -1);
			player[enemy].hp = Hy; return;
		}
		player[enemy].s.erase(player[enemy].s.begin()+d-1);
	}else{
		if(d == 0){
			player[enemy].hp = Hy; return;
		}
		player[enemy].s[d-1].h = Hy;
	}
}

int main(){
	int n; scanf("%d", &n);
	isEnd = 0; int nowPlayer = 0;  // 当前玩家 // 游戏是否结束 
	for(int i = 0; i < n; ++i){
		char command[10]; 
		scanf("%s", command);
		if(!strcmp(command, "summon")){
			int p, a, h;
			scanf("%d%d%d", &p, &a, &h);
			player[nowPlayer].s.insert(player[nowPlayer].s.begin()+p-1, Summon(h, a));
		}else if(!strcmp(command, "attack")){
			int a, d; scanf("%d%d", &a, &d);
			ack(a, d, nowPlayer);  // 序号从0开始 
		}else if(!strcmp(command, "end")){
			nowPlayer = 1 - nowPlayer;
		}
	}
	print();
	return 0;
} 
