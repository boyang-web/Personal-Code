#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_pos(string str)
{
    if (str.size() == 1)
        return true;
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (str[i + 1] != str[i] && str[i + 1] != str[i] + 1)
            return false;
    }
    return true;
}

bool is_good(string str, vector<string> &output)
{
    int n = str.size();
    if (n == 1 || n == 2)
    {
        output.push_back(str);
        return true;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        string sub1 = str.substr(0, i);
        string sub2 = str.substr(i, n - i);
        if (is_pos(sub1) && is_pos(sub2))
        {
            output.push_back(str);
            return true;
        }
    }
    return false;
}

int main()
{
    string input;
    cin >> input;
    vector<string> output;
    int cnt = 0;
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 1; i + j <= input.size(); j++)
        {
            string temp = input.substr(i, j);
            if (is_good(temp, output))
                cnt++;
            else
                break;
        }
    }
    cout << input << "有" << cnt << "个好串: ";
    for (auto x : output)
        cout << x << " ";

    return 0;
}