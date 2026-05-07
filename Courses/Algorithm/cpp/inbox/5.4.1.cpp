// 已知前序后序求可能的中序数
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    string pre, post;
    cin >> pre >> post;
    int cnt = 0;
    for (int i = 1; i < pre.size(); i++)
    {
        for (int j = 1; j < pre.size(); j++)
        {
            string postsub = post.substr(j - 1, 2);
            reverse(postsub.begin(), postsub.end());
            if (pre.substr(i - 1, 2) == postsub)
                cnt++;
        }
    }
    long long ans = pow(2, cnt);
    cout << ans;

    return 0;
}