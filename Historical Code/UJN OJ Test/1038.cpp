    #include "stdio.h"
    #include "math.h"
    int main()
    {
        int m,n,a,b,i,s=0;
        while((scanf("%d",&m))!=EOF)
        {
           scanf("%d",&n);//����һ��д��while�� 
           s=0;
           if(m<=n)
           {
                for(i=m;i<=n;i++)
            {
                if(i%3==0&&i%5==0)
                     s=s+i;
             }
            printf("%d\n",s);
            //getchar();  ���ð���ȫ���� 
           }
           else
           {
               for(i=n;i<=m;i++)
               {
                   if(i%3==0&&i%5==0)
                    s=s+i;
               }
               printf("%d\n",s);
               //getchar();

            }
        }
	return 0; 

    }
