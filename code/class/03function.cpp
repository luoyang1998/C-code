#include <iostream>

using namespace std;

/* 对象的初始化和清理
 * 1. 构造函数进行初始化操作
 * 2. 析构函数进行清理操作 */

/* 构造函数分类 及 三种调用方式 */

/* 拷贝构造函数的三个调用时机
 * 1. 使用一个创建完毕的对象来初始化一个新对象
 * 2. 值传递的方式给函数参数传值
 * 3. 以值方式返回传递对象 */

class Person
{
public:
    // 构造函数
    Person()
    {
        cout << "Person 无参构造函数调用" << endl;
    }
    Person(int age)    // 有参构造
    {
        m_age = age;
        cout << "Person 有参构造函数调用" << endl;
    }
    Person(const Person& p)// 拷贝构造函数
    {
        m_age = p.m_age;
        cout << "Person 拷贝构造函数调用" << endl;
    }
    // 析构函数
    ~Person()
    {
        cout << "Person 析构函数调用" << endl;
    }

    int m_age;
};
// 调用
void test()
{
    // 普通调用
    Person p1; // 在栈上的数据 test执行完毕就会释放

    // 括号法
    // 1.使用一个创建完毕的对象来初始化一个新对象
    Person p2(10);
    Person p3(p2); // 拷贝

    cout << "年龄为：" << p2.m_age << endl;
    cout << "年龄为：" << p3.m_age << endl;

    // 显示法
    Person p4;
    Person p5 = Person(10); // Person(10) 匿名对象 特点：当前执行结束后 系统直接释放
    Person p6 = Person(p5); //拷贝

    // 隐式转换
    Person p7 = 10; // 相当于Person p7 = Person(10);
    Person p8 = p7; // 拷贝
}

// 2. 值传递的方式给函数参数传值
void dowork(Person p)
{

}
void test01()
{
    Person p;
    dowork(p);
}

// 3. 以值方式返回传递对象
Person dowork2()
{
    Person p;
    cout << (int*)&p <<endl;
    return p;
}
void test02()
{
    Person p = dowork2();
    cout << (int*)&p <<endl;
}
int main()
{
//    test(); // 自动调用一次构造函数
//    test01();
    test02();
}
