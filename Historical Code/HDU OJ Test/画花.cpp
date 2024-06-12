///////////////////////////////////////////////////
// 程序名称：一束漂亮的花
// 编译环境：Visual C++ 6.0 / 2010，EasyX 2011惊蛰版
// 作　　者：yangw80 <yw80@qq.com>
// 最后修改：2011-9-29
//
#include <graphics.h>
#include <conio.h>
#include <math.h>

#define PI 3.14159265

// 画 花朵
void flower(int x, int y, COLORREF c)
{
	int x1, y1, x2, y2;
    int d = 15;
	double e;
	setcolor(c);
    for(double a = 0; a < 2 * PI; a += PI / 360)
    {
		e = d * (1 + sin(a * 5));
        x1 = int(x + e * cos(a));
        y1 = int(y + e * sin(a));
        x2 = int(x + e * cos(a + PI / 5));
        y2 = int(y + e * sin(a + PI / 5));
        line(x1, y1, x2, y2);
	}
}

// 画 蝴蝶结
void tie(int x, int y, COLORREF c)
{
	int x1, y1, x2, y2;
    int d = 80;
	double e;
	setcolor(c);
    for(double a = 0; a < 2 * PI; a += PI / 360)
    {
		e = d * (1 + sin(a * 4));
        x1 = int(x + e * cos(a));
        y1 = int(y + e * sin(a) / 2);
        x2 = int(x + e * cos(a + PI / 9));
        y2 = int(y + e * sin(a + PI / 9) / 4.5);
        line(x1, y1, x2, y2);
	}
}

// 主函数
void main()
{
	initgraph(640, 480);
	
	// 画枝干
	setcolor(GREEN);
	line(189, 372, 180, 400);
	line(310, 160, 325,  68);
	line(310, 160, 187, 374);
	line(150, 140, 189, 374);
	line(430, 176, 190, 374);
	line(370, 110, 187, 374);
	line(250,  72, 189, 372);
	line(253, 192, 190, 374);
	line(189, 372, 187, 400);
	line(189, 372, 182, 400);
	line(189, 372, 200, 120);

	// 画花朵
	flower(320, 160, RED);
	flower(200, 120, YELLOW);
	flower(150, 140, LIGHTRED);
	flower(430, 176, RGB(255, 127, 0));
	flower(370, 110, RGB(239, 179, 52));
	flower(250,  72, RGB(235, 95, 186));
	flower(325,  68, RGB(228, 119, 98));
	flower(253, 190, RGB(247, 169, 117));

	// 画蝴蝶结
	tie(195, 354, LIGHTMAGENTA);
	
	// 按任意键退出
	getch();
	closegraph();
}
