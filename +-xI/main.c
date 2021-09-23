#include <stdio.h>
/*
 *使用位运算 实现正整数 + - / * ^
 *base for lab
 *
 *char +8  0000 1000
 * ~       1111 0111
 * +1      1111 1000
 *char -8  1111 1000

   //位运算符
 * 取负 即为 取反 + 1
 * & and 与   必须有两个 1
 * | or  或   至少有一个 1
 * ~ not 取反 
 * ^ Xor 异或 只能有一个 1

   //逻辑运算符
 * &&  与
 * ||  或
 * !   非
 * xor 异或 
*/
 

/*
* & 取需要进位的位、然后左移1进位
* ^ 取不需进位的位、然后与需要进位的位 重新运算
* 直到 没有需要进位的时候、即 &取出来的值为 0
*/
int add(int a, int b){
	int a1 = a^b;
    int b1 = a&b;
    int tem;
    while(b1){
        printf("%d, %d \n",a1, b1);
        b1 = b1 << 1;
        tem = a1^b1;
        b1 = a1&b1;
        a1 = tem;
    }
    return a1;
}

/*
* 减a = 加 (-a)
*/
int sub(int a, int b){
    return = add(a, add(~b,1));
}

/*
二进制乘法 和 十进制乘法 一样
3 * 5 = 15
     11 = 3
    101 = 5
     11
    00
   11
   1111 = 15
------------
11 * 101 = 11 * 100 + 11 * 00 + 11 * 1
         = 11 < 2   + 0 +  11
         = 1100 + 11
         = 1111 
         = 15
*/
int mul(int a, int b){
    int sum = 0;
    while(b){
        if(b & 1){
            sum = add(sum, a);
        }
        b >>= 1;
        a <<= 1;
    }
    return sum;
}

int divide(int a, int b){
    int sum = 0;
    int i = 31;
    while(i>=0){
        if ((a >> i) >= b){
            sum = add(sum, 1 << i);
            a = sub(a, b<<i);
        }
        i = sub(i, 1);
    }
    return sum;
}

/*
x^y = x^n * x^m
3^7 = 3^4 * 3^2 * 3^1
3^7 = (3^3 * 3^1) * (3^1 * 3^1) * 3^1
*/
int power(int a, int b){
    int sum = 1;
    int tem = 1;
    while(b){
        tem = mul(tem, a);
        if(b&1){
            sum *=tem;
        }
        b>>=1;
    }
}

int main(){
    printf("%d \n", add(3,7));
	return 0;
}
 
