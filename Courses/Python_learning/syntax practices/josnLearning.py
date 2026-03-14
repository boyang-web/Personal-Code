"""
简要记录json相关操作
"""
import json

data=[{"name":"jack"},{"name":"micheal"}]
#list/dict转json字符串
json_str=json.dumps(data,ensure_ascii=False)# 关闭ascii码，这样就正常unicode编码了
print(type(json_str))
#json字符串转list/dict
print(type(json.loads(json_str)))