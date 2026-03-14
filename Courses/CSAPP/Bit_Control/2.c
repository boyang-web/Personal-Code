/*
CSAPP3e 2.63

【题目内容】

将下面的 C 函数代码补充完整。
函数 srl 用算术右移(由值 xsra 给出)来完成逻辑右移，
后面的其他操作不包括右移或者除法。
函数 sra 用逻辑右移(由值 xsrl 给出)来完成算术右移，
后面的其他操作不包括右移或者除法。
注意，可以通过计算 sizeof(int) << 3 来确定数据类型 int 的位数 w，
位移量 k 的取值范围为 0~w-1 。
*/

unsigned srl(unsigned x, int k) {

    /* Perform shift arithmetically */
    int w=sizeof(int)<<3;
    unsigned xsra = (int) x >> k ;

   // 补全代码
    int mask=(1<<w-k)-1;
    return xsra &mask; 


}


//很恶心的不让再用右移了
//采取反码+1的方式得到-1
int sra(int x, int k) {

    /* Perform shift logically */ 
    int w=sizeof(int)<<3;
    int xsrl = (unsigned) x >> k ;

    // 补全代码
    int sign=x &(1<<(w-1));
    sign=!!(sign);
    sign=~sign+1;

    int mask=~((1<<(w-k))-1);


    return xsrl |(mask&sign);



}