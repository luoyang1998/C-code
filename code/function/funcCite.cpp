#include <iostream>

using namespace std;
template <typename Type1>
void swap_C(Type1& a,Type1& b);
void swap_A(int* a,int* b);
void swap_B(int& a,int& b);
int& CDE(int&c);
int main()
{
    int a = 200;
    int b = 500;

    cout << "ָ�뷨��"  << endl;
    swap_A(&a,&b);
    cout << "a:" << a << "  b:" << b << endl;

    cout << "���÷���"  << endl;
    swap_B(a, b);
    cout << "a:" << a << "  b:" << b << endl;

    int c{20},d{50},e{10};
    cout << CDE(c) <<endl;
    /*��Ϊ��ֵ*/
    CDE(b) = 50;
    cout << b << endl;
    /*��Ϊ��ֵ*/
    int f = CDE(e);
    cout << f << endl;

    swap_C(a,b);
    cout << "a:" << a << "  b:" << b << endl;
}
// ��������
template <typename Type1>
void swap_C(Type1& a,Type1& b)
{
    Type1 temp{};
    temp = a;
    a = b;
    b = temp;
}
void swap_A(int* a,int* b)
{
    int temp{};
    temp = *a;
    *a = *b;
    *b = temp;
}
void swap_B(int& a,int& b)
{
    int temp{};
    temp = a;
    a = b;
    b = temp;
}
int& CDE(int&c)
{
    int e{2};
    c = c * e;
    return c;
}