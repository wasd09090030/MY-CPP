/*��˵a=i++������������˼���Ȱ�i��ֵ����a��Ȼ����ִ��i=i+1��
* 
��i��ʼ����3ʱ��ִ��a=i++�����ս��a=3��i=4.

2.��a=++i���������˼����ִ��i=i+1��Ȼ���ڰ�i��ֵ����a��

��i��ʼ����3ʱ��ִ��a=++i�����ս��a=4��i=4.*/

#include<iostream>
#include<vector>
using namespace std;


    int incresase(int k) {
       


        //return ��ֵ��k
        return k++;

      
    }


    int increase2(int k) {

        //return ��ֵ��k+1
        return ++k;
    }

    void showmuns() {

        vector<int> nums = { 1,2,3,4,5,6 };
        int a = 1, b = 1;

        cout << nums[a++] << endl;
        cout << nums[++b] << endl;
    }


    int main() {

        int k = 2;

        int a1 = incresase(k);

        int a2 = increase2(k);

        cout << a1 << endl << a2<<endl;

        showmuns();


    }