"""
演示module的操作
- 各种形式的导入
重名函数使用后导入的那一个
模块中的语句在import的时候会执行一次并缓存，有助于提升效率
- 为了保证测试文档不被执行，于是就有了if__name__=="__main__":
- 为了方便部分引用，有了模块变量__all__，是一个函数对象列表
        import * 的时候只会导入这个列表中的函数

如果引入了python package,再使用方法的时候就需要 包名.模块名.方法名 
导入某个功能的时候语法有变化：
    from package.module import method as name
__init__.py中写__all__来规定import*导入那些module
"""

# 语法：[from 模块名] import [模块|类|变量|函数|*][as 别名]
# (import后面可以逗号连接多个方法)
import time as t
print(1)
t.sleep(1)
print(2)

from time import sleep as sl#引入函数也可起别名，还不用经过模块调用
print(1)
sl(1)
print(2) 

from time import *# *代表引入全部，且不经过模块调用
print(1)
sleep(1)
print(2)

import exceptionHandle as eh
eh.testE()



#测试函数
# if __name__=="__main__":
#test()

#__all__变量模式



