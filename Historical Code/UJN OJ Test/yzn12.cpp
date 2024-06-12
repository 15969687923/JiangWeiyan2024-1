#include<stdio.h>
int main(){
   int a[20],n,i,j,t;
   while(1)//这个题的判断结束是这种，不是ctrl+z的文件结束方式 
	{
		scanf("%d",&n); 
		if(n==0)
			break;
	  	for(i=0;i<n;i++)
	    	scanf("%d",&a[i]);
		for(i=0;i<n-1;i++)
		 	printf("%d ",a[i]);
		printf("%d\n",a[n-1]);
		for(j=1;j<=n-1;j++)
        {	
			t=a[n-1];
		 	for(i=n-1;i>0;i--)
		    {
		      a[i]=a[i-1];
		    }
		      a[0]=t;
        for(i=0;i<n-1;i++)		  
		    printf("%d ",a[i]);
		    printf("%d\n",a[n-1]);
		}
	 }
	 return 0;
}
