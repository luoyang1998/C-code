#include <iostream>
/* this指针
 * 1. 解决名称冲突
 * 2. 返回对象本身用的*this */

using namespace std;

class Person
{
public:
    Person(int age)
    {
        this->age = age;
    }
    Person& AddAge(Person p)
    {
        this->age += p.age;
        // this指向p2的指针，而*this指向的就是p2这个本体
        return *this;
    }
    int age;
};
/* 解决名称冲突
 * 1. 不同命名
 * 2. this指针 */
void test01()
{
    Person p1(18);
    cout << "p1的年龄：" << p1.age << endl;
}
// 返回对象本身用的*this
void test02()
{
    Person p1(10);
    Person p2(10);
    p2.AddAge(p1);
    // p2.AddAge(p1).AddAge(p1); 返回为void时不可如此调用
    p2.AddAge(p1).AddAge(p1); //链式变成思想
    cout << "p2的年龄：" << p2.age << endl;
}
int main()
{
//    test01();
    test02();
}