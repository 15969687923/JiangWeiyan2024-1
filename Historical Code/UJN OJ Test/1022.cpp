#include<stdio.h>
int main(){
    float a,b,c;
    scanf("%f%f%f",&a,&b,&c);
    if(a==b &&b==c&&a==c && a+b>c && a+c>b && b+c>a){
            printf("equilateral triangle");
              return 0;}
    else if(a+b<c || a+c<b || b+c<a){
            printf("not a triangle");
            return 0;}
   else if(a==b || a==c || b==c){
            printf("isosceles triangle");
            return 0;}
   else if(a!=b && b!=c && a!=c && a+b>c && a+c>b && b+c>a){
            printf("common triangle");
            return 0;}
    

}
             

