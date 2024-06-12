#include<stdio.h>
int main(){
	int a[12];
	int z;
	//while(scanf("%d",&a[0])!=EOF){
		for(int i=1;i<=10;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<10;i++)
			for(int j=1;j<11-i;j++)
				if(a[j]>a[j+1]){
					z=a[j];
					a[j]=a[j+1];
					a[j+1]=z;
				}
		for(int i=1;i<=10;i++)
			printf("%d ",a[i]);
		printf("\n");
		//}
		return 0;
}
