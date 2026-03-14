/*
矩阵对角线 是一条从矩阵最上面行或者最左侧列中的某个元素开始的对角线，
沿右下方向一直到矩阵末尾的元素。
例如，矩阵 mat 有 6 行 3 列，
从 mat[2][0] 开始的 矩阵对角线
将会经过 mat[2][0]、mat[3][1] 和 mat[4][2] 。

给你一个 m * n 的整数矩阵 mat ，
请你将同一条 矩阵对角线 上的元素按升序排序后，返回排好序的矩阵。
*/

// 复杂情形的模拟
//本题需要注意的是对角线的数学特征

#include <vector>
#include <map>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int column = mat[0].size();
        int row = mat.size();
        // 按照r-c=row-1到-(column-1)进行对角线遍历存储再放出
        map<int, priority_queue<int, vector<int>, greater<int>>> data;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                data[i - j].push(mat[i][j]);
            }
        }
        vector<vector<int>> ans=mat;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                ans[i][j]=data[i-j].top();
                data[i-j].pop();
            }
        }

        return ans;
    }
};