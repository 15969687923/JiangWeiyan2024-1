#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stu{
	char a[20];
	struct stu *next;
};
#define len sizeof(struct stu)
int main(){
	struct stu *p1=NULL,*p2=NULL,*head=NULL;
	char b[20];
	scanf("%s",b);
	while(b[0]!='#'){
		p1=(struct stu *)malloc(len);
		strcpy(p1->a,b);
		if(head==NULL)
			head=p1;
		else
		p2->next = p1;
		p2=p1;
		scanf("%s",b);
	}
	struct stu *p;
	p2->next=NULL;
	if(head==NULL)
		printf("¿ÕÁ´±í\n");
	else{
		p=head;
		while(p!=NULL){
			printf("%s\n",p->a);
			p=p->next;
		}
	}
	return 0;
}
