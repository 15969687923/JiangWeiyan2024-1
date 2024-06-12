#include<stdio.h>
#include<string.h>
int main(){
	char a[10],b[10];
	int k,i,j,na,nb,suma,sumb,x;
	while(1){
		scanf("%s%s%d",a,b,&k);	
		if(strcmp(a,"0")==0 && strcmp(b,"0")==0)
			break;
		na=strlen(a);
		nb=strlen(b);
		x=1;suma=0;sumb=0;
		for(i=na-1;i>=na-k && i>=0;i--){
			suma=suma+x*(a[i]-48);
			x=x*10;	
		}
		x=1;
		for(i=nb-1;i>=nb-k && i>=0;i--){
			sumb=sumb+x*(b[i]-48);
			x=x*10;	
		}
		if(suma==sumb)
			printf("-1\n");
		else{
			x=1;suma=0;sumb=0;
			for(i=na-1;i>=0;i--){
				suma=suma+x*(a[i]-48);
				x=x*10;	
			}
			x=1;
			for(i=nb-1;i>=0;i--){
				sumb=sumb+x*(b[i]-48);
				x=x*10;	
			}
			printf("%d\n",suma+sumb);
		}
	}
	return 0;
}

