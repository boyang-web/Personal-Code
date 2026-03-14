"""
异常处理
    try...except...捕获
    else正常时执行 finally始终执行
异常在函数互相调用中具有传递性，如果异常没有被接收，就会报错
except 后可以接一个由异常名称组成的元组来捕获特定的异常
"""

# 演示四个关键字模式和函数传递异常
def func1():
    print(1/0)

def func2():
    func1()

def testE():
    try:
     func2()
    except Exception as e:
        print(e)
    else:
        print("正常执行")
    finally:
        print("始终执行")
