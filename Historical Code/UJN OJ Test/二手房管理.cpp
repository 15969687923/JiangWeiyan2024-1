#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char jiemian();
void xieru();
void duqu();
void shuru();
void paixu();
void chuangjian();
void zengjia();
void shanchu();
void xiugai();
void xianshi();
void chaxun();
void bianhaochaxun();
void mianjichaxun();
void shuchu(int i);
void fangxingchaxun();
void dizhichaxun();
void tongji(); 
void yuetongji();
void jitongji();
void huxingtongji();
void zhuangtaitongji();
int main(); 
struct wanzheng{
	int bianhao;
	char dizhi[100];
	int mianji;
	char huxing[100];
	int jiansheshijiann;
	int jiansheshijiany;
	int jiansheshijianr;
	int louceng;
	char sheshi[100];
	int jiage;
	char zhuangkuang[10];
	int xiaoshoushijiann;
	int xiaoshoushijiany;
	int xiaoshoushijianr;
}; 
struct wanzheng house[1000];   //ȫ�ֵķ�����Ϣ����洢 
int iii=0; 
char jiemian(){
	char i='0';
	system("cls");
	printf("\n\n\n");
	printf("          ---------------------------------------------------------\n");
	printf("          -------------��ӭʹ�ö��ַ�������Ϣ����ϵͳ--------------\n");
	printf("          ---------------------------------------------------------\n");
	printf("          *                                                       *\n");
	printf("          *                ������ϵͳӵ�����¹���                 *\n");
	printf("          *                   0.������ʷ����Ϣ                    *\n");
	printf("          *                   1.�½����ַ���Ϣ                    *\n");
	printf("          *                   2.���Ӷ��ַ���Ϣ                    *\n");
	printf("          *                   3.ɾ�����ַ���Ϣ                    *\n");
	printf("          *                   4.�޸Ķ��ַ���Ϣ                    *\n");
	printf("          *                   5.��ѯ���ַ���Ϣ                    *\n");
	printf("          *                   6.ͳ�ƶ��ַ���Ϣ                    *\n");	
	printf("          *                   7.ͨ��ȫ������Ϣ                    *\n");
	printf("          *                   8.�˳����ַ�ϵͳ                    *\n");
	printf("          *                                                       *\n");
	printf("          *            ���������1-8ʹ����Ӧ��ŵĹ���            *\n");
	printf("                                      ");
	i=getchar();
	system("cls");
	return i;
} 
///////////////////////////////////////////////////////////////
void xieru(){//�����ļ�����д�룬ÿ�ζ�����ˢ���ļ�  
	FILE *fb;
	if((fb=fopen("ks","wb+"))==NULL)
	{
		printf("�������������ԣ�\n");
		exit(1);
	}
	fwrite(&iii,4,1,fb); 
	for(int i=0;i<iii;i++)
		fwrite(&house[i],sizeof(struct wanzheng),1,fb);
	fclose(fb);
}
void duqu(){
	FILE *fb;
	int a;
	if((fb=fopen("ks","rb"))==NULL)
	{
		printf("������������ԣ�\n");
		getchar();
		main(); 
	}
	fread(&a,4,1,fb);
	for(int i=0;i<a;i++)
		fread(&house[iii++],sizeof(struct wanzheng),1,fb);
	fclose(fb);
}
//////////////////////////////////////////////////////////////
void shuru(void){							//���������������
	printf("�����뷿�ݱ�ţ�"); 
	scanf("%d",&house[iii].bianhao);
	printf("�����뷿�ݵ�ַ��");
	scanf("%s",&house[iii].dizhi);
	printf("�����뷿�ݽ��������");
	scanf("%d",&house[iii].mianji);
	printf("�����뷿�ݻ��ͣ����Ҽ�����������");
	scanf("%s",&house[iii].huxing);
	printf("�����뷿�ݽ���ʱ��(��)��");
	scanf("%d",&house[iii].jiansheshijiann);
	printf("�����뷿�ݽ���ʱ��(��)��");
	scanf("%d",&house[iii].jiansheshijiany);
	printf("�����뷿�ݽ���ʱ��(��)��");
	scanf("%d",&house[iii].jiansheshijianr);
	printf("�����뷿��¥�㣺");
	scanf("%d",&house[iii].louceng);
	printf("�����뷿��������ʩ��");
	scanf("%s",&house[iii].sheshi);
	printf("�����뷿�����ۼ۸���Ԫ����");
	scanf("%d",&house[iii].jiage);
	printf("�����뷿������״����δ��/ǩԼ��/���ۣ���");
	scanf("%s",&house[iii].zhuangkuang);
	printf("�����뷿������ʱ�䣨�꣩��δ��������0����ͬ����"); 
	scanf("%d",&house[iii].xiaoshoushijiann);
	printf("�����뷿������ʱ�䣨�£���"); 
	scanf("%d",&house[iii].xiaoshoushijiany);
	printf("�����뷿������ʱ�䣨�գ���"); 
	scanf("%d",&house[iii].xiaoshoushijianr);
	getchar();
	printf("\n����ɹ���\n");   
	iii++;
}
//////////////////////////////////////////////////////////
void paixu(int a){
	int i,j;
	struct wanzheng temp;
	for(i=0;i<a-1;i++){
		for(j=i+1;j<a;j++)
			if(house[i].bianhao>house[j].bianhao){
				temp=house[i];
				house[i]=house[j];
				house[j]=temp;
			}
	}
}
//////////////////////////////////////////////////////////
void chuangjian(){
	char c='y';
	getchar();
																							/*if(c=='y'||c=='Y') 
																								shuru();
																							printf("�Ƿ�������뷿����Ϣ��y/n��");
																							c=getchar();*/ 
	while(c=='y'||c=='Y'){
		shuru();
		printf("�Ƿ�������뷿����Ϣ��y/n��");
		c=getchar();
	}
	paixu(iii);
	xieru();
	return;
}
///////////////////////////////////////////////////
void zengjia(){
	char c='y';
	while(c=='y' || c=='Y'){
		shuru();
		printf("�Ƿ�������뷿����Ϣ��y/n��");
		c=getchar(); 
	} 
	paixu(iii);
	xieru();
	return;
}
//////////////////////////////////////////////////////
void shanchu(){
	int d,b=1100,i=0,j;
	char c;
	printf("������Ҫɾ����Ϣ�ķ��ݱ�ţ�");
	scanf("%d",&d);
	for(i=0;i<iii;i++){
		if(house[i].bianhao==d){
			b=i;
			break;
		}
	}
	getchar();
	if(i==iii){
		printf("����ѯû�д˷�����Ϣ���Ƿ��������뷿�ݱ�ţ�y/n��");
		c=getchar();
		if(c=='y'||c=='Y'){
			shanchu(); 
			return;                                                     //juebi�����⣡���� 
		}
		else{
			return;
		}
	}
	for(j=b;j<iii;j++){
		house[j]=house[j+1];
	}
	if(j==iii){
		iii--;
		printf("ɾ���ɹ����Ƿ����ɾ����y/n��");
		c=getchar();
		if(c=='y'||c=='Y'){
			shanchu();
			return; 
		}
		else{
			return;
		}
	}
	xieru();
	/*else if(j!=iii+2){
		printf("ɾ�����ִ��������ԣ������������");
		getchar();
		return; 
	}*/
		
}
///////////////////////////////////////////////////////
void xiugai(){
	int d,b,i;
	char a[100];
	char c='y';
	printf("��������Ҫ�޸ĵķ��ݱ�ţ�");
	scanf("%d",&d);
	for(i=0;i<iii;i++){
		if(house[i].bianhao==d){
			break;
		}
	}
	if(i==iii){
		printf("����ѯû�д˷��ݱ�ţ��Ƿ��������루y/n��");
		c=getchar();
		if(c=='y' || c=='Y'){
			xiugai();
			return;
		} 
		else
			return;
	}
	printf("�˷�����ϢΪ��\n");
	shuchu(i);
	printf("\n\n");
	//getchar();
	while(c=='y' || c=='Y'){
		printf("������Ҫ�޸ĵ����ࣺ");
		scanf("%s",a);
			if(strcmp(a,"���ݱ��")==0){
				printf("Ŀǰ���ݱ��Ϊ��%d\n�������޸�֮�����Ϣ��",house[i].bianhao);
				scanf("%d",&house[i].bianhao); 
			}
			else if(strcmp(a,"���ݵ�ַ")==0){
				printf("Ŀǰ���ݵ�ַΪ��%s\n�������޸�֮�����Ϣ��",house[i].dizhi);
				scanf("%s",house[i].dizhi); 
			}
			else if(strcmp(a,"�������")==0){
				printf("Ŀǰ�������Ϊ��%d\n�������޸�֮�����Ϣ��",house[i].mianji);
				scanf("%d",&house[i].mianji); 
			}
			else if(strcmp(a,"���ݻ���")==0){
				printf("Ŀǰ���ݻ���Ϊ��%s\n�������޸�֮�����Ϣ��",house[i].huxing);
				scanf("%s",house[i].huxing); 
			}
			else if(strcmp(a,"����ʱ��")==0){
				printf("Ŀǰ����ʱ��Ϊ��%d %d %d\n�������޸�֮�����Ϣ��",house[i].jiansheshijiann,house[i].jiansheshijiany,house[i].jiansheshijianr);
				scanf("%d",&house[i].jiansheshijiann); 
				scanf("%d",&house[i].jiansheshijiany); 
				scanf("%d",&house[i].jiansheshijianr); 
			}
			else if(strcmp(a,"¥��")==0){
				printf("Ŀǰ¥��Ϊ��%d\n�������޸�֮�����Ϣ��",house[i].louceng);
				scanf("%d",&house[i].louceng); 
			}
			else if(strcmp(a,"������ʩ")==0){
				printf("Ŀǰ������ʩΪ��%s\n�������޸�֮�����Ϣ��",house[i].sheshi);
				scanf("%s",house[i].sheshi); 
			}
			else if(strcmp(a,"���ۼ۸�")==0){
				printf("Ŀǰ���ۼ۸�Ϊ��%d\n�������޸�֮�����Ϣ��",house[i].jiage);
				scanf("%d",&house[i].jiage); 
			}
			else if(strcmp(a,"����״��")==0){
				printf("Ŀǰ����״��Ϊ��%s\n�������޸�֮�����Ϣ��",house[i].zhuangkuang);
				scanf("%s",house[i].zhuangkuang); 
			}
			else if(strcmp(a,"����ʱ��")==0){
				printf("Ŀǰ����ʱ��Ϊ��%d %d %d\n�������޸�֮�����Ϣ��",house[i].xiaoshoushijiann,house[i].xiaoshoushijiany,house[i].xiaoshoushijianr);
				scanf("%d",&house[i].xiaoshoushijiann); 
				scanf("%d",&house[i].xiaoshoushijiany);
				scanf("%d",&house[i].xiaoshoushijianr);
			}
			else{
				printf("��Ǹ��û�д����࣬��Ҫ�޸����������루���ݱ��/���ݵ�ַ/�������/���ݻ���/����ʱ��/¥��/������ʩ/���ۼ۸�/����״��/����ʱ�䣩\n") ;
			} 
			getchar();
			printf("�Ƿ�����޸Ĵ˱�ŷ�����Ϣ��y/n��");
			c=getchar();
			/*if(c=='y'||c=='Y'){
				xiugai(); 
				return;
			}*/ 
	} 
	paixu(iii);
	xieru();

}

/////////////////////////////////////////////////////
void xianshi(){                           //���ɾ�� 
	for(int i=0;i<iii;i++){
		printf("���ݱ��:%d\n���ݵ�ַ:%s\n�������:%d\n���ݻ���:%s\n����ʱ��:%d %d %d\n¥��:%d\n������ʩ:%s\n���ۼ۸�%d\n����״��:%s\n����ʱ��:%d %d %d\n\n",house[i].bianhao,house[i].dizhi,house[i].mianji,house[i].huxing,house[i].jiansheshijiann,house[i].jiansheshijiany,house[i].jiansheshijianr,house[i].louceng,house[i].sheshi,house[i].jiage,house[i].zhuangkuang,house[i].xiaoshoushijiann,house[i].xiaoshoushijiany,house[i].xiaoshoushijianr); 
	}
	printf("\n�����������\n");
		//getchar();
		getchar();
} 
///////////////////////////////////////////////////
///////////////////////////////////////////////////
int main(){
	char x='0';
	//duqu();
	while(1){
		x=jiemian();
		if(x=='0'){
			duqu();
			x='0';
			getchar();
			main();
		}
		else if(x=='1'){
			chuangjian();
			x='0';
			getchar();
			main();
		}
		else if(x=='2'){
			zengjia();
			x='0';
			getchar();
			main();
		}
		else if(x=='3'){
			shanchu();
			x='0';
			getchar();
			main();
		}
		else if(x=='4'){
			xiugai();
			x='0';
			getchar();
			getchar();
			main();
		}
		else if(x=='5'){
			chaxun();
			x='0';
			getchar();
			getchar();
			main();
		}
		else if(x=='6'){
			tongji();
			x='0';
			getchar();
			getchar();
			main();
		}
		else if(x=='7'){
			xianshi();
			x='0';
			getchar();
			main();
		}
		else if(x=='8')
			exit(0);
		else{
			printf("ָ��Ƿ������س���������ҳ��\n");
			getchar();
			getchar();
		} 
	}
	return 0;
}
///////////////////////////////////////////////////��ѯһ���� 
void chaxun(){
	int z;
	char c;
	system("cls");
	printf("         *                                                       *\n");
	printf("         *                  1.�����ݱ�Ų�ѯ                     *\n");
	printf("         *                  2.�����ݵ�ַ��ѯ                     *\n");
	printf("         *                  3.�����������ѯ                     *\n");
	printf("         *                  4.������������ѯ                     *\n");
	printf("         *                  5.�������˵�                         *\n");
	printf("         *                        ");
	scanf("%d",&z); 
	getchar();
	if(z==1)
		bianhaochaxun();
	else if(z==2)
		dizhichaxun();
	else if(z==3)
		mianjichaxun();
	else if(z==4)
		fangxingchaxun();
	else if(z==5)
		main();
	else{ 
		printf("ָ��Ƿ�������������\n");
		getchar();
		getchar();
		chaxun();
		return;
	}
	getchar();
	printf("�Ƿ������ѯ������Ϣ��y/n��");
	c=getchar();
	system("cls");	
	if(c=='y'||c=='Y'){
		chaxun();
		return;
	}
	return; 
}
void fangxingchaxun(){
	char a[100],c;
	int i,sum=0;
	printf("����������Ҫ�Ļ������������Ҽ�����������");
	scanf("%s",a);
	for(i=0;i<iii;i++)
		if(strstr(house[i].huxing,a)!=NULL){
			shuchu(i);
			sum++;
		} 
	if(sum==0){
		getchar();
		printf("��Ǹ��û������Ҫ�Ļ��ͣ��Ƿ���������Ͳ�ѯ��y/n��"); 
		c=getchar();
		if(c=='y'||c=='Y'){
			fangxingchaxun();
			return;
		}
		else{
			chaxun();
			return;
		} 
	}
}
void dizhichaxun(){
	char a[100],c;
	int i,sum=0;
	printf("����������Ҫ�ķ��ݵ�ַ�������ǲ��ֵ�ַ����");
	scanf("%s",a);
	for(i=0;i<iii;i++)
		if(strstr(house[i].dizhi,a)!=NULL){
			shuchu(i);
			sum++;
		} 
	if(sum==0){
		getchar();
		printf("��Ǹ��û������Ҫ��ַ�ķ��ݣ��Ƿ���������ݵ�ַ��ѯ��y/n��"); 
		c=getchar();
		if(c=='y'||c=='Y'){
			dizhichaxun();
			return;
		}
		else{
			chaxun();
			return;
		} 
	}
}
void bianhaochaxun(){
	int a,i;
	char c;
	printf("����������Ҫ��ѯ�ķ��ݱ�ţ�");
	scanf("%d",&a);
	for(i=0;i<iii;i++){
		if(house[i].bianhao==a){
			break;
		}
	}
	if(i==iii){
		getchar();
		printf("����ѯû�д˷��ݱ�ţ��Ƿ��������루y/n��");
		c=getchar();
		if(c=='y' || c=='Y'){
			bianhaochaxun();
			chaxun();
			return;
		} 
		else{
			chaxun();
			return;
		}
	}
	getchar();
	shuchu(i);
}
void mianjichaxun(){
	int a,i,sum=0;
	char c; 
	printf("����������Ҫ�ķ��������");
	scanf("%d",&a);
	for(i=0;i<iii;i++){
		if(house[i].mianji>=a){
			shuchu(i);
			sum++;
		}
	}
	getchar();
	if(sum==0){
		printf("��Ǹ��û�з�����Ҫ������ķ�����Ϣ���Ƿ�����������ѯ��y/n��");
		c=getchar();
		if(c=='y'||c=='Y'){
			mianjichaxun();
			return;
		}
		else{
			chaxun();
			return;
		} 
	} 
}
void shuchu(int i){
	printf("���ݱ��:%d\n���ݵ�ַ:%s\n�������:%d\n���ݻ���:%s\n����ʱ��:%d %d %d\n¥��:%d\n������ʩ:%s\n���ۼ۸�%d\n����״��:%s\n����ʱ��:%d %d %d\n\n",house[i].bianhao,house[i].dizhi,house[i].mianji,house[i].huxing,house[i].jiansheshijiann,house[i].jiansheshijiany,house[i].jiansheshijianr,house[i].louceng,house[i].sheshi,house[i].jiage,house[i].zhuangkuang,house[i].xiaoshoushijiann,house[i].xiaoshoushijiany,house[i].xiaoshoushijianr); 
	getchar();
}
///////////////////////////////////////////////////////////ͳ��һ���
void tongji(){
	int a;
	char c;
	system("cls");
	printf("         *                                                  *\n");
	printf("         *             1.����ͳ�Ʒ������������ͳɽ���       *\n");
	printf("         *             2.����ͳ�Ʒ������������ͳɽ���       *\n");
	printf("         *             3.������ͳ�Ʒ������������ͱ���       *\n");
	printf("         *             4.������ܷ�������״̬��Ϣ           *\n");
	printf("         *             5.�������˵�                         *\n");
	printf("                                  ");
	scanf("%d",&a); 
	getchar();
	if(a==1)
		yuetongji();
	else if(a==2)
		jitongji();
	else if(a==3)
		huxingtongji();
	else if(a==4)
		zhuangtaitongji();
	else if(a==5)
		main(); 
	getchar();
	printf("�Ƿ����ͳ�Ʒ���������Ϣ��y/n��");
	c=getchar();
	system("cls");	
	if(c=='y'||c=='Y'){
		tongji();
		return;
	}
	return; 
}
void yuetongji(){
	int a; 
	int i,sam=0,sum=0;
	char c;
	printf("��������Ҫ��ѯ�������·ݣ�");
	scanf("%d",&a);
	for(i=0;i<iii;i++)
		if(house[i].xiaoshoushijiany==a){
			sam++;
			sum=sum+house[i].jiage;
		} 
	if(sam==0){
		getchar();
		printf("��Ǹ��û������Ҫ����Ϣ���Ƿ�����ͳ�ƣ�y/n��"); 
		c=getchar();
		if(c=='y'||c=='Y'){
			yuetongji();
			return;
		}
		else{
			getchar(); 
			tongji();
			return;
		} 
	}
	printf("%d�·ݷ�����������Ϊ��%d���ɽ��ܶ�Ϊ����Ԫ����%d\n",a,sam,sum);
	return;
}
void jitongji(){
	int a; 
	int i,sam=0,sum=0;
	char c;
	printf("��������Ҫ��ѯ�ļ��ȣ�1/2/3/4����");
	scanf("%d",&a);
	if(a==1){
		for(i=0;i<iii;i++)
			if(house[i].xiaoshoushijiany==1 || house[i].xiaoshoushijiany==2 || house[i].xiaoshoushijiany==3){
				sam++;
				sum=sum+house[i].jiage;
			} 
	}
	else if(a==2){
		for(i=0;i<iii;i++)
			if(house[i].xiaoshoushijiany==4 || house[i].xiaoshoushijiany==5 || house[i].xiaoshoushijiany==6){
				sam++;
				sum=sum+house[i].jiage;
			} 
	}
	else if(a==3){
		for(i=0;i<iii;i++)
			if(house[i].xiaoshoushijiany==7 || house[i].xiaoshoushijiany==8 || house[i].xiaoshoushijiany==9){
				sam++;
				sum=sum+house[i].jiage;
			} 
	}
	else if(a==4){
		for(i=0;i<iii;i++)
			if(house[i].xiaoshoushijiany==10 || house[i].xiaoshoushijiany==11 || house[i].xiaoshoushijiany==12){
				sam++;
				sum=sum+house[i].jiage;
			} 
	}
	if(sam==0){
		getchar();
		printf("��Ǹ��û������Ҫ����Ϣ���Ƿ�����ͳ�ƣ�y/n��"); 
		c=getchar();
		if(c=='y'||c=='Y'){
			jitongji();
			return;
		}
		else{
			tongji();
			return;
		} 
	}
	printf("%d���ȷ�����������Ϊ��%d���ɽ��ܶ�Ϊ����Ԫ����%d\n",a,sam,sum);
	return;
}
void huxingtongji(){
	int i,sam=0;
	double d;
	char c,a[100];
	printf("����������Ҫͳ�Ƶķ��ݻ��ͣ�");
	scanf("%s",&a);
	getchar(); 
	for(i=0;i<iii;i++)
		if(strstr(house[i].huxing,a)!=NULL){
			sam++;
		} 
	if(sam==0){
		getchar();
		printf("��Ǹ��û������Ҫ����Ϣ���Ƿ�����ͳ�ƣ�y/n��"); 
		c=getchar();
		if(c=='y'||c=='Y'){
			huxingtongji();
			return;
		}
		else{
			tongji();
			return;
		} 
	}
	d=((double)sam/(double)iii)*100;
	printf("�û�����������Ϊ��%d����ռ����Ϊ��%.0lf %%��\n",sam,d);
	return;
}
void zhuangtaitongji(){
	int i,sam=0,sbm=0,scm=0;
	char c,a[100];
	for(i=0;i<iii;i++)
		if(strstr(house[i].zhuangkuang,"δ��")!=NULL){
			sam++;
			shuchu(i);
		} 
	printf("δ�۷��ݹ���%d��\n\n\n\n\n",sam);
	for(i=0;i<iii;i++)
		if(strstr(house[i].zhuangkuang,"ǩԼ��")!=NULL){
			sbm++;
			shuchu(i);
		} 
	printf("ǩԼ�з��ݹ���%d��\n\n\n\n\n",sbm);
	for(i=0;i<iii;i++)
		if(strstr(house[i].zhuangkuang,"����")!=NULL){
			scm++;
			shuchu(i);
		} 
	printf("���۷��ݹ���%d��\n\n\n\n\n",scm);
	if(sam==0 && sbm==0 && scm==0){
		getchar();
		printf("��Ǹ��û������Ҫ����Ϣ�������������"); 
		c=getchar();
		return; 
	}
	return;
} 













