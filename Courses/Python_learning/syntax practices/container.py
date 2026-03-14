"""
初学容器的各种方法
    切片：str[x:y:z] x,y 是区间端点，左闭右开,z是步长 切片表达式产生的也是一个str
    可以继续下表访问 str[::-1]就是reverse操作了
    (元组tuple)[列表list]{集合set}
    默认构造：
        所有的容器都可以直接加括号生成空容器
        a = ()生成元组
        a = []生成列表
        a = {}生成字典
    通用操作：len1取长度  max min取最大最小元素(str按照ASCII码字典序比较)
             list() tuple() set() str() 可以实现转化
             注意字典转换成list tuple set只取key
             其他数据类型转字符串实则只是加了俩引号
        sorted(容器)可以排序,默认降序
        对于dict来说，默认按照key的字典序排序 ，返回list
        参数列表中加入reverse=Ture就能升序，还支持自定义比较函数

"""
#list
def listPractice():
    """
    演示list的功能:
        不限制数据类型存储\n
        打印list，支持切片打印
        获取长度
        下标索引元素进行获取和修改，支持负数索引从后往前
        查询元素索引
        插入元素
        单个追加、批量追加
        根据索引删除元素中pop不写参数默认是最后一个，del支持切片删除
        根据内容删除元素删的是第一个匹配项
        统计某元素出现数量
        清空列表
    .. note::
        注意切片区间读取的内容是左闭右开 
    """
    list1=[1,"a",True,[1,"a"]]

    print("list的数据类型是:"+str(type(list1)))

    print(f"打印list:{list1},切片打印:{list1[1:3]}")

    print(f"list的长度:{len(list1)}")

    print(f"list的第二个元素:{list1[1]}, 第四个元素中的第二个元素是{list1[3][-1]}")

    print(f"查询a的索引:{list1.index("a")}")#不存在会报错

    list1.insert(1,"insert")#参数列表是新元素的索引、数据
    print(f"插入元素后的list:{list1}")

    list1.append("append")
    print(f"追加单个元素后的list:{list1}")

    list1.extend(["extend","extend","extend"])
    print(f"批量追加后list:{list1}")

    print(f"删掉末尾元素：{list1.pop()}，pop末尾元素后：{list1}")#pop可以返回删除的元素
    del list1[-4:-2]
    print(f"切片删除后：{list1}")

    list1.remove("a")
    print(f"删除掉a后的list:{list1}")

    print(f"统计extend的数量:{list1.count("extend")}")

    list1.clear()
    print(f"清空完成后的list:{list1}")

# listPractice()

def tuplePractice():
    """
    演示tuple的功能:(由于是不可变列表，所以主要是查询类的方法)\n
        定义空元组
        元组下表索引元素
    .. note::
        只需注意元组是小括号即可
    """
    tuple1=(1,2,3,"char",["list1","list2"],False)
    emptyTuple=()#或者是emptyTuple=tuple()

    #同样支持下标索引   
    print(tuple1[4][1])
    #同样支持len , count , index方法

#tuplePractice()

def strPractice():
    """
    演示str的方法
        同样支持切片打印\n
        同样支持len , count , index 对单个字符的查找操作
        index . count 索引还承担的查询字串的工作
        replace子串更换
        split按照字符切分
        strip规整字符串：去前后空格 或者去前后指定字符串
    .. note::
        注意str实际上也是不可以修改的，只能间接创造新的字符串\n
        所以修改操作得到的字符串都已返回值呈现\n
        注意strip去前后字符串是按照单个字符计算的
    """
    str1=" abcd f a "
    print(f"打印字符串：{str1}")

    print(f"查询字串bcd的位置：{str1.index("bcd")}")

    print(f"替换字符串：{str1.replace("abc","替换 后的字 符串")}，此时原字符串不变：{str1}")

    print(f"按照空格切分字符串，存入列表：{str1.split(" ")}")

    print(f"去前后空格：{str1.strip()}，去前后字符串：{str1.strip(" a")}")

# strPractice()

def setPractice():
    """
    演示set的方法\n
    add增加元素,remove移除元素
    .. note::
        注意集合使用的是大括号{}\n
        集合自动去重，但是没有顺序\n
        注意set中的pop是弹出元素，原set会被修改\n
        clear清空\n
        difference/difference_update intersection union进行交并补计算\n
        同样支持len for循环\n
        注意a = { } 创建的是空字典
    """
    set1={"1","2","4"}
    set2={"1","3","4"}

    set1.add("3")
    print(f"添加元素后的set:{set1}")

    print(f"弹出元素是{set1.pop()},pop元素后的set:{set1}")

    print(f"获得set1一侧的差集:{set1.difference(set2)} , 获得交集：{set1.intersection(set2)}")
    set1.difference_update(set2)
    print(f"直接对set1操作，获得差集：{set1}")
    print(f"获得并集：{set1.union(set2)}")
  
# setPractice()

def dictPractice():
    """
    演示dict的方法\n
        支持键值对索引
        支持pop删除
        支持clear清空
        支持keys获取全部key
        支持for循环遍历
    .. note::
        注意dict的定义是大括号内用逗号分隔的键值对\n
        注意keys返回的对象不是列表，但支持列表形式的遍历\n
        字典的嵌套可以储存有表头的表格

    """
    dict1={"k3":1 , "k2": 2 , "k1":3}
    print(f"原字典：{dict1}")

    dict1.pop("k2")
    print(f"pop删除后的字典:{dict1}")

    print(f"获取全部的key:{dict1.keys()}")

    
    

dictPractice()

