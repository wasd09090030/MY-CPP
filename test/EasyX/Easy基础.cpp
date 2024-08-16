#include<iostream>
#include<graphics.h>


int main(){
	//创建窗口，前两个参数为分辨率，后一个参数flag有NOCLOSE,NOMINIMIZE等
	initgraph(1280, 920);

	//设置背景颜色，默认为黑
	setbkcolor(WHITE);//单语句无法将背景设置为白色
	//此刻白色相当于在第二图层，需要加上以下清屏语句,相当于清除当前黑色图层
	cleardevice();

	//设置填充颜色
	setfillcolor(GREEN);
	//设置线条款式
	setlinestyle(PS_SOLID, 7);
	//设置线条颜色
	setlinecolor(RED);

	//画⚪，坐标（50，50），半径40
	//rectangle画矩形，ellipse画椭圆等等
	//circle前面加上fill是有边框填充，加上soolid是无边框填充
	circle(550, 50, 40);

	fillcircle(200, 250, 60);

	//输出文字，默认字体白色，可选RGB颜色
	settextcolor(BLUE);
	//设置文字样式，大小，字体
	settextstyle(60, 0, TEXT("楷体"));
	outtextxy(500,200,TEXT("年后设定"));


	//文字居中显示
	//先画一个矩形,参数分别为左上角与右下角
	rectangle(700, 600, 1000, 800);
	char str[] = "居中显示";
	int width =(150- textwidth(str)/2)+700;
	int highth = (100-textheight(str)/2)+600;
	outtextxy(width,highth,str);

	//避免窗口直接关闭
	getchar();
	//关闭窗口
	closegraph();

	}