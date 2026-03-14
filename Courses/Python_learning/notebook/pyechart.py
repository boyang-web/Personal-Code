"""
练习使用pyechart绘图
"""
# 折线图
from pyecharts.charts import Line
from pyecharts.options import TitleOpts
def create_line():
    line=Line()
    line.add_xaxis(["A","B","C","D","E"])
    line.add_yaxis("indicator", [1, 3, 5, 6, 3])
    #设置全局配置项来丰富功能
    line.set_global_opts(
        title_opts=TitleOpts(title="indicator展示",pos_left="center")
    )
    line.render()


create_line()