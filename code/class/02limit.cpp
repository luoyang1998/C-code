#include <iostream>
#include <string>
using namespace std;
/* 成员属性设置为私有
 * 1. 自己控制属性
 * 2. 对于写可以检测有效性 */

class Person
{
public:
    // 设置姓名
    void setname(string name)
    {
        m_name = name;
    }
    // 读取姓名
    string getname()
    {
        return m_name;
    }
    // 读取年龄 改为可读可写 设置年龄范围 0-100
    int getage()
    {
//        m_age = 0;
        return m_age;
    }
    void setage(int age)
    {
        if (age < 0 | age > 100){
            m_age = 0;
            cout << "年龄输入有误！" << endl;
            return;
        }
        m_age = age;
    }
    // 设置汽车
    void setcar(string car)
    {
        m_car = car;
    }

private:
    string m_name;  // 可读可写
    string m_car;  // 只写
    int m_age;  // 只读

};
int main(){
    Person p1;
    p1.setname("张三");
    cout << "姓名为：" << p1.getname() << endl;
    cout << "年龄为：" << p1.getage() << endl;
    p1.setcar("拖拉机");
    p1.setage(101);
}
