#include<stdio.h>
#include<string.h>
int main()
{
	int n,i;
	char a[300],b[300];
	while(gets(b)&&(strcmp(b,"ENDOFINPUT")!=0)){
		gets(a);
		gets(b);
		n=strlen(a);
		for(i=0;i<n;i++){
			if(a[i]>=70 && a[i]<=90)
				a[i]=a[i]-5;
			else if(a[i]<=69 && a[i]>=65)
				a[i]=a[i]+21;
		}
		printf("%s\n",a);
	}
	return 0;
}

