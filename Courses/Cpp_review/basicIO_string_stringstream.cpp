/*
复习字符串解析和字符串操作
复习基本文件读写
*/

/*
字符串流：最小单位是单个字符，包含\n \t ' '之类的
>>是流提取运算符 ，跳过\n \t ' ' 进行读取
*/

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cctype>
#include <fstream>
using namespace std;

// 基本写文件
void test1()
{ // 注意这个目录的写法
    ofstream fout("tempfile/temptext.txt");
    fout << "1 " << "2 " << endl
         << "3" << endl
         << "4 " << "5";
    ifstream fin("tempfile/temptext_w.txt");
    if (!fin) // 读取失败会返回false
    {
        cout << "读取失败，不存在文件" << endl;
        return;
    }
    fin.close(); // 别忘了关闭文件
}
// 基本读文件
void test2()
{
    // 尤其要注意的是两个混合输入易错点
    // 一个fstream用完后光标在最末尾，尽量不复用
    // cin>>后敲的回车可能会被之后的getline读取，要在cin后写cin.ignore();
    ifstream fin1("tempfile/temptext.txt");
    string str;
    while (fin1 >> str)
        cout << str << " ";

    // 按行读取
    ifstream fin2("tempfile/temptext.txt");
    string line;
    while (getline(fin2, line))
        cout << line << "\n";

    fin1.close();
}
// 基本string操作
void test3()
{
    // 子串，查找，插入，删除，替换，大小写/数字字符转换、方便一点的首位获取和尾增删

    string str = "0123456789";
    cout << str.substr(1, 3) << " ";
    cout << str.find("234") << " ";
    // 注意没找到要用string::npos来判定
    if (str.find("135") == string::npos)
        cout << "not found" << " ";
    str.insert(5, "A");
    cout << str << " ";
    // 注意这里要用迭代器
    str.erase(str.begin() + 8);
    // 从2开始把后三个字符替换
    str.replace(2, 3, "BC");
    cout << str << "\n";

    // 需要#include<cctype>
    string charstr = "abcd";
    for (auto &x : charstr)
        x = toupper(x);
    cout << charstr<<endl;
    //to_string()可以转换成字符串
    //stoi可以转换成数字
    string strnum="123";
    cout<<to_string(stoi(strnum)+3)<<endl;
    //push和pop也能用 front 和back亦可
    strnum.push_back('A');
    cout<<strnum.front()<<" "<<strnum.back()<<endl;
    
}


//sstring的用法
void test4()
{
//字符串转流式输出
stringstream ss("1 23 45");
int a,b,c;
ss>>a>>b>>c;

stringstream ss1("1 2 3 4 5");
string x;
while(ss1>>x)
cout<<x;

//cin是流，fin是流 ss也是流
//geline(cin,line," ")就可以按照分隔符把cin流转移到line
//分割token
string line = "apple,banana,orange";
stringstream ss2(line);
string token;

while (getline(ss2, token, ',')) {
    cout << token << '\n';
}

}

int main()
{
    // test1();
    // test2();
    // test3();
    test4();
    return 0;
}
