/*先说a=i++，这个运算的意思是先把i的值赋予a，然后在执行i=i+1；
* 
当i初始等于3时，执行a=i++，最终结果a=3，i=4.

2.而a=++i，这个的意思是先执行i=i+1，然后在把i的值赋予a；

当i初始等于3时，执行a=++i，最终结果a=4，i=4.*/

#include<iostream>
#include<vector>
using namespace std;


    int incresase(int k) {
       


        //return 的值是k
        return k++;

      
    }


    int increase2(int k) {

        //return 的值是k+1
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