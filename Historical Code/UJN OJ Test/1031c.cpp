 #include<stdio.h>
 #include<math.h>
  int main() {
      // ���ⷽ����Ŀ
      int n;
    //  scanf("%d", &n);
  
      // ��������ϵ��
      float a, b, c;
 
     // �洢�����ϵ��
     float args[n][n];
 
     // �������̵ĸ�
     double x1, x2;
 
     // ѭ������洢ÿ�з��̵�ϵ��a��b��c
     int count=0;
    // while(count!=n) {
         scanf("%f %f %f", &a, &b, &c);
        // args[count][0] = a;
        // args[count][1] = b;
        // args[count][2] = c;
        // count++;
    // }
 
     // ѭ������ÿ�е�һԪ���η��̸�
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
             // ʵ�����㹫ʽ�� -1.0*b/(2*a) �鲿���㹫ʽ��+/- (sqrt(-delta))/(2*a)
             printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi\n", -1.0*b/(2*a), (sqrt(-delta))/(2*a), -1.0*b/(2*a), (sqrt(-delta))/(2*a));
         }
    // }
     return 0;
 }
