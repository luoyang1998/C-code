#include <iostream>
/* 静态成员变量
 * 1.所有对象共享同一份数据
 * 2.编译阶段就分配内存
 * 3.类内声明，类外初始化操作*/

/* 静态成员函数
 * 1.所有对象共享同一个函数
 * 2.静态成员函数只能访问静态成员变量 */
using namespace std;
class Person
{
public:
    static int m_A;
    int m_C; // 非静态成员

    // 静态成员变量也有访问权限
private:
    static int m_B;

public:
    // 静态成员函数
    static void func()
    {
        m_A = 100;
        //m_C = 200; 静态函数 不可以访问 非静态成员变量 非共享且无法区分哪个对象的属性
        cout << "static void func 调用" << endl;
    }

    // 静态成员函数是有访问权限的
private:
    static void func2()
    {
        cout << "static void func2 调用" << endl;
    }
};

// 类外初始化
int Person::m_A = 0;
int Person::m_B = 200;

void test01()
{
    Person p;
    cout << p.m_A << endl;
    Person p2;
    p2.m_A = 200;
    cout << p.m_A << endl;
}
void test02()
{
    // 静态成员变量 不属于某个对象，所有对象都共享同一份数据
    // 静态成员变量有两种访问方式
    // 1. 通过对象进行访问
    Person p;
    cout << p.m_A << endl;
    // 2. 通过类名进行访问
    cout << Person::m_A << endl;
//    cout << Person::m_B << endl; 类外访问不到私有成员
}
void test03()
{
    // 1. 通过对象进行访问
    Person p;
    p.func();
    // 2. 通过类名进行访问
    Person::func();
    //Person::func2(); 类外访问不到私有静态成员函数
}
int main()
{
//    test01();
    test02();
    test03();
}