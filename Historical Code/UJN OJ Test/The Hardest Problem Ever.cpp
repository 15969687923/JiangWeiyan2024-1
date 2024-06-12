#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	//char a[40]={"V","W","X","Y","Z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U"};
	char b[150];
	int s;
	while(1){
		gets(b);
		if(strcmp(b,"START")==0 || strcmp(b,"END")==0)
			continue;
		if(strcmp(b,"ENDOFINPUT")==0)
			break;
		else{
			s=strlen(b);
			for(int i=0;i<s;i++){
				if(b[i]==' '||b[i]==',')
					continue;
				else if(b[i]>='F' && b[i]<='Z')
					b[i]=b[i]-5;
				else
					b[i]=b[i]+21;
			}
			puts(b);
		}
	}
	return 0;
}
