"""
练习基础文件操作
语法:open(file, mode, encoding)
示例:f=open("a.txt", "r", encoding="utf-8")
解读:文件路径在不同环境下有区别，vscode以当前打开的文件夹作为根目录
     写path时../代表上级file/代表下级,还有pathlib里更高级的path工程方案
     模式: r 只读（默认）  w 写入（会先清空）  a 追加（a/w如果没有文件会新建文件）
        还有后缀 b 二进制  + 读写 
        示例： rb 二进制读  w+ 清空文件后读写
     编码模式建议保持utf-8 注意这里是关键字传参+字符串（不要忘记冒号）
操作流程：open  read/write  flush  close
解读：open/close打开关闭文件
     flush将缓冲区内容写入文件，提高效率。close内置了flush
     读文件：f.read()读取全部,输出成一个字符串
            f.read(10)读取前十个字符
            f.readline()读一行(\n也会读进去)
            f.readlines()读取全部，按行输出成一个字符串列表（带有\n）
            for line n f:最优的循环遍历
     写文件：f.write(内容)只支持写字符串类型
            writelines(["a\n" , "b\n" , "c\n"])写多行，但得自己带换行符
更改文件指针位置：f.seek(位置) 位置填写0就是文件开头
    a模式指针默认在末尾


"""

#读写演示，去除换行符和空格写在源文件后
# with open("test.txt" , "w", encoding="utf-8") as fw:
#     fw.writelines(["1 234 5 6\n", "7 8\n", "9 0\n"])

with open("test.txt", "a+", encoding="utf-8") as fa:
    fa.seek(0)
    for line in fa.readlines():
        fa.write(line.replace(" ","").replace("\n",""))


