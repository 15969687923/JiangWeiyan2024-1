#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<graphics.h>
int?a,visit[30][15],Color[30][15],minX=30,minY=30,maxX=310,maxY=610,speed=500,score=0,rank=0;??
??int?color[]={GREEN,CYAN,MAGENTA,BROWN,LIGHTGRAY,LIGHTBLUE,LIGHTGREEN,LIGHTRED,YELLOW};??
??int?block[36][5][5]=??
??{??
??????{0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0},??
??????{0,0,1,1,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,0,0,0,1,1,0},??
??????{0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,1,0,1,0,0,0,0,0},??
??????{0,1,1,0,0,0,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0,1,1,0,0},??
??????{0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,1,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,1,1,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,1,1,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},??
??????{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0}??
??};??
??void?Interface();//界面的设计??
??void?nextblock();//生成下一个方块??
??void?newblock();//将下一个放到主方框中??
??void?move(int?x,int?y,int?A);//移动方块??
??int?couldmove(int?x0,int?y0,int?A,char?dir,int?next);//判断能否移动??
??int?couldrotate(int?x0,int?y0,int?A,int?next);//判断能否旋转??
??void?mark(int?x0,int?y0,int?A,int?next);//标记方块固定后的位置??
??void?full();//判断有没有能够消行的??
??void?down(int?x);//有消行的将上面的方块下移一行??
??int?gameover();//判断游戏是否结束??
??int?main()??
??{??
??????int?i,j;??
??????Interface();??
??????nextblock();??
??????Sleep(500);??
??????memset(visit,0,sizeof(visit));??
??????while(1)??
??????{??
??????newblock();??
??????full();??
??????if(gameover())??
??????????break;??
??????}??
??????getch();??
??????closegraph();??
??????return?0;??
??}??
??void?Interface()??
??{??
??????int?i,j;??
??????char?str[10];??
??????initgraph(550,?660);??
??????HWND?hwnd?=?GetHWnd();??
??????SetWindowText(hwnd,?"NEW俄罗斯方块?????????????????制作:丶阿明");??
??????Sleep(2000);??
??????setfont(40,0,"隶体");??
??????setcolor(RED);??
??????outtextxy(145,200,"NEW");??
??????setfont(40,0,"楷体");??
??????for(i=0;i<=255;i++)??
??????????for(j=0;j<=255;j++)??
??????????{??
??????????????setcolor(RGB((i+j+128)%255,i,j));??
??????????????outtextxy(205,200,"俄罗斯方块!");??
??????????}??
??????????Sleep(2000);??
??????????setcolor(YELLOW);??
??????????setfont(22,0,"隶体");??
??????????outtextxy(310,300,"←_←");??
??????????setfont(22,0,"楷体");??
??????????outtextxy(180,300,"这逼装的可以");??
??????????setcolor(LIGHTMAGENTA);??
??????????Sleep(2500);??
??????????outtextxy(175,300,"请按任意键开始游戏!");??
??????????getch();??
??????????cleardevice();??
??????????setcolor(WHITE);??
??????????rectangle(29,29,334,633);??
??????????rectangle(28,28,335,634);??
??????????rectangle(370,50,515,195);??
??????????setfont(24,0,?"楷体");??
??????????setcolor(LIGHTGRAY);??
??????????outtextxy(405,215,"下一个:");??
??????????setcolor(RED);??
??????????outtextxy(405,280,"分数:");??
??????????sprintf(str,"%d",score);??
??????????outtextxy(415,310,str);??
??????????outtextxy(405,375,"等级:");??
??????????sprintf(str,"%d",rank);??
??????????outtextxy(425,405,str);??
??????????setfont(22,0,?"楷体");??
??????????setcolor(LIGHTBLUE);??
??????????outtextxy(390,475,"操作说明:");??
??????????outtextxy(390,500,"↑:?旋转");??
??????????outtextxy(390,525,"↓:?下降");??
??????????outtextxy(390,550,"←:?左移");??
??????????outtextxy(390,575,"→:?右移");??
??????????outtextxy(390,600,"空格:?暂停");??
??}??
??void?nextblock()??
??{??
??????int?i,j,x=391,y=71;??
??????setfont(23,0,"楷体");??
??????setcolor(BLACK);??
??????for(i=0;i<5;i++)??
??????????for(j=0;j<5;j++)??
??????????????outtextxy(x+20*j,y+20*i,"■");??
??????????srand(time(NULL));??
??????????a=rand()%9;??
??????????setcolor(color[a]);??
??????????for(i=0;i<5;i++)??
??????????????for(j=0;j<5;j++)??
??????????????????if(block[4*a][i][j]==1)??
??????????????????????outtextxy(x+20*j,y+20*i,"■");??
??}??
??void?newblock()??
??{??
??????int?i,j,x=130,y=30,A=a;??
??????if(A==0||A==1||A==6)??
??????????y-=60;??
??????else?if(A==2||A==3||A==5||A==7||A==8)??
??????????y-=40;??
??????else??
??????????y-=80;??
??????setfont(23,0,"楷体");??
??????setcolor(color[A]);??
??????for(i=0;i<5;i++)??
??????????for(j=0;j<5;j++)??
??????????????if(block[4*A][i][j]==1&&y+20*i>=30)??
??????????????????outtextxy(x+20*j,y+20*i,"■");??
??????????????Sleep(100);??
??????????????nextblock();??
??????????????move(x,y,A);??
??}??
??void?move(int?x,int?y,int?A)??
??{??
??????int?i,j,f,k=0,next=0,Speed=speed,key,nex;??
??????while(1)??
??????{??
??????????f=couldmove(x,y+k,A,'x',next);??
??????????if(f==0)??
??????????{??
??????????????mark(x,y+k,A,next);??
??????????????break;??
??????????}??
??????????if(kbhit())??
??????????{??
??????????????key=getch();??
??????????????if(key==32)??
??????????????????getch();??
??????????}??
??????????setcolor(BLACK);??
??????????for(i=0;i<5;i++)??
??????????????for(j=0;j<5;j++)??
??????????????????if(block[4*A+next][i][j]==1&&y+20*i+k>=30)??
??????????????????????outtextxy(x+20*j,y+20*i+k,"■");??
??????????????????if(kbhit())??
??????????????????{??
??????????????????????key=getch();??
??????????????????????if(key==72)??
??????????????????????{??
??????????????????????????nex=(next+1)%4;??
??????????????????????????if(couldrotate(x,y+k,A,nex))??
??????????????????????????????next=nex;??
??????????????????????}??
??????????????????????else?if(key==80)??
??????????????????????????Speed=50;??
??????????????????????else?if(key==75&&couldmove(x,y+k+20,A,'z',next))??
??????????????????????????x-=20;??
??????????????????????else?if(key==77&&couldmove(x,y+k+20,A,'y',next))??
??????????????????????????x+=20;??
??????????????????}??
??????????????????setcolor(color[A]);??
??????????????????for(i=0;i<5;i++)??
??????????????????????for(j=0;j<5;j++)??
??????????????????????????if(block[4*A+next][i][j]==1&&y+20*i+k+20>=30)??
??????????????????????????????outtextxy(x+20*j,y+20*i+k+20,"■");??
??????????????????????????Sleep(Speed);??
??????????????????????????k+=20;??
??????????????}??
??}??
??int?couldmove(int?x0,int?y0,int?A,char?dir,int?next)??
??{??
??????int?i,j,x,y,f=1;??
??????x=(y0-minY)/20;??
??????y=(x0-minX)/20;??
??????if(dir=='x')??
??????{??
??????????for(i=0;i<5;i++)??
??????????????for(j=0;j<5;j++)??
??????????????if(block[4*A+next][i][j]==1&&(x+i+1==30||(x+i+1>=0&&x+i+1<30&&y+j>=0&&y+j<15&&visit[x+i+1][y+j]==1)))??
??????????????????f=0;??
??????}??
??????else?if(dir=='z')??
??????{??
??????????for(i=0;i<5;i++)??
??????????????for(j=0;j<5;j++)??
??????????????????if(block[4*A+next][i][j]==1&&(y+j==0||(x+i>=0&&x+i<30&&y+j-1>=0&&y+j-1<15&&visit[x+i][y+j-1]==1)))??
??????????????????????f=0;??
??????}??
??????else?if(dir=='y')??
??????{??
??????????for(i=0;i<5;i++)??
??????????????for(j=0;j<5;j++)??
??????????????????if(block[4*A+next][i][j]==1&&(y+j+1==15||(x+i>=0&&x+i<30&&y+j+1>=0&&y+j+1<15&&visit[x+i][y+j+1]==1)))??
??????????????????????f=0;??
??????}??
??????return?f;??
??}??
??int?couldrotate(int?x0,int?y0,int?A,int?next)??
??{??
??????int?i,j,x,y,f=1;??
??????x=(y0-minY)/20;??
??????y=(x0-minX)/20;??
??????if(!couldmove(x0,y0,A,'x',next))??
??????????f=0;??
??????for(i=0;i<5;i++)??
??????????for(j=0;j<5;j++)??
??????????????if(block[4*A+next][i][j]==1&&(y+j==-1||y+j==15||(x+i>=0&&x+i<30&&y+j>=0&&y+j<15&&visit[x+i][y+j]==1)))??
??????????????????f=0;??
??????????????return?f;??
??}??
??void?mark(int?x0,int?y0,int?A,int?next)??
??{??
??????int?i,j,x,y;??
??????x=(y0-minY)/20;??
??????y=(x0-minX)/20;??
??????for(i=0;i<5;i++)??
??????????for(j=0;j<5;j++)??
??????????????if(block[4*A+next][i][j]==1)??
??????????????{??
??????????????????visit[x+i][y+j]=1;??
??????????????????Color[x+i][y+j]=color[A];??
??????????????}??
??}??
??void?full()??
??{??
??????int?i,j,k=0;??
??????char?str[10];??
??????for(i=29;i>=0;i--)??
??????{??
??????????for(j=0;j<15;j++)??
??????????????if(visit[i][j]==0)??
??????????????????break;??
??????????????if(j==15)??
??????????????{??
??????????????????k++;??
??????????????????down(i);??
??????????????????i++;??
??????????????}??
??????}??
??????setcolor(RED);??
??????score+=10*k;??
??????sprintf(str,"%d",score);??
??????outtextxy(415,310,str);??
??????rank=(score/50);??
??????sprintf(str,"%d",rank);??
??????outtextxy(425,405,str);??
??????speed=500-100*rank;??
??????if(speed==0)??
??????????speed=100;??
??????if(score>=300)??
??????????speed=75;??
??}??
??void?down(int?x)??
??{??
??????int?i,j;??
??????for(i=x;i>0;i--)??
??????????for(j=0;j<15;j++)??
??????????????if(visit[i-1][j]==1)??
??????????????{??
??????????????????visit[i][j]=visit[i-1][j];??
??????????????????Color[i][j]=Color[i-1][j];??
??????????????????setcolor(Color[i-1][j]);??
??????????????????outtextxy(minX+20*j,minY+20*i,"■");??
??????????????}??
??????????????else??
??????????????{??
??????????????????visit[i][j]=visit[i-1][j];??
??????????????????setcolor(BLACK);??
??????????????????outtextxy(minX+20*j,minY+20*i,"■");??
??????????????}??
??????????????setcolor(BLACK);??
??????????????for(j=0;j<15;j++)??
??????????????{??
??????????????????visit[0][j]=0;??
??????????????????outtextxy(minX+20*j,minY,"■");??
??????????????}??
??}??
??int?gameover()??
??{??
??????int?i,j;??
??????for(i=0;i<15;i++)??
??????????if(visit[0][i]==1)??
??????????{??
??????????????for(i=0;i<=7;i++)??
??????????????{??
??????????????????setcolor(RGB(35*i,255-35*i,255));??
??????????????????for(j=i;j<30-i;j++,Sleep(20))??
??????????????????????outtextxy(30+20*i,30+20*j,"■");??
??????????????????for(j=i;j<15-i;j++,Sleep(20))??
??????????????????????outtextxy(30+20*j,30+20*(29-i),"■");??
??????????????????for(j=30-1-i;j>=i;j--,Sleep(20))??
??????????????????????outtextxy(30+20*(14-i),30+20*j,"■");??
??????????????????for(j=15-1-i;j>=i;j--,Sleep(20))??
??????????????????????outtextxy(30+20*j,30+20*i,"■");??
??????????????}??
??????????????setcolor(WHITE);??
??????????????setfont(45,0,"隶体");??
??????????????outtextxy(75,300,"GAME?OVER!");??
??????????????Sleep(5000);??
??????????????return?1;??
??????????}??
??????????return?0;??
??}??
