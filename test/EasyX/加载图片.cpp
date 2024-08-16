#include <graphics.h>
#include<iostream>


// 主函数
int main()
{
	// 绘图窗口初始化
	initgraph(1200, 960);

	//定义图像
	IMAGE img;

	// 读取图片至绘图窗口
	// 相对路径：相对于该CPP文件
	//loadimage(NULL, ("ss.jpg"));
	//绝对路径
	//loadimage(NULL, ("D:\\wg\\VS\\CPP\\test\\EasyX\\ss.jpg"));
	loadimage(NULL, ("D:\\wg\\VS\\CPP\\test\\EasyX\\Myimagine\\dante.jpg"));

	// 按任意键退出
	getchar();
	closegraph();
}