#include <iostream>
#include <set>
#include <string>
#include <algorithm>
/*
 * set容器
 * 1. 构造函数 赋值
 * 2. 大小和交换
 * 3. 插入和删除
 * 4. 查找和统计
 * 5. 对组的创建
 * 6. 排序: 存放内置数据类型
 * 7. 排序：存放自定义数据类型
 */
using namespace std;

void printSet(set<int>&s) {
    for (set<int>::iterator it = s.begin(); it!=s.end(); it++)
        cout << *(it) << " ";

    cout << endl;
}
void test01() {
    set<int>s1;
    // 插入数据 只有insert
    s1.insert(10);
    s1.insert(30);
    s1.insert(40);
    s1.insert(20);
    printSet(s1);//10 20 30 40
    // 拷贝构造
    set<int>s2(s1);
    printSet(s2);
    set<int>s3;
    s3 = s2;
    printSet(s3);
}
void test04() {
    // 查找
    set<int>s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    set<int>::iterator pos = s1.find(30);
    if (pos != s1.end()) {
        cout << "找到元素：" << *pos << endl;
    } else {
        cout << "未找到元素" << endl;
    }
    // 统计
    int num = s1.count(30);
    cout << "元素个数：" << num << endl;
}
void test05() {
    // set底层会判断是否插入成功
    set<int>s;
    pair<set<int>::iterator ,bool> ret = s.insert(10);
    if (ret.second) {
        cout << "插入成功" << endl;
    } else {
        cout << "插入失败" << endl;
    }

    // 方式一
    pair<string, int>p("Tom",20);
    cout << "姓名：" << p.first << " 年龄：" << p.second << endl;
    // 方式二
    pair<string ,int>p2 = make_pair("Jerry",2);
    cout << "姓名：" << p2.first << " 年龄：" << p2.second << endl;
}
/// 仿函数
class myCompare {
public:
    bool operator()(int v1,int v2) const {
        return v1>v2;
    }
};
void test06() {
    set<int,myCompare>s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    // 指定排序规则从大到小 创建容器时 修改规则
    for (set<int,myCompare>::iterator it = s.begin(); it!=s.end(); it++) {
        cout << *(it) << " ";
    }
    cout << endl;
}
class Person{
public:
    Person (string name,int age) {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};
class comparePerson {
public:
    bool operator()(const Person& p1,const Person& p2) const {
        // 按照年龄 降序
        return p1.m_Age > p2.m_Age;
    }
};
void test07() {
    // 自定义数据类型 都需要指定排序规则
    set<Person,comparePerson>s;
    Person p1("刘备",35);
    Person p2("曹操",45);
    Person p3("孙权",40);
    Person p4("赵云",25);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    for (set<Person,comparePerson>::iterator it = s.begin(); it!=s.end(); it++) {
        cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << endl;
    }
}
int main() {
//    test01();
//    test04();
//    test05();
//    test06();
    test07();
}