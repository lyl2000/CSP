#include <stdio.h>
#define N 100000+5
int a[N];
int main(){
	int n,b,d;
	double c;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", a+i);
	}
	if(a[0]<a[n-1]){
		b=a[n-1];
		d=a[0];
	}else{
		b=a[0];
		d=a[n-1];
	}
	if(n & 1){
		c=a[n/2];
		printf("%d %d %d", b, int(c), d);
	}else{
		c=(a[(n-1)/2] + a[n/2]) *1.0 / 2;
		if(c-int(c)==0)
			printf("%d %d %d", b, int(c), d);
		else
			printf("%d %.1f %d", b, c, d); 
	}
	printf("\n");
	return 0;
}
