#include<stdio.h>
#include<string.h>
int main(){
	char a[100];
	int n;
	while(1){
		scanf("%s",a);
		if(a=="ENDOFINPUT")
			return 0;
		else if(a=="START")
			continue;
		else if(a=="END"){
			printf("\n");
			continue;
		}
		else{
			n=strlen(a);
			for(int i=0;i<n;i++){
				if(a[i]>='F' && a[i]<='Z')
					a[i]=a[i]-5;
				else if(a[i]>='A')
					a[i]=a[i]+21;
				printf("%c",a[i]);
			}
			printf(" ");
		}
		
	}
	return 0;
} 
