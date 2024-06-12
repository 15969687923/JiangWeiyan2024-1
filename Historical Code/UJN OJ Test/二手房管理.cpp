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
struct wanzheng house[1000];   //全局的房屋信息数组存储 
int iii=0; 
char jiemian(){
	char i='0';
	system("cls");
	printf("\n\n\n");
	printf("          ---------------------------------------------------------\n");
	printf("          -------------欢迎使用二手房销售信息管理系统--------------\n");
	printf("          ---------------------------------------------------------\n");
	printf("          *                                                       *\n");
	printf("          *                本管理系统拥有如下功能                 *\n");
	printf("          *                   0.读入历史的信息                    *\n");
	printf("          *                   1.新建二手房信息                    *\n");
	printf("          *                   2.增加二手房信息                    *\n");
	printf("          *                   3.删除二手房信息                    *\n");
	printf("          *                   4.修改二手房信息                    *\n");
	printf("          *                   5.查询二手房信息                    *\n");
	printf("          *                   6.统计二手房信息                    *\n");	
	printf("          *                   7.通览全部的信息                    *\n");
	printf("          *                   8.退出二手房系统                    *\n");
	printf("          *                                                       *\n");
	printf("          *            请键入数字1-8使用相应编号的功能            *\n");
	printf("                                      ");
	i=getchar();
	system("cls");
	return i;
} 
///////////////////////////////////////////////////////////////
void xieru(){//创建文件并且写入，每次都重新刷新文件  
	FILE *fb;
	if((fb=fopen("ks","wb+"))==NULL)
	{
		printf("创建错误请重试！\n");
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
		printf("读入错误请重试！\n");
		getchar();
		main(); 
	}
	fread(&a,4,1,fb);
	for(int i=0;i<a;i++)
		fread(&house[iii++],sizeof(struct wanzheng),1,fb);
	fclose(fb);
}
//////////////////////////////////////////////////////////////
void shuru(void){							//所有数据输入调用
	printf("请输入房屋编号："); 
	scanf("%d",&house[iii].bianhao);
	printf("请输入房屋地址：");
	scanf("%s",&house[iii].dizhi);
	printf("请输入房屋建筑面积：");
	scanf("%d",&house[iii].mianji);
	printf("请输入房屋户型（几室几厅几卫）：");
	scanf("%s",&house[iii].huxing);
	printf("请输入房屋建设时间(年)：");
	scanf("%d",&house[iii].jiansheshijiann);
	printf("请输入房屋建设时间(月)：");
	scanf("%d",&house[iii].jiansheshijiany);
	printf("请输入房屋建设时间(日)：");
	scanf("%d",&house[iii].jiansheshijianr);
	printf("请输入房屋楼层：");
	scanf("%d",&house[iii].louceng);
	printf("请输入房间配套设施：");
	scanf("%s",&house[iii].sheshi);
	printf("请输入房屋销售价格（万元）：");
	scanf("%d",&house[iii].jiage);
	printf("请输入房屋销售状况（未售/签约中/已售）：");
	scanf("%s",&house[iii].zhuangkuang);
	printf("请输入房屋销售时间（年）（未售请输入0，下同）："); 
	scanf("%d",&house[iii].xiaoshoushijiann);
	printf("请输入房屋销售时间（月）："); 
	scanf("%d",&house[iii].xiaoshoushijiany);
	printf("请输入房屋销售时间（日）："); 
	scanf("%d",&house[iii].xiaoshoushijianr);
	getchar();
	printf("\n输入成功！\n");   
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
																							printf("是否继续输入房屋信息（y/n）");
																							c=getchar();*/ 
	while(c=='y'||c=='Y'){
		shuru();
		printf("是否继续输入房屋信息（y/n）");
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
		printf("是否继续输入房屋信息（y/n）");
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
	printf("请输入要删除信息的房屋编号：");
	scanf("%d",&d);
	for(i=0;i<iii;i++){
		if(house[i].bianhao==d){
			b=i;
			break;
		}
	}
	getchar();
	if(i==iii){
		printf("经查询没有此房屋信息，是否重新输入房屋编号（y/n）");
		c=getchar();
		if(c=='y'||c=='Y'){
			shanchu(); 
			return;                                                     //juebi有问题！！！ 
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
		printf("删除成功，是否继续删除（y/n）");
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
		printf("删除出现错误，请重试，按任意键继续");
		getchar();
		return; 
	}*/
		
}
///////////////////////////////////////////////////////
void xiugai(){
	int d,b,i;
	char a[100];
	char c='y';
	printf("请输入您要修改的房屋编号：");
	scanf("%d",&d);
	for(i=0;i<iii;i++){
		if(house[i].bianhao==d){
			break;
		}
	}
	if(i==iii){
		printf("经查询没有此房屋编号，是否重新输入（y/n）");
		c=getchar();
		if(c=='y' || c=='Y'){
			xiugai();
			return;
		} 
		else
			return;
	}
	printf("此房屋信息为：\n");
	shuchu(i);
	printf("\n\n");
	//getchar();
	while(c=='y' || c=='Y'){
		printf("请输入要修改的门类：");
		scanf("%s",a);
			if(strcmp(a,"房屋编号")==0){
				printf("目前房屋编号为：%d\n请输入修改之后的信息：",house[i].bianhao);
				scanf("%d",&house[i].bianhao); 
			}
			else if(strcmp(a,"房屋地址")==0){
				printf("目前房屋地址为：%s\n请输入修改之后的信息：",house[i].dizhi);
				scanf("%s",house[i].dizhi); 
			}
			else if(strcmp(a,"建筑面积")==0){
				printf("目前建筑面积为：%d\n请输入修改之后的信息：",house[i].mianji);
				scanf("%d",&house[i].mianji); 
			}
			else if(strcmp(a,"房屋户型")==0){
				printf("目前房屋户型为：%s\n请输入修改之后的信息：",house[i].huxing);
				scanf("%s",house[i].huxing); 
			}
			else if(strcmp(a,"建设时间")==0){
				printf("目前建设时间为：%d %d %d\n请输入修改之后的信息：",house[i].jiansheshijiann,house[i].jiansheshijiany,house[i].jiansheshijianr);
				scanf("%d",&house[i].jiansheshijiann); 
				scanf("%d",&house[i].jiansheshijiany); 
				scanf("%d",&house[i].jiansheshijianr); 
			}
			else if(strcmp(a,"楼层")==0){
				printf("目前楼层为：%d\n请输入修改之后的信息：",house[i].louceng);
				scanf("%d",&house[i].louceng); 
			}
			else if(strcmp(a,"配套设施")==0){
				printf("目前配套设施为：%s\n请输入修改之后的信息：",house[i].sheshi);
				scanf("%s",house[i].sheshi); 
			}
			else if(strcmp(a,"销售价格")==0){
				printf("目前销售价格为：%d\n请输入修改之后的信息：",house[i].jiage);
				scanf("%d",&house[i].jiage); 
			}
			else if(strcmp(a,"销售状况")==0){
				printf("目前销售状况为：%s\n请输入修改之后的信息：",house[i].zhuangkuang);
				scanf("%s",house[i].zhuangkuang); 
			}
			else if(strcmp(a,"销售时间")==0){
				printf("目前销售时间为：%d %d %d\n请输入修改之后的信息：",house[i].xiaoshoushijiann,house[i].xiaoshoushijiany,house[i].xiaoshoushijianr);
				scanf("%d",&house[i].xiaoshoushijiann); 
				scanf("%d",&house[i].xiaoshoushijiany);
				scanf("%d",&house[i].xiaoshoushijianr);
			}
			else{
				printf("抱歉，没有此门类，如要修改请重新输入（房屋编号/房屋地址/建筑面积/房屋户型/建设时间/楼层/配套设施/销售价格/销售状况/销售时间）\n") ;
			} 
			getchar();
			printf("是否继续修改此编号房屋信息（y/n）");
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
void xianshi(){                           //最后删掉 
	for(int i=0;i<iii;i++){
		printf("房屋编号:%d\n房屋地址:%s\n建筑面积:%d\n房屋户型:%s\n建设时间:%d %d %d\n楼层:%d\n配套设施:%s\n销售价格%d\n销售状况:%s\n销售时间:%d %d %d\n\n",house[i].bianhao,house[i].dizhi,house[i].mianji,house[i].huxing,house[i].jiansheshijiann,house[i].jiansheshijiany,house[i].jiansheshijianr,house[i].louceng,house[i].sheshi,house[i].jiage,house[i].zhuangkuang,house[i].xiaoshoushijiann,house[i].xiaoshoushijiany,house[i].xiaoshoushijianr); 
	}
	printf("\n按任意键返回\n");
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
			printf("指令非法！按回车键返回主页面\n");
			getchar();
			getchar();
		} 
	}
	return 0;
}
///////////////////////////////////////////////////查询一揽子 
void chaxun(){
	int z;
	char c;
	system("cls");
	printf("         *                                                       *\n");
	printf("         *                  1.按房屋编号查询                     *\n");
	printf("         *                  2.按房屋地址查询                     *\n");
	printf("         *                  3.按建筑面积查询                     *\n");
	printf("         *                  4.按户型条件查询                     *\n");
	printf("         *                  5.返回主菜单                         *\n");
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
		printf("指令非法！请重新输入\n");
		getchar();
		getchar();
		chaxun();
		return;
	}
	getchar();
	printf("是否继续查询房屋信息（y/n）");
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
	printf("请输入您想要的户型条件（几室几厅几卫）：");
	scanf("%s",a);
	for(i=0;i<iii;i++)
		if(strstr(house[i].huxing,a)!=NULL){
			shuchu(i);
			sum++;
		} 
	if(sum==0){
		getchar();
		printf("抱歉，没有您想要的户型，是否继续按户型查询（y/n）"); 
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
	printf("请输入您想要的房屋地址（可以是部分地址）：");
	scanf("%s",a);
	for(i=0;i<iii;i++)
		if(strstr(house[i].dizhi,a)!=NULL){
			shuchu(i);
			sum++;
		} 
	if(sum==0){
		getchar();
		printf("抱歉，没有您想要地址的房屋，是否继续按房屋地址查询（y/n）"); 
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
	printf("请输入您想要查询的房屋编号：");
	scanf("%d",&a);
	for(i=0;i<iii;i++){
		if(house[i].bianhao==a){
			break;
		}
	}
	if(i==iii){
		getchar();
		printf("经查询没有此房屋编号，是否重新输入（y/n）");
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
	printf("请输入您想要的房屋面积：");
	scanf("%d",&a);
	for(i=0;i<iii;i++){
		if(house[i].mianji>=a){
			shuchu(i);
			sum++;
		}
	}
	getchar();
	if(sum==0){
		printf("抱歉，没有符合您要求面积的房屋信息！是否继续按面积查询（y/n）");
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
	printf("房屋编号:%d\n房屋地址:%s\n建筑面积:%d\n房屋户型:%s\n建设时间:%d %d %d\n楼层:%d\n配套设施:%s\n销售价格%d\n销售状况:%s\n销售时间:%d %d %d\n\n",house[i].bianhao,house[i].dizhi,house[i].mianji,house[i].huxing,house[i].jiansheshijiann,house[i].jiansheshijiany,house[i].jiansheshijianr,house[i].louceng,house[i].sheshi,house[i].jiage,house[i].zhuangkuang,house[i].xiaoshoushijiann,house[i].xiaoshoushijiany,house[i].xiaoshoushijianr); 
	getchar();
}
///////////////////////////////////////////////////////////统计一箩筐
void tongji(){
	int a;
	char c;
	system("cls");
	printf("         *                                                  *\n");
	printf("         *             1.按月统计房屋销售数量和成交额       *\n");
	printf("         *             2.按季统计房屋销售数量和成交额       *\n");
	printf("         *             3.按户型统计房屋销售数量和比例       *\n");
	printf("         *             4.分类汇总房屋销售状态信息           *\n");
	printf("         *             5.返回主菜单                         *\n");
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
	printf("是否继续统计房屋销售信息（y/n）");
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
	printf("请输入您要查询的销售月份：");
	scanf("%d",&a);
	for(i=0;i<iii;i++)
		if(house[i].xiaoshoushijiany==a){
			sam++;
			sum=sum+house[i].jiage;
		} 
	if(sam==0){
		getchar();
		printf("抱歉，没有您想要的信息，是否重新统计（y/n）"); 
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
	printf("%d月份房屋销售数量为：%d，成交总额为（万元）：%d\n",a,sam,sum);
	return;
}
void jitongji(){
	int a; 
	int i,sam=0,sum=0;
	char c;
	printf("请输入您要查询的季度（1/2/3/4）：");
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
		printf("抱歉，没有您想要的信息，是否重新统计（y/n）"); 
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
	printf("%d季度房屋销售数量为：%d，成交总额为（万元）：%d\n",a,sam,sum);
	return;
}
void huxingtongji(){
	int i,sam=0;
	double d;
	char c,a[100];
	printf("请输入您想要统计的房屋户型：");
	scanf("%s",&a);
	getchar(); 
	for(i=0;i<iii;i++)
		if(strstr(house[i].huxing,a)!=NULL){
			sam++;
		} 
	if(sam==0){
		getchar();
		printf("抱歉，没有您想要的信息，是否重新统计（y/n）"); 
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
	printf("该户型总销售量为：%d，所占比例为：%.0lf %%。\n",sam,d);
	return;
}
void zhuangtaitongji(){
	int i,sam=0,sbm=0,scm=0;
	char c,a[100];
	for(i=0;i<iii;i++)
		if(strstr(house[i].zhuangkuang,"未售")!=NULL){
			sam++;
			shuchu(i);
		} 
	printf("未售房屋共有%d套\n\n\n\n\n",sam);
	for(i=0;i<iii;i++)
		if(strstr(house[i].zhuangkuang,"签约中")!=NULL){
			sbm++;
			shuchu(i);
		} 
	printf("签约中房屋共有%d套\n\n\n\n\n",sbm);
	for(i=0;i<iii;i++)
		if(strstr(house[i].zhuangkuang,"已售")!=NULL){
			scm++;
			shuchu(i);
		} 
	printf("已售房屋共有%d套\n\n\n\n\n",scm);
	if(sam==0 && sbm==0 && scm==0){
		getchar();
		printf("抱歉，没有您想要的信息，按任意键返回"); 
		c=getchar();
		return; 
	}
	return;
} 













