"""
记录遇到的容器操作技巧
- 各种原始方法
- collection库

"""
# dict的get方法，常用于统计计数、给默认值
#实际上就是安全查询
def test_get():
    words={}
    for word in ["w1","w2"]:
        words[word]= words.get(word, 0)+ 1
#注意：不建议if dict.get() 判断某元素不存在，不能排除一个元素的value是0的情况

