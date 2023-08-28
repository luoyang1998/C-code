#include <iostream>
using namespace std;
unsigned int c_in_str(const char* str,char ch);
char* buildstr(char c,int n);
char* fill_str(char* str,unsigned int x);

int main()
{
//    char a[15] = "hehehehehelaa";
//    const char* p = "asdfasdfad";
//    unsigned int aaa = c_in_str(a,'h');
//    cout << aaa;

//    int integer; // 整数
//    char ch;
//    cout << "请输入字符：";
//    cin >> ch;
//    cout << "请输入整数：";
//    cin >> integer;
//    char* p = buildstr(ch,integer);
//    cout << p;
//    delete[] p; // 使用完 清空动态内存

    unsigned int x{};
    cout << "请输入整数：";
    while (!(cin>>x)) {
        cin.clear();
        while (cin.get()  != '\n')
            continue;
        cout << "请输入整数：";
        break;
    }
    char* p = new char[x+1];
    p = fill_str(p,x);
    cout << p;\
    delete[] p;
}

// 判断字符串中有几个指定字母
unsigned int c_in_str(const char* str,char ch)
{
    unsigned int count = 0;
    // 遇到'\0'结束
    while (*str){
        if (*str == ch){
            count++;
        }
        str++;
    }
    return count;
}

// 创建一个字符串
char* buildstr(char c,int n) // 返回指针
{
    char* pstr = new char[n+1]; //包含\0
    pstr[n] = '\0';
    while (n-- > 0){
        pstr[n] = c;
    }
    return pstr;
}

// 输入字符串长度，并复制输出
char* fill_str(char* str,unsigned int x)
{
    cout << "请输入字符串：";
    for (int i = 0; i < x; ++i) {
        cin >> *str;
        str++;
    }
    *str = '\0';
    return str-x;
}