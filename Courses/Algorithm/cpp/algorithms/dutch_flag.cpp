/*
【问题描述】
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，
原地 对它们进行排序，
使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

必须在不使用库内置的 sort 函数的情况下解决这个问题。
（注意！通过的代码会被复查）

【输入形式】
第一行一个正整数 n，保证 n 小于 100。
第二行 n 个用空格隔开的整数 a[1]...a[n]，取值为 0, 1, 2。
【输出形式】
一行 n 个用空格隔开的整数，表示排序后的结果
【样例输入】
6
2 0 2 1 1 0
【样例输出】
0 0 1 1 2 2
【样例说明】
*/

#include <iostream>
using namespace std;
// 两轮交换的版本
// 注意red 的 0 和color初始化默认的0不要冲突了
void solution1()
{
    int color[101];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> color[i];

    int slow = 0;

    int red = 0;
    while (red < n)
    {
        if (color[red] == 0)
        {
            swap(color[red], color[slow]);
            slow++;
        }
        red++;
    }

    int white = slow;
    while (white < n)
    {
        if (color[white] == 1)
        {
            swap(color[white], color[slow]);
            slow++;
        }
        white++;
    }

    for (int i = 0; i < n; i++)
        cout << color[i] << " ";
}

// 荷兰国旗（三指针）法
/*
靠中间的指针遍历，滑动两边的指针
临界情况也能很好的适应
*/
void solution2()
{
    int color[101];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> color[i];

    int begin = 0, end = n - 1;
    int mid = 0;
    while (mid <= end)
    {
        if (color[mid] == 0)
        {
            swap(color[mid], color[begin]);
            begin++;
            mid++;
        }
        else if (color[mid] == 1)
        {
            mid++;
        }
        else //(color[mid] == 2)
        {
            swap(color[mid], color[end]);
            end--;
        }
    }

    for (int i = 0; i < n; i++)
        cout << color[i] << " ";
}
int main()
{
    // solution1();
    // solution2();
    return 0;
}