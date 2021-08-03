#include <stdio.h>
int main(){
	int s,cnt=1,ans=0,sc=0;
	while(scanf("%d",&s)&&s!=0){
		if(s==2){
			if(sc==1||cnt==1){
				ans+=2;
				sc=2;
			}else{
				sc+=2;
				ans+=sc;
			}
		}else if(s==1){
			sc=1;
			ans+=1;
		}
		cnt++;
	}
	printf("%d",ans);
	return 0;
} 
