class Solution {
public:
    int smallestEvenMultiple(int n) {
        if (n % 2 == 0)
            return n;
        else
            return 2 * n;
    }
};


//如果 n 是奇数，n 的二进制形式的最低位为 1，所以 n & 1 的结果是 1。
//如果 n 是偶数，n 的二进制形式的最低位为 0，所以 n & 1 的结果是 0。

class Solution02 {
public:
    int smallestEvenMultiple(int n) {
        if (n & 1) return n * 2;
        else return n;
    }
};