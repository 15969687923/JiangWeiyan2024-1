#include<stdio.h>
char str[1000];
int fun(char str)
{
   	int i,j;
	char ch[1000];
   	i=0;j=0;
  	while(1){
     	if(i==999)
 			break;
 		else{
     		if((i+1)%4==0){
  				ch[i]=' ';
  				i++;
  			}
			else{
  				ch[i]=str[j];
  				j++;
  				i++;
 			}
  		}
	} 
	ch[i]='\0';
  	return(ch);
}
int main(){ 
  	int T;
	char ch[1000],cd[1000]; 
  	scanf("%d",&T);
  	while(T--){
  		gets(ch);
  		cd=fun(ch);
      	puts(cd);
  	}
  	return 0;
}
