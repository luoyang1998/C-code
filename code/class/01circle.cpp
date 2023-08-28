#include <iostream>
#include <string>
using namespace std;
/* 设计一个圆类，计算圆的周长
 * 圆周长公式：2*pi*r */
const double pi = 3.14;

// class代表设计一个类,类名
class Circle
{
    // 访问权限
    // 公共权限
public:
    // 属性：半径
    int m_r;
    // 行为：获取周长
    double caculateZC()
    {
        return 2*pi*m_r;
    }
};

/* 创建一个学生类，给学生赋值姓名、学号，输出 */
class student
{
public:
    int num;
    string name;
public:
    void display()
    {
        cout << "学生学号："  << num << endl;
        cout << "学生姓名："  << name << endl;
    }
    void setname(string s_name)
    {
        name = s_name;
    }
    void setnum(int s_num)
    {
        num = s_num;
    }
};
int main() {
    // 通过圆类，创建一个具体的圆（对象）
    Circle c1;
    // 给圆对象 属性进行赋值
    c1.m_r = 10;
    cout << "圆的周长" << c1.caculateZC() << std::endl;

    student s1;
//    s1.name = "张三";
//    s1.num = 123456;
    s1.setname("张三");
    s1.setnum(12);
    s1.display();

}
