//复习priority_queue
#include <iostream>
#include <queue>
using namespace std;

void test1()
{
    cout << "priority_queue默认返回最大元素";
    priority_queue<int> pq;
    pq.push(2);
    pq.push(5);
    pq.push(1);
    cout << "\n最大元素是：" << pq.top();
    cout << "\npq默认的比较函数是less<int> a<b,记住小于号是最大堆即可";

    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(2);
    pq1.push(5);
    cout << "\n最小元素是：" << pq1.top();
    // pq支持的基本操作有：
    // push增 pop删 empty/size/top查 swap改（和完全同类的pq交换）
}
void test2()
{
    // 可以用函数对象进行自定义比较
    // 自定义比较对象
    struct object
    {
        int p1;
        int p2;
        object(int p1_v, int p2_v) : p1(p1_v), p2(p2_v) {}
    };
    object o1(5, 6);
    object o2(3, 4);
    object o3(7, 1);
    // 函数对象
    struct cmp_less_first
    {
        bool operator()(object a, object b)
        {
            return a.p1 < b.p1;
        }
    };
    priority_queue<object, vector<object>,cmp_less_first> pq1;
    //注意这里的cmp是结构体的名字，也就是第三个参数填写的是一种类型
    pq1.push(o1);
    pq1.push(o2);
    pq1.push(o3);
    cout<<"p1最大的object的p2是："<<pq1.top().p2;
    //lambda表达式
    //注意STL设计为当cmp是lambda时，就需要把cmp传给py进行默认构造
    //这基于pq这个对象中有一个比较器成员，需要存储一个对象,函数对象类型可以保证默认构造，lambda匿名对象不能保证这一点
    auto cmp_greater_second =[](object a,object b){return a.p2>b.p2;};
    priority_queue<object ,vector<object>,decltype(cmp_greater_second)> pq2(cmp_greater_second);
    pq2.push(o1);
    pq2.push(o2);
    pq2.push(o3);
    cout<<"\np2最小的object的p1是："<<pq2.top().p1;


}

int main()
{
    test2();
    return 0;
}