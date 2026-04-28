#include <vector>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int fast = 0;
    int slow = 0;
    while (fast < nums.size())
    {
        if (nums[fast] != nums[slow])
        {
            slow++;
            nums[slow] = nums[fast];
        }
        fast++;
    }
    return slow + 1;
}

struct Listnode
{
    int val;
    Listnode *next;
    Listnode(int x) : val(x), next(nullptr) {}
};

Listnode *mergeTwoList(Listnode *L1, Listnode *L2)
{
    if (L1 == nullptr && L2 == nullptr)
        return nullptr;
    Listnode *dummy = new Listnode(0);
    Listnode *p = dummy, *p1 = L1, *p2 = L2;
    while (p1 != nullptr && p2 != nullptr)
    {
        if (L1->val < L2->val)
        {
            p->next = p1;
            p1 = p1->next;
            p = p->next;
        }
        else
        {

            p->next = p2;
            p2 = p2->next;
            p = p->next;
        }
    }
    if (p1 == nullptr)
        p->next = p2;
    if (p2 == nullptr)
        p->next = p1;
    return dummy->next;
}

Listnode *returnRearNnode(Listnode *L, int n)
{
    Listnode dummy(0);
    dummy.next = L;
    Listnode *fast = &dummy, *slow = &dummy;
    for (int i = 0; i <= n; i++) // 注意这个题先走n+1步会更优
    {
        fast = fast->next;
        if (fast == nullptr)
            return nullptr;
    }
    while (fast != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Listnode *del = slow->next;
    slow->next = del->next;
    delete del;
    return dummy.next;
}

long long subsetSum(vector<int> nums)
{
    int n = nums.size();
    long long res = 0;
    for (int x : nums)
        res += x * pow(2, n - 1);
    return res;
}

int countCompetitor()
{
    int n;
    cin >> n;
    vector<vector<int>> score(n, vector<int>(4));
    for (int i = 0; i < n; i++)
    {
        cin >> score[i][0] >> score[i][1] >> score[i][2];
        score[i][3] = score[i][0] + score[i][1] + score[i][2];
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            bool is_competitor = abs(score[i][0] - score[j][0]) <= 5 &&
                                 abs(score[i][1] - score[j][1]) <= 5 &&
                                 abs(score[i][2] - score[j][2]) <= 5 &&
                                 abs(score[i][3] - score[j][3]) <= 10;
            if (is_competitor)
                res++;
        }
    return res;
}

void seaport()
{
    int n;
    cin >> n;

    queue<pair<int, vector<int>>> port;
    map<int, int> nations;

    for (int i = 0; i < n; i++)
    {
        pair<int, vector<int>> ship;
        int arrive_time, passager_num;
        cin >> arrive_time >> passager_num;

        ship.first = arrive_time;
        for (int i = 0; i < passager_num; i++)
        {
            int nation;
            cin >> nation;
            ship.second.push_back(nation);
            nations[nation]++;
        }
        port.push(ship);

        // 删除
        while (!port.empty() && arrive_time - 86400 >= port.front().first)
        {
            for (int nation : port.front().second)
            {
                if (nations[nation] == 1)
                    nations.erase(nation);
                else
                    nations[nation]--;
            }
            port.pop();
        }
        cout << nations.size() << "\n";
    }
    return;
}

void Joseph()
{
    int n, m;
    cin >> n >> m;
    vector<int> q;
    for (int i = 1; i <= n; i++)
        q.push_back(i);

    int index = 0;
    while (!q.empty())
    {
        int del;
        index += m - 1;
        del = q[index % q.size()];
        q.erase(q.begin() + (index % q.size()));
        cout << del << " ";
    }
    return;
}

void parenthesis_match()
{
    string input;
    cin >> input;
    stack<char> stk;
    for (char c : input)
    {
        if (c == '(')
            stk.push(c);
        else
        {
            if (!stk.empty() && stk.top() == '(')
                stk.pop();
            else
                stk.push(c);
        }
    }
    if (stk.empty())
        cout << "YES";
    else
        cout << "NO";
}

void midfix_to_postfix()
{
    string input;
    cin >> input;
    stack<char> opstk;
    for (int i = 0; i < input.size(); i++)
    {
        char c = input[i];
        if (isdigit(c))
        {
            string curnum;
            curnum += c;
            while (i + 1 < input.size() && isdigit(input[i + 1]))
            {
                i++;
                curnum += input[i];
            }
            cout << curnum << " ";
        }
        else if (c == '(')
        {
            opstk.push(c);
        }
        else if (c == ')')
        {
            while (!opstk.empty() && opstk.top() != '(')
            {
                cout << opstk.top() << " ";
                opstk.pop();
            }
            if (!opstk.empty() && opstk.top() == '(')
                opstk.pop();
        }
        else if (c == '+' || c == '-')
        {
            while (!opstk.empty() && opstk.top() != '(')
            {
                cout << opstk.top() << " ";
                opstk.pop();
            }
            opstk.push(c);
        }
        else if (c == '*' || c == '/')
        {

            while (!opstk.empty() && opstk.top() != '(' && (opstk.top() == '*' || opstk.top() == '/'))
            {
                cout << opstk.top() << " ";
                opstk.pop();
            }
            opstk.push(c);
        }
    }
    while (!opstk.empty())
    {
        cout << opstk.top() << " ";
        opstk.pop();
    }
    return;
}

struct mystack
{
    queue<int> q;
    queue<int> temp;

    void push(int x)
    {
        temp.push(x);
        while (!q.empty())
        {
            temp.push(q.front());
            q.pop();
        }
        swap(q, temp);
        return;
    }
    int pop()
    {
        if (q.empty())
        {
            cout << "Stack is empty" << "\n";
            return -1;
        }
        int res = q.front();
        q.pop();
        return res;
    }
    int top()
    {
        if (q.empty())
        {
            cout << "Stack is empty" << "\n";
            return -1;
        }
        return q.front();
    }
    void empty()
    {
        if (q.empty())
            cout << "true" << "\n";
        else
            cout << "false" << "\n";
    }
    void print()
    {
        if (q.empty())
        {
            cout << "Stack is empty" << "\n";
            return;
        }
        queue<int> tmp = q;
        while (!tmp.empty())
        {
            int del = tmp.front();
            tmp.pop();
            cout << del << " ";
        }
        cout << "\n";
    }
    void exit()
    {
        return;
    }
};

void postfix_cal()
{
    string token;
    stack<string> stk;
    while (cin >> token)
    {
        if (isdigit(token[0])) // 注意string判整数的方法
        {
            stk.push(token);
        }
        else
        {
            int n2 = stoi(stk.top());
            stk.pop();
            int n1 = stoi(stk.top());
            stk.pop();
            if (token == "+")
            {
                stk.push(to_string(n1 + n2));
            }

            if (token == "-")
            {
                stk.push(to_string(n1 - n2));
            }

            if (token == "*")
            {
                stk.push(to_string(n1 * n2));
            }

            if (token == "/")
            {
                stk.push(to_string(n1 / n2));
            }
        }
    }
    cout << stk.top();
}

void decode()
{
    string input;
    cin >> input;

    stack<int> stkint;
    stack<string> stkstr;
    string curstr = "";
    int curint = 0;

    for (char c : input)
    {
        if (isdigit(c))
        {
            curint = curint * 10 + c - '0';
        }
        else if (c == '[')
        {
            stkint.push(curint);
            stkstr.push(curstr);
            curint = 0;
            curstr = "";
        }
        else if (c == ']')
        {
            string prestr = stkstr.top();
            stkstr.pop();
            int times = stkint.top();
            stkint.pop();
            string temp;
            for (int i = 0; i < times; i++)
            {
                temp += curstr;
            }
            curstr = prestr + temp;
        }
        else
        {
            curstr += c;
        }
    }
    cout << curstr;
}

void color_sort(vector<int> colors)
{
    int left = 0, right = colors.size() - 1, mid = -1;
    while (mid < right)
    {
        mid++;
        if (colors[mid] == 0)
            swap(colors[mid], colors[left]);
        else if (colors[mid] == 2)
            swap(colors[mid], colors[right]);
        while (mid <= right && colors[right] == 2)
            right--;
        while (mid >= left && colors[left] == 0)
            left++;
    }
    for (int x : colors)
        cout << x << " ";
}

struct node
{
    string addr;
    string val;
    string naddr;
};

void list_rearrange()
{
    map<string, node> mp;
    vector<node> vec;
    string curaddr;
    int n;
    cin >> curaddr >> n;
    for (int i = 0; i < n; i++)
    {
        node temp;
        cin >> temp.addr >> temp.val >> temp.naddr;
        mp[temp.addr] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        vec.push_back(mp[curaddr]);
        curaddr = mp[curaddr].naddr;
    }
    int left = 0, right = n - 1;
    while (left <= right)
    {
        if (left == right)
        {
            cout << vec[left].addr << vec[left].val << vec[left].naddr << "\n";
            break;
        }
        else
        {
            cout << vec[left].addr << vec[left].val << vec[left].naddr << "\n";
            left++;
            cout << vec[right].addr << vec[right].val << vec[right].naddr << "\n";
            right--;
        }
    }
}

Listnode *sumtwo(Listnode *l1, Listnode *l2)
{
    if (l1 == nullptr && l2 == nullptr)
        return nullptr;

    Listnode *p1 = l1, *p2 = l2;
    Listnode *dummy = new Listnode(0);
    Listnode *p3 = dummy;
    int carry = 0;
    while (p1 != nullptr || p2 != nullptr)
    {
        int n1 = p1 == nullptr ? 0 : p1->val;
        int n2 = p2 == nullptr ? 0 : p2->val;
        int sum = n1 + n2 + carry;
        carry = sum / 10;
        Listnode *temp = new Listnode(sum % 10);
        p3->next = temp;
        p3 = p3->next;
        if (p1 != nullptr)
            p1 = p1->next;
        if (p2 != nullptr)
            p2 = p2->next;
    }
    if (carry == 1)
    {
        Listnode *temp = new Listnode(1);
        p3->next = temp;
    }
    return dummy->next;
}

// int main()
// {
//     // color_sort({1,0,2,0,1,2});
//     return 0;
// }
