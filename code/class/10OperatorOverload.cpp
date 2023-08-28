#include <iostream>
#include <string>
/* 运算符重载
 * 1. 加号运算符重载 1)成员运算重载 2)全局函数重载
 * 2. 左移运算符重载 1)全局函数重载 不会利用成员函数重载 p.operator<<(cout) 无法cout在左侧
 * 3. 递增运算符重载 自定义整型
 * 4. 赋值运算符重载
 * 5. 关系运算符重载 1) = 2) !=
 * 6. 函数调用运算符重载 1)打印 2)加法*/
using namespace std;

class Person {
public:
    Person() {
    }

    Person(int age) {
        m_Age = new int(age);
    }

    Person(string name, int age) {
        m_Name = name;
        m_age = age;
    }

    ~Person() {
        if (m_Age != NULL) {
            delete m_Age;
        }
    }

    // 重载赋值运算符
    Person &operator=(Person &p) {
        // 编译器提供浅拷贝
        // 先判断是否有属性在堆区 如果有先释放 再深拷贝
        if (m_Age != NULL) {
            delete m_Age;
            m_Age = NULL;
        }
        // 深拷贝
        m_Age = new int(*p.m_Age);
        return *this;
    }

    // 重载==
    bool operator==(Person &p) {
        if (this->m_Name == p.m_Name && this->m_age == p.m_age) {
            return true;
        }
        return false;
    }
    bool operator!=(Person &p) {
        if (this->m_Name != p.m_Name || this->m_age != p.m_age) {
            return false;
        }
        return true;
    }
    // 成员函数重载+号
//    Person operator+(Person &p) {
//        Person temp;
//        temp.m_A = this->m_A + p.m_A;
//        temp.m_B = this->m_B + p.m_B;
//        return temp;
//    }

    int m_A;
    int m_B;

    int *m_Age;

    string m_Name;
    int m_age;

};

// 自定义整型
class MyInteger {
    friend ostream &operator<<(ostream &cout, MyInteger myint);

public:
    MyInteger() {
        m_Num = 0;
    }

    // 重载前置++运算符 返回引用是为了一直对一个数进行操作
    MyInteger &operator++() {
        m_Num++;
        return *this;
    }

    // 重载后置++运算符 int表示占位参数，可以用于区分前置后置递增函数 temp为临时变量 不可返回引用
    MyInteger operator++(int) {
        // 先返回结果
        MyInteger temp = *this;
        // 再递增
        m_Num++;
        return temp;
    }

private:
    int m_Num;
};

// 打印输出类
class MyPrint
{
public:
    // 重载函数调用运算符
    void operator()(string text)
    {
        cout << text << endl;
    }
};
// 仿函数灵活，没有固定写法
// 加法类
class MyAdd
{
public:
    int operator()(int a,int b)
    {
        int c = a + b;
        return c;
    }
};

// 全局函数重载+
Person operator+(Person &p1, Person &p2) {
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}

// 也可函数重载
Person operator+(Person &p1, int num) {
    Person temp;
    temp.m_A = p1.m_A + num;
    temp.m_B = p1.m_B + num;
    return temp;
}

// 全局函数重载<<
ostream &operator<<(ostream &cout, Person &p) // ostream输出流
{
    cout << p.m_A << " " << p.m_B;
    return cout; // cout是一个输出流对像，返回输出流时，可以继续在同一行使用<<返回其他字符
}

ostream &operator<<(ostream &cout, MyInteger myint) // ostream输出流
{
    cout << myint.m_Num;
    return cout; // cout是一个输出流对像，返回输出流时，可以继续在同一行使用<<返回其他字符
}


void test01() {
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;
    Person p2;
    p2.m_A = 10;
    p2.m_B = 10;
//    Person p3 = operator+(p1,p2); 本质调用 可正常运行
    Person p3 = p1 + p2;
    cout << p3.m_A << " " << p3.m_B << endl;

    Person p4 = p1 + 20; // 函数重载
    cout << p4.m_A << " " << p4.m_B << endl;
}

void test02() {
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;

    cout << p1 << endl;
}

void test03() {
    MyInteger myint;
    cout << myint << endl;
    cout << ++myint << endl;
    cout << myint << endl;

    MyInteger myint2;
    cout << myint2++ << endl;
    cout << myint2 << endl;
}

void test04() {
    Person p1(18);
    cout << "p1的年龄：" << *p1.m_Age << endl;
    Person p2(20);
    p2 = p1; // 赋值操作 存在析构时 造成new堆区重复释放 利用深拷贝解决
    cout << "p2的年龄：" << *p2.m_Age << endl;
    Person p3(30);

    p3 = p2 = p1;
    cout << "p1的年龄：" << *p1.m_Age << endl;
    cout << "p2的年龄：" << *p2.m_Age << endl;
    cout << "p3的年龄：" << *p3.m_Age << endl;
}

void test05() {
    Person p1("Tom", 18);
    Person p2("Tom", 18);
    if (p1 == p2) {
        cout << "p1与p2为同一人" << endl;
    } else {
        cout << "p1与p2不为同一人" << endl;
    }
    if (p1 != p2) {
        cout << "p1与p2为同一人" << endl;
    } else {
        cout << "p1与p2不为同一人" << endl;
    }
}

void test06()
{
    MyPrint myPrint;
    myPrint("Hello World!");
    MyAdd myAdd;
    cout << myAdd(1,2) << endl;
    cout << MyAdd()(1,2) << endl; // 匿名函数对象 调用完立即释放
}

int main() {
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
    test06();
}
