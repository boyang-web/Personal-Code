/*
复习unordered_map 和map的基本操作

- 两者的区别：
map 底层是红黑树 操作复杂度是O(log n)
unordered_map 底层是哈希表，平均复杂度是 O(1)

本文件以map为例，unordered_map大部分操作一模一样
*/

#include <map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void test1()
{
    // 统计频次、查找与删除
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 1, 2};
    map<int, int> frq;
    //统计次数的过程中顺便去重
    for (int x : v1)
        frq[x]++; // 注意map会自动创建没有的key-value

    // find函数返回迭代器，找不到就返回end()
    //简单的情形也可以使用count返回0或1
    auto it = frq.find(5);


    // map的迭代器不支持it+1这种随机访问操作，但是可以++
    cout << frq[1] << " " << (++it)->first << endl;

    //删除就没什么特别的
    frq.erase(2);
}

void test2()
{
    // 遍历、排序
    vector<int> v2={4,7,1,9,2,34,8,432,2,1};
    //注意map的参数列表和priority_queue一样，
    // 传入的是类型，用lambda的时候也要传入对象
    map<int,int,greater<int>> mp;
    for(auto x:v2)
    mp[x]++;

    for(auto &p:mp)
    cout<<p.first<<" ";
}

int main()
{
    // test1();
    test2();
    return 0;
}