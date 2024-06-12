#include <stdio.h>
#include <string.h>
main(){
	int n, i, j, t, max, num[1000];
	char color[1000][16];
	while(scanf("%d", &n) != EOF){
		if(n){
			num[0]=0;
			scanf("%s", color[0]);
			for(i=1; i <n; i++){
				num[i]=0;
				scanf("%s", color[i]);
				for(j=0; j <i-1; j++)
					if(strcmp(color[i], color[j])==0) num[i] +=1;
			}
			max=num[0];
			t=0;
			for(i=1; i <n; i++)
				if(max <num[i]) {max =num[i]; t=i;}
			printf("%s\n",color[t]);
		}
	}
	return 0;
}

