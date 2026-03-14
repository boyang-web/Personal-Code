"""
练习：统计文章中每个单词出现的数量
    单词通过空格和换行分割
"""

# words={}
# with open("files/article.txt","r", encoding="utf-8") as fr:
#     #解析并存储单词数量
#     for line in fr.readlines():
#         for word in line.replace("\n", "").split(" "):
#             if words.get(word):
#                 words[word] += 1
#             else:
#                 words[word] = 1
# print(words)

"""
评价
整体正确，局部优化
if-else逻辑可以通过get(word, 0) + 1优化掉
两层for逻辑也可以直接用read().spilt()优化
    不了解方法特性导致的
"""

words={}
with open("files/article.txt", "r" , encoding="utf-8") as fr:
    for word in fr.read().split():
        words[word] = words.get(word , 0) + 1
print(words)

#使用counter标准库可以把前四行压缩成一行