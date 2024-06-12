#include<stdio.h>
int main(){
    int t,n,d=0,j;
    float a,c=0;
    int b[100];
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        d=0;c=0;
        scanf("%d",&n);
        for(int j=1;j<=n;j++){
            scanf("%d",&b[j]);
            c=c+b[j];
        }
        c=c/n;
        for(int m=1;m<=n;m++)
            if(b[m]>c)
                d=d+1;
        printf("%.2f ",c);
        printf("%d\n",d);
       // for(int j=1;j<=n;j++)
       //     b[j]=0;
    }
    return 0;
}
