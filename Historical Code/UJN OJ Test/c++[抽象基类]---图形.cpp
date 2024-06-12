#include<iostream>
#include<string>
using namespace std;
class point{
    public:
        point(int a,int b);
        int getx();
        int gety();
        void inx(int a);
        void iny(int a);
    private:
        int x;int y;
};
point::point(int a,int b){
    x=a;y=b;
}
int point::getx(){
    return x;
}
int point::gety(){
    return y;
}
void point::inx(int a){
    this->x=a;
}
void point::iny(int a){
    this->y=a;
}
class Figure{
    public:
        Figure(int a,int b);
        virtual void rotate(int a)=0;
        virtual void move()=0;
        virtual void draw()=0;
    protected:
        point pp;
};
Figure::Figure(int a,int b):pp(a,b)
{}
class Circle:public Figure{
    public:
        Circle(int a,int b,int rr);
        void move(point q);
        void draw();
    private:
        int r;
};
Circle::Circle(int a,int b,int rr):pp(a,b),r(rr)
{}
void Circle::move(point q){
    pp.inx(q.getx());
    pp.iny(q.gety());
}
void Circle::draw(){
    cout<<"A circle with center ("<<pp.getx()<<", "<<pp.gety()<<" and radius "
    <<this->r<<"."<<endl;
}
class Square:public Figure{
    public:
        Square(int a,int b,int rr,int jd);
        void rotate(int jd);
        void draw();
    private:
        int r;
        int j;
};
Square::Square(point ppp,int rr,int jd):pp(a,b),r(rr),j(jd)
{}
void Square::rotate(int jd){
    this->j=jd;
}
void Square::draw(){
    cout<<"A square with center ("<<pp.getx()<<", "<<pp.gety()<<") side length "
    <<this->r<<". The angle between one side and the X-axis is "<<this->j<<"."<<endl;
}
int main(){
	Circle c(1, 2, 3); //构建圆形，参数：圆心、半径
	Square s(4, 5, 6,0); //构建矩形，参数：
	Figure *f = &c, &g = s;  //基类指针指向子类对象
	f->draw();  //画圆形
	f->move(Point(2, 2));  //将圆移动到（2，2）位置
	f->draw();  //画圆形
	g.draw(); //画矩形
	g.rotate(1); //旋转矩形
	g.draw();
	return 0;
}
