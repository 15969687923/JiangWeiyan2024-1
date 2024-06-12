 #include<stdio.h>
 #include<math.h>
  int main() {
      // 待解方程数目
      int n;
    //  scanf("%d", &n);
  
      // 声明方程系数
      float a, b, c;
 
     // 存储读入的系数
     float args[n][n];
 
     // 声明方程的根
     double x1, x2;
 
     // 循环读入存储每行方程的系数a、b和c
     int count=0;
    // while(count!=n) {
         scanf("%f %f %f", &a, &b, &c);
        // args[count][0] = a;
        // args[count][1] = b;
        // args[count][2] = c;
        // count++;
    // }
 
     // 循环计算每行的一元二次方程根
   //  for(int i=0; i<n; i++) {
         double delta = 0.0;
         a = args[1][0];
         b = args[1][1];
         c = args[1][2];
         delta = b * b - 4 * a * c;
         if(delta==0) {
             x1 = (-b+0)/(2*a);
             x2 = x1;
             printf("x1=x2=%.5f\n", x1);
         } else if(delta>0) {
             x1 = (-b+sqrt(delta))/(2*a);
             x2 = (-b-sqrt(delta))/(2*a);
             if(x1>x2)
                 printf("x1=%.5f;x2=%.5f\n", x1, x2);
             else
                 printf("x2=%.5f;x1=%.5f\n", x2, x1);
         } else {
             // 实部计算公式： -1.0*b/(2*a) 虚部计算公式：+/- (sqrt(-delta))/(2*a)
             printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi\n", -1.0*b/(2*a), (sqrt(-delta))/(2*a), -1.0*b/(2*a), (sqrt(-delta))/(2*a));
         }
    // }
     return 0;
 }
