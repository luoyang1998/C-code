#include <iostream>
#include <string>
/* 多继承
 * 1. 虚函数
 * 2. 虚析构*/
using namespace std;

class Base1 {
public:
    Base1() {
        m_A = 100;
    }

    int m_A;
};

class Base2 {
public:
    Base2() {
        m_A = 200;
    }

    int m_A;
};

// 子类 继承Base1 和 Base2
class Son : public Base1, public Base2 {
public:
    Son()
    {
        m_C = 300;
        m_D = 400;
    }
    int m_C;
    int m_D;
};

class Animal{
public:
    Animal()
    {
        cout << "Animal构造函数调用" << endl;
    }
    // 虚函数
    virtual void speak(){
        cout << "动物在说话" << endl;
    }
//    virtual ~Animal() // 改为虚析构 会调用子类析构
//    {
//        cout << "Animal析构函数调用" << endl;
//    }
    // 纯虚析构 需要有代码具体实现
    virtual ~Animal() = 0;
};
// 纯虚析构 需要声明 也需要实现 有纯虚析构 属于抽象类
Animal::~Animal(){
    cout << "Animal纯析构函数调用" << endl;
};
class Cat:public Animal{
public:
    Cat(string name)
    {
        cout << "Cat构造函数调用" << endl;
        m_Name = new string(name);
    }
    virtual void speak(){  // 子类重写父类虚函数virtual void speak()
        cout << *m_Name << "小猫在说话" << endl;
    }
    ~Cat()
    {
        if(m_Name != NULL){
            cout << "Cat析构函数调用" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }
    string *m_Name;
};
// C++中允许父子之间的类型转换，不需要做强制类型转换
// 动物在说话  地址早绑定  在编译阶段确定函数地址
// speak前加virtual变成虚函数  变成动态多态进行晚绑定  实现小猫说话
void doSpeak(Animal &animal){ // Animal & animal = cat 引用执行子类对象
    animal.speak();
}
void test01()
{
    Son s;
    cout << "size of s = " << sizeof(s) << endl;
    // 当父类出现童名成员 需要加作用域区分
    cout << "m_A = " << s.Base1::m_A << endl; // 200
    cout << "m_A = " << s.Base2::m_A << endl; // 100
}
//void test02(){
//    Cat cat;
//    doSpeak(cat);
//}
void test03(){
    Animal * animal = new Cat("Tom");
    animal->speak();
    // 父类指针在析构时候，不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄露
    delete animal;
}
int main()
{
//    test01();
//    test02();
    test03();
}
