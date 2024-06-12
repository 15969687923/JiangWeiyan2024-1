#include<stdio.h>
int main(){
	int a,b,c,d,e,f;
	while(scanf("%d",&a)!=EOF){
		getchar();
		scanf("%d",&b);
		getchar();
		scanf("%d",&c);
		if(a%4==0 && a%100!=0){
			if(b==1)
				d=c;
			else if(b==2)
				d=31+c;
			else{
				d=31+29;
				e=31;
				f=-1;
				for(int i=3;i<b;i++){
					d=d+e;
					e=e+f;
					f=f*(-1);
				}
				d=d+c;
			}
		}
		else{
			d=0;
			e=31;
			f=-1;
			for(int i=1;i<b;i++){
				d=d+e;
				e=e+f;
				f=f*(-1);
			}
			d=d+c;
		}
		printf("%d\n",d);
			
	}
}
