// 操作系统课设.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
typedef int datatype1;
#define stackmaxsize 50//超级块的栈大小
#define piecenum 20480//块总数
#define piecesize 1024//块大小 
#define inodesize 32//inode占的字节数

class stack
{
private:
	datatype1 data[stackmaxsize];
	int top;
public:
	stack();//初始化栈
	bool Empty();//判断栈是否为空
	bool full();//判断栈是否已满了
	void Push(int element);//入栈
	void Pop();//出栈
	int getTop();//取栈顶元素
	void Destroy();//销毁栈
	int retop();
};
//typedef struct stack Stack;
int stack::retop() {//得到栈顶号
	return top;
}
stack::stack()//初始化栈
{
	top = -1;
}
bool stack::Empty()//判断栈是否为空
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool stack::full()//判断栈是否已满了
{
	if (top == stackmaxsize - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void stack::Push(int element)//入栈
{
	if (!full())
	{
		top++;
		data[top] = element;
	}
	else
	{
		printf("栈满\n");
	}
}
void stack::Pop()//出栈
{
	if (!Empty())
	{
		top--;
	}
	else
	{
		printf("栈空\n");
	}
}
int stack::getTop()//取栈顶元素
{
	if (!Empty())
	{
		return data[top];
	}
	else
	{
		printf("栈空\n");
	}
}
void stack::Destroy()//销毁栈
{
	top = -1;
}
FILE *fp;
bool makefile() {//初始化文件
	errno_t err;
	char a[1] = { 'z' };
	err = fopen_s(&fp, "unix.txt", "w+" );
	for(int i = 1;i <= 20;i++)
		for (int j = 1; j <= 1024; j++) {
			//fwrite(a, 1, 1024, fp);//这样会乱码
			for (int n = 1; n <= 1024; n++) {
				fprintf(fp, "%c", a[0]);
			}
		}
	return err;
}
struct superpiece{//超级块
	int freepiecenum;
	int filenum;
	int inodenum;
	stack a;
};
struct inode{//i节点
	bool flag;//0是普通文件，1是目录文件
	short iaddr[13];//索引表
	int size;//文件长度,块为单位
	char num;//文件链接计数
	//string time;//最近修改时间
};
struct listpiece{//目录项
	char name[14];
	short inum;//i节点号
};
struct datapiece {
	int free[50];//记录后一组50个盘块号
};
bool makelist() {//初始化目录项
	char a[14] = {"aaaaaaaaaaaaa"};//13个a，1个/0
	short inum = -1;
	/*int fseek(FILE *stream, long offset, int fromwhere);
	成功，返回0，失败返回-1，并设置errno的值，可以用perror()函数输出错误。
	函数设置文件指针stream的位置。如果执行成功，stream将指向以fromwhere
	（偏移起始位置：文件头0，当前位置1，文件尾2）为基准，偏移offset（指针偏移量）个字节的位置。
	如果执行失败(比如offset超过文件自身大小)，则不改变stream指向的位置。*/
	fseek(fp, 2048, 0);//目录节点从2049开始
	for (int i = 1; i <= 640; i++) {
		fprintf(fp, "%s", a);
		fprintf(fp, "%hd", inum);
		fprintf(fp, "%c", ' ');
	}
	return true;
}
bool makeinode(){//初始化i结点
	bool flag = 1;//0是普通文件，1是目录文件
	short iaddr[13];//索引表
	for (int j = 0; j < 13; j++) {
		iaddr[j] = -2;
	}
	int size = -1;//文件长度,字节为单位
	char num = ' ';//文件链接计数
	fseek(fp, 12 * 1024, 0);//目录节点从2049开始
	for (int i = 1; i <= 640; i++) {
		fprintf(fp, "%d", flag);
		fprintf(fp, "%c", ' ');
		for (int j = 0; j < 13; j++) {
			fprintf(fp, "%hd", iaddr[j]);
			fprintf(fp, "%c", ' ');
		}
		fprintf(fp, "%d", size);
		fprintf(fp, "%c", ' ');
		fprintf(fp, "%c", num);
	}
	return true;
}
bool makedata() {//初始化数据块datapiece.free存的是空闲块号
	int address;
	fseek(fp, 32 * 1024, 0);//从第32块开始是数据块
	for (int i = 0; i < 50; i++) {//32-81也是50块！算了就这样吧一样
		fprintf(fp, "%d ", 81 + i);
	}
	
	for (int i = 0; i < 405; i++) {
		address = 81 + i * 50;
		fseek(fp, address * 1024, 0);
		for (int j = 0; j < 50; j++) {
			fprintf(fp, "%d ", address + 50 + j);
		}
	}//最后是20381-20430放进20331中

	fseek(fp, 20381 * 1024, 0);//最后一组20431-20479共49个放进20381的free[1]-free[49]
	fprintf(fp, "%d ", 0);
	for (int j = 0; j < 49; j++) {
		fprintf(fp, "%d ", 20431 + j);
	}
	return true;
}
bool makesupera(superpiece &supera) {//初始化超级点
	supera.freepiecenum = piecenum - 32;
	supera.filenum = 0;
	supera.inodenum = 0;
	for (int i = 32; i < 81; i++) {
		supera.a.Push(i);//第一次把第一组的全都压栈
	}
	return true;
}
void first(superpiece &supera) {//初始化总函数/*首先初始化盘区*/
	makefile();//建立文件打开不关闭
	makelist();
	makeinode();
	makedata();
	makesupera(supera);
}
bool updatesupera(superpiece &supera) {//更新超级点
	int num;
	int kh;
	num = supera.a.getTop();
	cout << "当前栈最后一个块号： " << num;
	supera.a.Pop();
	fseek(fp, num * 1024, 0);//定位到当前快号位置取里面存的下一组空闲块号
	cout << "读到的空闲块号：" << endl;
	for (int i = 0; i < 50; i++) {
		fscanf_s(fp, "%d", &kh);
		if (kh == 0) {
			cout << "抱歉，空间不足！" << endl;
			return false;
		}
		cout << kh << "  ";
		supera.a.Push(kh);
	}
	cout << endl;
	return true;
}
bool distribute(superpiece &supera, int size, int khm[]) {//分配块号
	bool bl=true;
	for (int i = 0; i < size; i++) {
		if (supera.a.retop() == 0) {
			khm[i] = supera.a.getTop();
			bl = updatesupera(supera);
		}
		khm[i] = supera.a.getTop();
		supera.a.Pop();
	}
	if (bl)
		return true;
	else
		return false;
}
void buildfile(superpiece &supera) {//建立文件
	listpiece list;
	inode node;
	bool bl;
	char a[14] = { ' ' }, c = ' ', numm=' ';
	int size, i = 0;
	int khm[piecenum] = { 0 };
	cout << "请输入文件名：（13个字符以内）" << endl;
	while (c != '\n') {
		c = getchar();
		a[i++] = c;
		//list.name[i++] = c;
	}
	//scanf_s("%s", a);
	cout << "请输入文件大小：（字节）" << endl;
	cin >> size;
	getchar();
	size = ceil(size / 1024.0);//从此之后就是块大小啦
	if (supera.freepiecenum < size) {
		cout << "抱歉，空间不足！" << endl;
		return;
	}
	else {
		supera.filenum++;
		fseek(fp, 2 * 1024 + (supera.filenum - 1) * 17, 0);
		for (int i = 0; i < 14; i++) {
			list.name[i] = a[i];
			fprintf(fp, "%c", a[i]);
		}
		fprintf(fp, "%d", supera.inodenum);
		fprintf(fp, "%c", ' ');
		int nodenum;
		nodenum = ceil(size / 10.0);
		supera.freepiecenum = supera.freepiecenum - size;
		bl = distribute(supera, size, khm);
		if (!bl)
			return;
		for (int i = 0; i < size; i++) {//实际分配的块号们
			cout << khm[i] << endl;
		}
		list.inum = supera.inodenum;//目录的i节点号存放目前空闲的i节点位置
		int k = 0;
		node.flag = 0;//普通文件
		node.size = size;
		if (nodenum == 1) {//文件不超过10240字节的一层索引
			fseek(fp, 12 * 1024 + supera.inodenum * (inodesize + 15), 0);
			fprintf(fp, "%d", node.flag);
			fprintf(fp, "%c", ' ');
			for (int i = 0; i < size; i++) {
				node.iaddr[i] = khm[k++];
				fprintf(fp, "%hd", node.iaddr[i]);
				fprintf(fp, "%c", ' ');
			}
			for (int i = size; i < 13; i++) {
				fprintf(fp, "%hd", 0);
				fprintf(fp, "%c", ' ');
			}
			fprintf(fp, "%d", node.size);
			fprintf(fp, "%c", ' ');
			fprintf(fp, "%c", numm);
			supera.inodenum++;
		}
		else {//文件超过10240字节多层索引
			while (size > 10) {
				fseek(fp, 12 * 1024 + supera.inodenum * (inodesize + 15), 0);
				/*if(node.flag==true)
					fprintf(fp, "%d", 1);
				else
					fprintf(fp, "%d", 0);*/
				fprintf(fp, "%d", node.flag);
				fprintf(fp, "%c", ' ');
				//cout << "**********" << node.flag << endl;
				for (int i = 0; i < 10; i++) {
					node.iaddr[i] = khm[k++];
					fprintf(fp, "%hd", node.iaddr[i]);
					fprintf(fp, "%c", ' ');
				}
				supera.inodenum++;
				fprintf(fp, "%d", supera.inodenum);//iaddr[10]=下一个inode
				fprintf(fp, "%c", ' ');
				for (int i = 11; i < 13; i++) {//这些是用来干啥的？？？
					fprintf(fp, "%hd", 0);
					fprintf(fp, "%c", ' ');
				}
				fprintf(fp, "%d", node.size);
				fprintf(fp, "%c", ' ');
				fprintf(fp, "%c", numm);
				size = size - 10;
			}
			fseek(fp, 12 * 1024 + supera.inodenum * (inodesize + 15), 0);
			fprintf(fp, "%d", node.flag);
			fprintf(fp, "%c", ' ');
			for (int i = 0; i < size; i++) {
				node.iaddr[i] = khm[k++];
				fprintf(fp, "%hd", node.iaddr[i]);
				fprintf(fp, "%c", ' ');
			}
			for (int i = size; i < 13; i++) {
				fprintf(fp, "%hd", 0);
				fprintf(fp, "%c", ' ');
			}
			fprintf(fp, "%d", node.size);
			fprintf(fp, "%c", ' ');
			fprintf(fp, "%c", numm);
			supera.inodenum++;
		}
		
	}
}
void overview(superpiece &supera) {//展示系统情况
	listpiece list;
	cout << "本系统共有：" << supera.filenum << "个文件" << endl;
	cout << "共占了：" << supera.inodenum << "个索引节点" << endl;
	cout << "系统还有：" << supera.freepiecenum << "个空闲盘块" << endl;
	for (int i = 0; i < supera.filenum; i++) {
		fseek(fp, 2 * 1024 + i * 17, 0);//习惯上从1开始
		cout << "文件名称为：";
		for (int i = 0; i < 14; i++) {
			fscanf_s(fp, "%c", &list.name[i], 1);
			cout << list.name[i];
		}
		cout << endl;
		fscanf_s(fp, "%hd", &list.inum, 2);
		cout << "文件占的第一个索引节点是：" << list.inum << endl;
	}
}
void openfile() {//打开文件（显示文件占用块号）
	listpiece list;
	inode node;
	int filenumm;
	int flag;
	char y = 'y';
	int khm[piecenum] = { 0 };
	while (y != 'n') {
		cout << "请输入想要打开的文件在文件目录的编号：";
		cin >> filenumm;
		cout << endl;
		fseek(fp, 2 * 1024 + (filenumm - 1) * 17, 0);//习惯上从1开始
		cout << "文件名称为：";
		for (int i = 0; i < 14; i++) {
			fscanf_s(fp, "%c", &list.name[i],1);
			cout << list.name[i];
		}
		cout << endl;
		fscanf_s(fp, "%hd", &list.inum);
		cout << "文件占的第一个索引节点是：" << list.inum << endl;
		fseek(fp, 12 * 1024 + list.inum * (inodesize + 15), 0);
		fscanf_s(fp, "%d", &flag);
		//cout << "**********" << flag << endl;
		//i = (bool)j;j为0 i就为0，j不为0，i就为1
		//node.flag = (bool)flag;
		int k = 0;
		fseek(fp, 12 * 1024 + list.inum * (inodesize + 15) + 1, 0);
		for (int i = 0; i < 10; i++) {
			fscanf_s(fp, "%hd", &node.iaddr[i]);
			if (node.iaddr[i] > 0) {
				khm[k++] = node.iaddr[i];
			}
		}
		fscanf_s(fp, "%hd", &node.iaddr[10]);
		for (int i = 11; i < 13; i++) {//这些是用来干啥的？？？
			fscanf_s(fp, "%hd", &node.iaddr[i]);
		}
		fscanf_s(fp, "%d", &node.size);
		fscanf_s(fp, "%c", &node.num,1);
		while (node.iaddr[10] > 0) {//多层索引
			fseek(fp, 12 * 1024 + node.iaddr[10] * (inodesize + 15), 0);
			fscanf_s(fp, "%d", &flag);
			//i = (bool)j;j为0 i就为0，j不为0，i就为1
			node.flag = (bool)flag;
			for (int i = 0; i < 10; i++) {
				fscanf_s(fp, "%hd", &node.iaddr[i]);
				if (node.iaddr[i] > 0) {
					khm[k++] = node.iaddr[i];
				}
				if (k == node.size) {//以免输出超过块数
					break;
				}
			}
			fscanf_s(fp, "%hd", &node.iaddr[10]);
		}
		cout << "该文件占据块数：" << node.size << endl;
		cout << "该文件类型（0是普通文件，1是目录文件）：" << flag << endl;
		cout << "该文件占据的块号：";
		for (int i = 0; i < k; i++) {
			cout << khm[i] << " ";
		}
		cout << endl;
		cout << "是否继续查看文件（y/n）：";
		cin >> y;
		getchar();
		cout << endl;
	}
}
void remakedata(int kh, int add[51]) {//重新把这50个块放进下一个块内
	fseek(fp, kh * 1024, 0);
	for (int i = 0; i < 50; i++) {
		fprintf(fp, "%d ", add[i]);
	}
}
void remakesupera(int khm[piecenum], int k, superpiece &supera) {//重新把块放回栈里
	int add[51];
	for (int i = 0; i < k; i++) {
		if (supera.a.full()) {//栈满了
			for (int i = 0; i < 50; i++) {
				add[i] = supera.a.getTop();
				supera.a.Pop();
			}
			supera.a.Push(khm[i]);
			remakedata(khm[i], add);//重新把这50个块放进下一个块内
		}
		else {
			supera.a.Push(khm[i]);
		}
	}
}
void remakelist(int filenumm, superpiece &supera, int nodenum) {//释放回收list
	listpiece list;
	for (int i = 0; i < (supera.filenum - filenumm); i++) {
		fseek(fp, 2 * 1024 + (filenumm + i) * 17, 0);//习惯上从1开始
		for (int x = 0; x < 14; x++) {
			fscanf_s(fp, "%c", &list.name[x], 1);
		}
		fscanf_s(fp, "%hd", &list.inum);

		fseek(fp, 2 * 1024 + (filenumm + i - 1) * 17, 0);
		for (int x = 0; x < 14; x++) {
			fprintf(fp, "%c", list.name[x]);
		}
		fprintf(fp, "%d", list.inum - nodenum);
		fprintf(fp, "%c", ' ');
	}
}
void remakeinode(int inum, int nodenum, superpiece &supera) {//释放回收inode,文件首inode号,inode个数
	inode node;
	int flag;
	for (int j = 0; j < nodenum; j++) {
		for (int i = 0; i < (supera.inodenum - inum - j); i++) {
			fseek(fp, 12 * 1024 + (inum + i + 1) * (inodesize + 15), 0);
			fscanf_s(fp, "%d", &flag);
			fseek(fp, 12 * 1024 + (inum + i + 1) * (inodesize + 15) + 1, 0);
			for (int x = 0; x < 10; x++) {
				fscanf_s(fp, "%hd", &node.iaddr[x]);
			}
			fscanf_s(fp, "%hd", &node.iaddr[10]);
			//if (node.iaddr[10] > 0)
			//	node.iaddr[10] = node.iaddr[10] - nodenum;//修改inode链接
			for (int x = 11; x < 13; x++) {//这些是用来干啥的？？？
				fscanf_s(fp, "%hd", &node.iaddr[x]);
			}
			fscanf_s(fp, "%d", &node.size);
			fscanf_s(fp, "%c", &node.num, 1);

			fseek(fp, 12 * 1024 + (inum + i) * (inodesize + 14), 0);
			fprintf(fp, "%c", ' ');
			fprintf(fp, "%d", flag);
			fseek(fp, 12 * 1024 + (inum + i) * (inodesize + 15) + 1, 0);
			fprintf(fp, "%c", ' ');
			for (int x = 0; x < 13; x++) {
				fprintf(fp, "%hd", node.iaddr[x]);
				fprintf(fp, "%c", ' ');
			}
			fprintf(fp, "%d", node.size);
			fprintf(fp, "%c", ' ');
			fprintf(fp, "%c", node.num);
		}
	}
	for (int i = 0; i < (supera.inodenum - nodenum); i++) {//全都移动完再修改inode链接以免减多
		fseek(fp, 12 * 1024 + (inum + i) * (inodesize + 15) + 32, 0);
		fscanf_s(fp, "%hd", &node.iaddr[10]);
		if (node.iaddr[10] > 0)
			node.iaddr[10] = node.iaddr[10] - nodenum;//修改inode链接
		fseek(fp, 12 * 1024 + (inum + i) * (inodesize + 15) + 32, 0);
		fprintf(fp, "%hd", node.iaddr[10]);
	}
}
void delfile(superpiece &supera) {//删除文件
	listpiece list;
	inode node;
	int filenumm;
	char y = 'y';
	int flag;
	int khm[piecenum] = { 0 };
	while (y != 'n') {
		cout << "请输入想要删除的文件编号：";
		cin >> filenumm;
		cout << endl;
		fseek(fp, 2 * 1024 + (filenumm - 1) * 17, 0);//习惯上从1开始
		cout << "删除的文件名称为：";
		for (int i = 0; i < 14; i++) {
			fscanf_s(fp, "%c", &list.name[i], 1);
			cout << list.name[i];
		}
		cout << endl;
		cout << "是否确认删除（y/n）：";
		cin >> y;
		getchar();
		cout << endl;
		if (y == 'y') {
			fscanf_s(fp, "%hd", &list.inum);//文件占的第一个索引节点
			fseek(fp, 12 * 1024 + list.inum * (inodesize + 15), 0);
			fscanf_s(fp, "%d", &flag);
			//cout << "**********" << flag << endl;
			//i = (bool)j;j为0 i就为0，j不为0，i就为1
			//node.flag = (bool)flag;
			int k = 0;
			int nodenum = 1;//该文件inode的个数
			fseek(fp, 12 * 1024 + list.inum * (inodesize + 15) + 1, 0);
			for (int i = 0; i < 10; i++) {
				fscanf_s(fp, "%hd", &node.iaddr[i]);
				if (node.iaddr[i] > 0) {
					khm[k++] = node.iaddr[i];
				}
			}
			fscanf_s(fp, "%hd", &node.iaddr[10]);
			for (int i = 11; i < 13; i++) {//这些是用来干啥的？？？
				fscanf_s(fp, "%hd", &node.iaddr[i]);
			}
			fscanf_s(fp, "%d", &node.size);
			fscanf_s(fp, "%c", &node.num, 1);
			while (node.iaddr[10] > 0) {//多层索引
				nodenum++;//进行一次多层索引inode个数加一
				fseek(fp, 12 * 1024 + node.iaddr[10] * (inodesize + 15), 0);
				fscanf_s(fp, "%d", &flag);
				//i = (bool)j;j为0 i就为0，j不为0，i就为1
				node.flag = (bool)flag;
				for (int i = 0; i < 10; i++) {
					fscanf_s(fp, "%hd", &node.iaddr[i]);
					if (node.iaddr[i] > 0) {
						khm[k++] = node.iaddr[i];
					}
				}
				fscanf_s(fp, "%hd", &node.iaddr[10]);
			}
			remakesupera(khm, k - 1, supera);//重新把块放回栈里
			remakelist(filenumm, supera, nodenum);//释放回收list
			remakeinode(list.inum, nodenum, supera);//释放回收inode,文件首inode号,inode个数
			supera.filenum = supera.filenum - 1;
			supera.freepiecenum = supera.freepiecenum + node.size;
			supera.inodenum = supera.inodenum - nodenum;
			cout << "删除文件成功！" << endl;
		}
		cout << "是否继续删除文件（y/n）：";
		cin >> y;
		getchar();
		cout << endl;
	}
}
int main(){//主函数
	
	superpiece supera;

	char a;
	while (1) {
		//getchar();
		cout << "请选择您的操作：" << endl;
		cout << "1 初始化" << endl;
		cout << "2 建立文件" << endl;
		cout << "3 打开文件" << endl;
		cout << "4 删除文件" << endl;
		cout << "5 显示系统总信息" << endl;
		cout << "6 退出" << endl;
		a = getchar();
		getchar();
		switch (a)
		{
		case '1':
			first(supera);
			cout << "初始化成功！" << endl;
			break;
		case '2':
			buildfile(supera);
			break;
		case '3':
			openfile();
			break;
		case '4':
			delfile(supera);
			break;
		case '5':
			overview(supera);
			break;
		case '6':
			fclose(fp);
			exit(1);
			break;
		default:
			break;
		}
	}
	

	return 0;
}
//测试12000和32000
