#include <iostream>

using namespace std;
const int* f1(const int* ,int n); // 变量名可以省略
const int* f2(const int [],int n);
const int* f3(const int [],int n);
int main()
{
    int a[3] = {1,2,3};
    /* 声明指向函数的指针*/
    cout << "声明指向函数的指针：" << endl;
    const int* (*p)(const int* ,int n) = f1;
    cout << "数为：" << *(*p)(a,3) << "地址为：" << (*p)(a,3) << endl;
    // 自动变量类型,只能用于单值的使用
    auto p2 = f2;
    cout << "数为：" << *p2(a,3) << "地址为：" << p2(a,3) << endl;
    cout << "使用指向函数的指针数组：" << endl;
    const int* (*pa[3])(const int [],int n) = {f1,f2,f3};
    for (int i = 0; i < 3; ++i) {
        cout << "数为：" << *pa[i](a,3) << "地址为：" << pa[i](a,3) << endl;
    }

    cout << "使用指向函数指针的指针：" << endl;
    auto pb = pa;
    for (int i = 0; i < 3; ++i) {
        cout << "数为：" << *pb[i](a,3) << "地址为：" << pb[i](a,3) << endl;
    }

    cout << "使用指向数组的指针 auto：" << endl;
    auto pc = &pa;
    for (int i = 0; i < 3; ++i) {
        cout << "数为：" << *(*pc)[i](a,3) << "地址为：" << (*pc)[i](a,3) << endl;
    }

    cout << "使用指向数组的指针 不用auto：" << endl;
    const int* (*(*pd)[3])(const int[],int n) = &pa;
    for (int i = 0; i < 3; ++i) {
        cout << "数为：" << *(*pd)[i](a,3) << "地址为：" << (*pd)[i](a,3) << endl;
    }
}
const int* f1(const int* ar,int n)
{
    return ar;
}
const int* f2(const int ar[],int n)
{
    return ar+1;
}
const int* f3(const int ar[],int n)
{
    return ar+2;
}