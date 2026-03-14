/*
复现csapp中show_bytes函数
基本原理是获取代读取数据的地址
利用char指针数组进行分割存储
再遍历对指针解引用，并且用十六进制输出
*/

#include <stdio.h>

void show_bytes(char* pc, int len)
{
    for (int i = 0; i < len; i++)
        printf("%.2x\n", pc[i]);
}

int main()
{
    int a = 16*17;
    show_bytes((char*)&a, sizeof(int));
    return 0;
}