#include<stdio.h>
int main(){
	struct stu{
		int a;
		char b[10];
		int c;
	}st[11],*p;
	int max=0;
	for(int i=1;i<=8;i++){
		scanf("%d%s%d",&st[i].a,&st[i].b,&st[i].c);
		if(st[i].c>=max){
			max=st[i].c;
			p=&st[i];
		}
	}
	printf("%d %s %d\n",p->a,p->b,p->c);
	return 0;
	 
} 
