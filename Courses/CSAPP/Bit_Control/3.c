/*
CSAPP3e 2.71

【题目内容】

你刚刚开始在一家公司工作，他们要实现一组过程来操作一个数据结构，
要将 4 个有符号字节封装成一个 32 位unsigned。
一个字中的字节从 0 (最低有效字节)编号到 3 (最高有效字节)。
分配给你的任务是:为一个使用补码运算和算术右移的机器编写一个具有如下原型的函数:

 Declaration of data type where 4 bytes are packed into an unsigned 

typedef unsigned packed_t;



Extract byte from word. Return as signed integer 

int xbyte(packed_t word, int bytenum);



也就是说，函数会从 32 位 unsigned 中抽取出指定的字节，
再把它符号扩展为一个 32 位 int。

你的前任(因为水平不够高而被解雇了)编写了下面的代码:



Failed attempt at xbyte 

int xbyte(packed_t word, int bytenum) {

    return (word >> (bytenum << 3)) & 0xFF;

}

给出函数的正确实现，只能使用左右移位、最多一个减法和强制类型转换。
*/
//恶心的没边了
typedef unsigned packed_t;
int xbyte(packed_t word, int bytenum);
int xbyte(packed_t word, int bytenum)
{
 
    return ((int)word << ((3 - bytenum) << 3)) >> 24;
}