#include <stdio.h>
int b[100],m;
int i,t,s[100];
int fun()
{
	int i,n=0;
	float sum=0,ave;
	for(i=0;i<m;i++)
		sum=sum+s[i];
	ave=sum/m;
	for(i=0;i<m;i++)
		if(s[i]<ave)
		{
			b[n]=s[i];
			n++;
		}
	return(n);
}
int main()
{
	
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&s[i]);
	}
	t=fun();//�ټ�һ��������������� ����ֵn����������ȫ�ò���д���������ܾ����������Ϊ���ú������ú��������� 
	for(i=0;i<n;i++)
	printf("%d ",b[i]);
}

