#include <iostream>
using namespace std;

const int N=100+5;
struct Ball{
	int id,v,loc;
	Ball(){}
	Ball(int _id,int _loc):id(_id),v(1),loc(_loc){}
	void move(){ loc+=v; }
	void backword(){ v=-v; }
	bool operator<(const Ball& ball){ return loc<ball.loc; }
}balls[N];

int main(){
	int n,L,t,loc;
	cin>>n>>L>>t;
	for(int i=0;i<n;i++){
		cin>>loc;
		balls[i]=Ball(i,loc);
	}
	for(int i=0;i<t;i++){
		for(int j=0;j<n;j++) balls[j].move();
		sort()
	}
	return 0;
}
