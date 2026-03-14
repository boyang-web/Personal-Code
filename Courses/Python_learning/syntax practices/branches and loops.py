"""
训练分支和循环
采用以下习题
1.给出两个正整数，打印并统计其间素数的个数
2.求最大公约数和最小公倍数
"""

# 打印素数
# first_number=int(input("input first number:"))
# second_number=int(input("input second number:"))
# y=0
# x=0
# for x in range(first_number,second_number+1):
#     if x == 2:
#         print(x)
#     if x != 1 :
#         for y in range(2,x):
#             if (x % y == 0):
#                 break
#         if y == x-1:
#             print(x)
a = 2
b = 1
"""
评价与问题
主要问题在于for else结构不清楚(cpp风格的此类问题标准解法也忘记了)
1.cpp的解法:声明is_prime状态变量确定是否为素数,循环结束后使用语句if(is_prime)
2.python的优化 for: else: 如果循环没被break打破就执行else
"""
# 打印素数
# first_number=int(input("input first number:"))
# second_number=int(input("input second number:"))
# for x in range(first_number,second_number+1):
#     if x<2:
#         continue
#     for y in range(2,x):
#         if x % y == 0:
#             break
#     else:
#         print(x)


# 求最大公约数gcd
# given_number1=200
# given_number2=32
# small_number=min(given_number1,given_number2)
# big_number=max(given_number1,given_number2)
# while small_number!=big_number:
#     temp=max(big_number-small_number,small_number)
#     small_number=min(big_number-small_number,small_number)
#     big_number=temp
# print(small_number)

"""
评价与问题
算法上，辗转相除法用成减损术了
max,min函数没有简单的if-else易读, temp实际上是没有必要出现的
python还支持a , b = b , a的直接交换
实则标准库math里有这个函数
"""

# 求最大公约数gcd
# def gcd(a, b):
#     while b != 0:
#         a, b = b, a % b
#     return a
# print(gcd(1246,19740))

# import math
# print(math.gcd(12,4))
