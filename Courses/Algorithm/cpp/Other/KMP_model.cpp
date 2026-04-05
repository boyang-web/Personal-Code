/*
vector<int> build_pi(const string& p)
int kmp_find(const string& s, const string& p)
*/
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> build_pi(const string &p)
{
    vector<int> pi(p.size(), 0);
    for (int i = 1; i < p.size(); i++)
    {
        int j = pi[i - 1];
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
int kmp_find(const string &s, const string &p)
{
    if (p.empty())
        return 0;
    vector<int> pi = build_pi(p);
    int i = 0, j = 0;
    while (i < s.size())
    {
        while (j > 0 && s[i] != p[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == p[j])
        {
            j++;
        }
        if (j == p.size())
            return i - j + 1;
        i++;
    }
    return -1;
}

int main()
{
    return 0;
}