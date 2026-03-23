// 输入一个整数，打印全排列

#include <vector>
#include <iostream>

using namespace std;

int n;
vector<int> permutation;
bool isvalid[100];
void dfs(int k) // 表示排到了第k个数字
{

    if (k == n + 1)
    {
        for (int x : permutation)
            cout << x;
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (isvalid[i])
        {
            permutation.push_back(i);
            isvalid[i] = 0;
            dfs(k + 1);
            permutation.pop_back();
            isvalid[i] = 1;
        }
    }
}

int main()
{

    cin >> n;
    for (int i = 1; i <=n; i++)//最后是这里出了问题，要确认到底是在用哪些下标
        isvalid[i] = true;
    dfs(1);
    return 0;
}

// #include <vector>
// #include <iostream>

// using namespace std;

// int n;
// vector<int> permutation;
// bool isvalid[100];

// void dfs(int k) // 表示当前在填第 k 个位置
// {
//     if (k == n + 1)
//     {
//         for (int x : permutation)
//             cout << x;
//         cout << "\n";
//         return;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         if (isvalid[i])
//         {
//             permutation.push_back(i);
//             isvalid[i] = false;

//             dfs(k + 1);

//             permutation.pop_back();
//             isvalid[i] = true;
//         }
//     }
// }

// int main()
// {
//     cin >> n;

//     for (int i = 1; i <= n; i++)
//         isvalid[i] = true;

//     dfs(1);
//     return 0;
// }