"""
此处训练函数的基本操作
- 函数文档的编辑和悬停查看
- 函数的多个返回值
- 多种传参方式
- 函数参数与lambda匿名函数
"""

#函数说明文档：多行注释形式
def myfunc(x,y):
    """
    myfunc函数实现了某功能
    :param x: 形参x表示某含义
    :type x: float
    :param y: 形参y表示某含义
    :type y: int
    :return: 返回值表示某含义
    :rtype: int
    :raises TypeError: 当某些情况时，类型异常
    .. note::
        注意在函数介绍时想要多行换行，只用在第一行末尾加上\\n即可
    """
    return result

#多返回值函数
def multireturn(x,y):
    return x+y,x-y

x, y = multireturn(3,5)
#print(x,y)

"""
位置传参，关键字传参，默认参数解读：
    对于函数参数列表，与cpp一样可以有默认参数，并且有默认值的参数要写在参数列表的最后面
    对于调用时传参，位置传参与cpp一致，关键字传参采取键值对方式，不必考虑参数顺序
    有默认值的参数在关键字传参里可以不写
    两种传参方式可以混用，但位置传参在前，关键字传参在后
"""


#位置参数->关键字参数
def multiPara(name=None, age=None, gender=None):
    print(f"姓名是{name},年龄是{age},性别是{gender}")

def testMultiPara():
    multiPara("jack", 19 , "男")#位置传参
    multiPara(gender="男",age=21)#关键字传参
    multiPara("jack",gender="女")#混用传参

# testMultiPara()

"""
不定长传参解读:
    参数列表中单双星号分别代表不定长参数的位置传递和关键字传递
    实则是解包
"""
def arguLChange(*args):
    print(args)
def kwarguChange(**kwargs):
    print(kwargs)
def testargs():
    arguLChange("1",1,True)
    kwarguChange(a=1,b=2,name="jack")

# testargs()

"""
python中所有函数都是函数对象，都可以直接作为参数传递并直接调用
python中lambda语法：（注意python中lambda只限一行）
    lambda x, y : x + y
即lambda 参数 : 一行代码
"""
def compute(x,y):
    return x + y
def FuncArg(x, y, compute):
    print(compute(x,y))

def testFuncArgAndLambda():
    FuncArg(3,5,compute)
    FuncArg(3,5,lambda x, y : x + y)

# testFuncArgAndLambda()





