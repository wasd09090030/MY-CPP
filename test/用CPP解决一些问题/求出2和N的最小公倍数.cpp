class Solution {
public:
    int smallestEvenMultiple(int n) {
        if (n % 2 == 0)
            return n;
        else
            return 2 * n;
    }
};


//��� n ��������n �Ķ�������ʽ�����λΪ 1������ n & 1 �Ľ���� 1��
//��� n ��ż����n �Ķ�������ʽ�����λΪ 0������ n & 1 �Ľ���� 0��

class Solution02 {
public:
    int smallestEvenMultiple(int n) {
        if (n & 1) return n * 2;
        else return n;
    }
};