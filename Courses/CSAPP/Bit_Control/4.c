/*CSAPP3e 2.67

【题目内容】

给你一个任务，编写一个函数 int_size_is_32(), 当在一个 int 是 32 位的机器上运行时，该函数返回 1, 而其他情况则返回 0。不允许使用 sizeof 运算符。下面是开始时的尝试:

/* The following code does not run properly on some machines 

int bad_int_size_is_32() {



    /* Set most significant bit (msb) of 32-bit machine 

    int set_msb =  1 << 31;

    /* Shift past msb of 32-bit word 

    int beyond_msb =  1 << 32;



     set_msb is nonzero when word size >= 32

    beyond_msb is zero when word size <= 32 

    return set_msb && !beyond_msb;

}

当在 SUN SPARC 这样的 32 位机器上编译并运行时，这个函数返回的却是 0。下面的编译器信息给了我们一个问题的指示:

warning: left shift count >= width of type



修改代码，使得它在 int 至少为 16 位的任何机器上都能正确地运行。*/


//这个题展示了如何通过代码探测硬件能力——利用溢出
int int_size_is_32() {
    int set_msb = 1 << 15;
    set_msb = set_msb << 15;
    set_msb = set_msb << 1;

    int beyond_msb = set_msb << 1;

    return set_msb && !beyond_msb;
}