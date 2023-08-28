#include <iostream>

using namespace std;

/* 浅拷贝与深拷贝
 * 1. 编译器提供的拷贝构造函数，会提供浅拷贝操作*/

class Person
{
public:
    // 构造函数
    Person()
    {
        cout << "Person 无参构造函数调用" << endl;
    }
    Person(int age, int height)    // 有参构造
    {
        m_age = age;
        m_height = new int(height);
        cout << "Person 有参构造函数调用" << endl;
    }
    Person(const Person &p)// 拷贝构造函数
    {
        m_age = p.m_age;
        // m_height = p.m_height; // 浅拷贝
        // 深拷贝
        m_height = new int(*p.m_height);
        cout << "Person 拷贝构造函数调用" << endl;
    }
    // 析构函数
    ~Person()
    {
        // 析构代码，将对去开辟数据做释放操作
        if (m_height != NULL){
            delete m_height;
            m_height = NULL;
        }
        cout << "Person 析构函数调用" << endl;
    }

    int m_age;
    int *m_height;
};
// 调用
void test()
{
    Person p1(18,160);
    cout << "年龄为：" << p1.m_age << " 身高为：" << *p1.m_height << endl;
    Person p2(p1);
    cout << "年龄为：" << p2.m_age << " 身高为：" << *p2.m_height << endl;

}


int main()
{
    test();
}
