/*
CSAPP3e 2.61

【题目内容】

分别写四个 C 表达式，表达式在满足下列条件时值为 1, 而在其他情况下值为 0。其中所有的 x 都是 int 类型。
A. x 的任何位都等于 1
B. x 的任何位都等于 0
C. x 的最低有效字节中的位都等于1
D. x 的最高有效字节中的位都等于0

本题禁止使用 == 和 != 运算符。
*/

int A(int x) {
    return !(~x);
}

int B(int x) {
    return !x;
}

int C(int x) {
    return !(~(x & 0xFF) & 0xFF);
}

int D(int x) {
    int w=sizeof(x)<<3;
    return !((x>>(w-8))) ;
}