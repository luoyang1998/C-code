#include <iostream>
/* 初始化列表 赋初值 */
using namespace std;
class Person
{
public:
    // 传统初始化操作
//    Person(int a,int b,int c)
//    {
//        m_A = a;
//        m_B = b;
//        m_C = c;
//    }

    // 初始化列表赋初值,不方便进行修改传入值
//    Person():m_A(10),m_B(20),m_C(30)
//    {
//        // 可为空
//    }
    Person(int a,int b,int c):m_A(a),m_B(b),m_C(c)
    {
        // 可为空
    }

    int m_A;
    int m_B;
    int m_C;
};
void test()
{
    Person p(10,20,30);
//    Person p;
    cout << p.m_A << " " <<  p.m_B << " " << p.m_C << endl;
}
int main()
{
    test();

}
