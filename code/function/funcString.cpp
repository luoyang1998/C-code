#include <iostream>
#include <string>
using namespace std;
void display(const string sa[],int n);
int main()
{
    const unsigned int size = 5;
    string a[size];
    cout << "输入大小：" << endl;
    for (int i = 0; i < size; ++i) {
        cout << i+1 << ":";
        getline(cin,a[i]);
    }
    cout << "输出字符为：" << endl;
    display(a,size);
}
// 定义五个数，并输出
void display(const string sa[],int n)
{
    for (int i = 0; i < n; ++i) {
        cout << i+1 << ":" << sa[i] << endl;
    }
}
