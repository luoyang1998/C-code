#include <iostream>
#include <string>
using namespace std;
/*
 * 类模板----友元类内类外实现
 * 全局函数类内实现 - 直接在类内声明友元即可
 * 全局函数类外实现 - 需要提前让编译器知道全局函数的存在
 *
 * 通过全局函数打印Person
 */

// 提前让编译器知道person类
template<class T1,class T2>
class Person;

// 类外实现
template<class T1,class T2>
void printPerson(Person<T1,T2> p){
    cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
}

template<class T1,class T2>
class Person {
    // 全局函数 类内实现
    friend void showPerson(Person<T1,T2> p)
    {
        cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
    }
    // 全局函数 类外实现
    // 如果是全局函数，是类外实现 需要让编译器先识别
    friend void printPerson<>(Person<T1,T2> p);

public:
    Person(T1 name,T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

private:
    T1 m_Name;
    T2 m_Age;
};

// 1. 全局函数类内实现
void test01() {
    Person<string ,int>p("Jerry",18);
    showPerson(p);
}
// 2. 全局函数类外实现
void test02() {
    Person<string ,int>p("Tom",20);
    printPerson(p);
}
int main(){
//    test01();
    test02();
}


