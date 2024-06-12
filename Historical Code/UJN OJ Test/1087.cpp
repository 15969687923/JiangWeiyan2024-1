#include<stdio.h>
int main(){
	double a,b;
	char c;	
	double d;
	while(scanf("%lf%lf",&a,&b)!=EOF){
		c=getchar();
		c=getchar();
		if(a==0 && b==0)
			return 0;
		else{
			d=a/b;
			if(c==48)
			printf("%.0lf\n",d);
			else if(c==49)
			printf("%.1lf\n",d);
			else if(c==50)
			printf("%.2lf\n",d);
			else if(c==51)
			printf("%.3lf\n",d);
			else if(c==52)
			printf("%.4lf\n",d);
			else if(c==53)
			printf("%.5lf\n",d);
			else if(c==54)
			printf("%.6lf\n",d);
			else if(c==55)
			printf("%.7lf\n",d);
			else if(c==56)
			printf("%.8lf\n",d);
			else if(c==57)
			printf("%.9lf\n",d);
		}
	}
	
}
