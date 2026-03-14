"""
记录python中遇到过的语法糖(syntactic suger),并给出演示
逻辑组合类：
打包解包类：
- 多变量赋值
- 简易交换
- 数学区间
- 推导式（以列表推导式为例）
- 序列容器切片
"""
 # 多变量赋值
def assignment(a,b,c):
    a, b, c = 1, 2, 3

#简易交换
def swap(a,b):
    a, b = b, a
    
#数学区间(支持多个变量连等)
def is_1_to_10(n):
    if 1 < n < 10:
        return True
    else:
        return False
    
# 列表推导式
def getEven():
    print([n for n in [1,2,3,4,5,6,7,8] if n % 2 == 0])

#序列容器切片
def listCut():
    a=[0,1,2,3,4,5,6,7,8]
    print(f"reverse:{a[::-1]}")
    print(f"从前往后数三个:{a[:3]}")
    print(f"从前数第四个到从后数第三个：{a[3:-2]}")





