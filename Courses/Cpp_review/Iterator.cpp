/*
复习cpp中迭代器的基本操作

*/
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

void test1()
{
    // 基本的迭代器循环,即range for的基本原理
    vector<int> v1 = {1, 2, 3, 4};
    for (auto it = v1.begin(); it != v1.end(); it++)
        cout << *it << " ";
    // 注意等价写法时需要加引用
    for (auto &x : v1)
        cout << x << " ";
}

void test2()
{
    // 迭代器在对内存操作过之后就会失效
    vector<int> v2 = {1, 2, 3, 4};
    auto it = v2.begin() + 1;
    cout << *it;
    v2.push_back(5);
    // 所以建议迭代器即写即用
    auto it2 = v2.begin() + 1;
    cout << "\n"
         << *it << " " << *it2;
}

void test3()
{
    // 迭代器基本操作
    vector<int> v3 = {1, 2, 3, 4, 5};
    auto it = v3.begin() + 2;
    // 获取前后与距离
    auto it1 = next(it);
    auto it2 = prev(it);
    cout << *it << " " << *it1 << " " << *it2 << " " << distance(it2, it1);
    // 注意distance计算的是前一个迭代器要多少步才能走到h后面的迭代器
}

void test4()
{
    // 与其他容器相关的部分操作
    // erase
    vector<int> v4 = {1, 2, 3, 4, 5, 6, 7, 7, 7};
    auto it = v4.erase(v4.begin() + 3);
    cout << "erase会返回新的迭代器\n"
         << *it << endl;
    // find查找失败会返回end()
    auto it1 = find(v4.begin(), v4.end(), 4);
    cout << *(it1 - 1) << endl;
    // sort函数的第三个参数是函数对象而不是类型，不要和priority_queue弄混
    sort(v4.begin(), v4.end(), less<int>());
    for (auto &x : v4)
        cout << x << " ";
    // binary_search返回bool , count统计元素数量
    cout << "\n"
         << binary_search(v4.begin(), v4.end(), 4) << " "
         << count(v4.begin(), v4.end(), 7) << " "
         << count(v4.begin(), v4.end(), 4) << endl;

    // lower_bound 和 upper_bound 返回迭代器
    cout << "lower_bound返回第一个>=x的位置"
         << *lower_bound(v4.begin(), v4.end(), 5) << endl;
    cout << "upper_bound返回第一个>x的位置"
         << *upper_bound(v4.begin(), v4.end(), 5) << endl;
    // 获取下标

    auto it2 = find(v4.begin(), v4.end(), 6);
    cout << it2 - v4.begin() << endl;

    // insert
    v4.insert(v4.begin() + 3, 66);
    for (auto &x : v4)
        cout << x << " ";

    // 区间erase vector和string还略有不同
    string str = "0123456789";
    str.erase(3, 2); // 从3下标开始删除两个
    cout << str << endl;
    v4.erase(v4.begin() + 1, v4.begin() + 4); // 删除区间,注意是左闭右开的设计
    for (auto &x : v4)
        cout << x << " ";
}

int main()
{
    // test1();
    // test2();
    // test3();
    test4();
    return 0;
}