#include <graphics.h>
#include<iostream>


// ������
int main()
{
	// ��ͼ���ڳ�ʼ��
	initgraph(1200, 960);

	//����ͼ��
	IMAGE img;

	// ��ȡͼƬ����ͼ����
	// ���·��������ڸ�CPP�ļ�
	//loadimage(NULL, ("ss.jpg"));
	//����·��
	//loadimage(NULL, ("D:\\wg\\VS\\CPP\\test\\EasyX\\ss.jpg"));
	loadimage(NULL, ("D:\\wg\\VS\\CPP\\test\\EasyX\\Myimagine\\dante.jpg"));

	// ��������˳�
	getchar();
	closegraph();
}