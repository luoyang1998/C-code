#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
/*
 * 1. vector存放内置数据类型
 * 2. vector存放自定义数据类型
 * 3. 容器嵌套容器
 */
using namespace std;

void myPrint(int val) {
    cout << val << endl;
}
void test01() {
    // 创建vector容器，数组
    vector<int> v;
    // 插入数据 尾插
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    // 通过迭代器访问容器中数据
    vector<int>::iterator itBegin = v.begin(); // 起始迭代器，指向容器第一个元素
    vector<int>::iterator itEnd = v.end(); // 结束迭代器，指向容器最后一个元素的下一个位置

    // 第一种遍历方式
    while (itBegin != itEnd) {
        cout << *itBegin << endl;
        itBegin++;
    }
    // 第二种遍历方式
    for (vector<int>::iterator it = v.begin();it!=v.end();it++) {
        cout << *it << endl;
    }
    // 第三种遍历方式 利用STL提供遍历算法
    for_each(v.begin(),v.end(), myPrint);
}

/// 2. 自定义数据类型
class Person {
public:
    Person(string name,int age) {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};
void test02() {
    vector<Person> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);

    // 向容器种添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    // 遍历数据
    for (vector<Person>::iterator it=v.begin();it!=v.end();it++) {
        cout << "姓名：" << (*it).m_Name << "  年龄：" << (*it).m_Age << endl;
    }
}
// 存放自定义类型指针
void test03() {
    vector<Person*> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);

    // 向容器种添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    // 遍历数据
    for (vector<Person*>::iterator it=v.begin();it!=v.end();it++) {
        cout << "姓名：" << (*it)->m_Name << "  年龄：" << (*it)->m_Age << endl;
    }
}
/// 嵌套容器
void test04() {
    vector<vector<int>> v;
    // 创建小容器
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>v4;
    // 小容器添加数据
    for (int i = 0; i < 4; ++i) {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }
    // 将小容器插入大容器
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    // 大容器遍历
    for (vector<vector<int>>::iterator it=v.begin();it!=v.end();it++) {
        // (*it) ---- 是一个容器
        for (vector<int>::iterator vit=(*it).begin();vit!=(*it).end();vit++) {
            cout << *vit << " ";
        }
        cout << endl;
    }
}
int main() {
//    test01();
//    test02();
//    test03();
    test04();
}
