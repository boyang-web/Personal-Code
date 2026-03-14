"""
简单练习一下input和print
"""


def test0():
    a=input("请输入密码")
    print("正确密码是:%d\n输入的密码是:%d"%(666,int(a)))

# test0()

def test1():
    print("保留两位小数，域宽5：%5.2f"%(float(input("输入多位小数："))) + 
        f"\n原位输出：{input("再次输入数字：")}")

test1()


"""
注意f字符串不能控制精度
input获取的数据默认是str类型，用格式占位符需要数据类型匹配
"""