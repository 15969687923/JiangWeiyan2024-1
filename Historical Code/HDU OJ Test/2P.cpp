#include<stdio.h>
#include<math.h>
const double pi=4.0*atan(1.0);
int main(){
	int n,year,s;
	double x,y,d,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&x,&y);
		d=sqrt(x*x+y*y);
		s=50;year=1;
		for(;;){
			r=sqrt(2*s/pi);
			if(r>=d)
				break;
			else{
				s=s+50;
				year++;
			}
		}
		printf("Property %d: This property will begin eroding in year %d.\n",i,year);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
