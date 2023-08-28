#include <iostream>
#include <list>
#include <algorithm>
/*
 * list容器
 * 1. 构造函数
 * 2. 赋值和交换
 * 3. 大小操作
 * 4. 插入和删除
 * 5. 数据存取
 * 6. 反转和排序
 * 7. 排序
 */
using namespace std;
void printList(const list<int>&L) {
    for (list<int>::const_iterator it=L.begin();it!=L.end();it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test01() {
    list<int>L1; //默认构造
    //尾插
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);
    // 区间构造
    list<int>L2(L1.begin(),L1.end());
    printList(L2);
    list<int>L3(10,100);
    printList(L3);
    list<int>L4(L3);
    printList(L4);
}
void test02() {
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);//10 20 30 40

    // 赋值
    list<int>L2;
    L2 = L1;
    printList(L2);//10 20 30 40
    list<int>L3;
    L3.assign(L2.begin(),L2.end());
    printList(L3);//10 20 30 40
    list<int>L4;
    L4.assign(10,100);
    printList(L4);//100 100 100 100 100 100 100 100 100 100
    // 交换
    L4.swap(L2);
    cout << "交换后:" << endl;
    printList(L2);//100 100 100 100 100 100 100 100 100 100
    printList(L4);//10 20 30 40
}
void test03() {
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);//10 20 30 40

    if (empty(L1)) {
        cout << "L1为空" << endl;
    } else {
        cout << "L1不为空" << endl;
        cout << "L1的元素个数：" << size(L1) << endl;
    }

    L1.resize(6,1);
    L1.resize(8);
    printList(L1);//10 20 30 40 1 1 0 0
    L1.resize(3);
    printList(L1);//10 20 30
}
void test04() {
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    // 头插
    L1.push_front(40);
    L1.push_front(50);
    L1.push_front(60);
    printList(L1);//60 50 40 10 20 30
    // 删除
    L1.pop_back();
    printList(L1);//60 50 40 10 20
    L1.pop_front();
    printList(L1);//50 40 10 20
    //插入  提供迭代器
    list<int>::iterator it = L1.begin();
    L1.insert(++it,100);
    printList(L1);//50 100 40 10 20
    //删除
    it = L1.begin();
    L1.erase(++it);
    printList(L1);//50 40 10 20
    //移除
    L1.remove(10);
    printList(L1);//50 40 20
}
void test05() {
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    cout << "第一个元素：" << L1.front() << endl;//10
    cout << "最后一个元素：" << L1.back() << endl;//30
}
/// 从大到小排序
bool myCompare(int v1,int v2) {
    // 降序 让第一个数>第二个数
    return v1>v2;
}
void test06() {
    list<int>L1;
    L1.push_back(10);
    L1.push_back(30);
    L1.push_back(20);
    L1.push_back(50);
    L1.push_back(40);
    printList(L1);//10 30 20 50 40
    //反转
    L1.reverse();
    printList(L1);//40 50 20 30 10
    //排序  默认从小到大 所有不支持随机访问迭代器，不支持标准算法sort(begin,end)
    L1.sort();
    printList(L1);//10 20 30 40 50
    L1.sort(myCompare);//降序
    printList(L1);//50 40 30 20 10
}
/// 案例：对于自定义数据类型进行排序，Person中有姓名、年龄、身高
///     按照年龄进行升序，如果年龄相同按照身高进行降序
class Person {
public:
    Person(string name,int age,int height) {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }

    string m_Name;
    int m_Age;
    int m_Height;
};
void printPeoson(list<Person>&L) {
    for (list<Person>::iterator it=L.begin();it!=L.end();it++) {
        cout << "姓名：" << (*it).m_Name << " 年龄：" << it->m_Age << " 身高:" << it->m_Height << endl;
    }
}
/// 指定排序规则
bool comparePerson(Person &p1,Person &p2) {
    // 按照年龄升序
    if (p1.m_Age == p2.m_Age) {
        // 年龄相同 按身高降序
        return p1.m_Height > p2.m_Height;
    } else {
        return p1.m_Age < p2.m_Age;
    }
}
void test07() {
    list<Person>L;// 创建容器
    Person p1("刘备",35,175);
    Person p2("曹操",45,180);
    Person p3("孙权",40,170);
    Person p4("赵云",25,190);
    Person p5("张飞",35,160);
    Person p6("关羽",35,200);

    //插入数据
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);
    printPeoson(L);
    //排序
    cout << "---------------------" << endl;
    cout << "排序后:" << endl;
    L.sort(comparePerson);
    printPeoson(L);
}
int main() {
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
//    test06();
    test07();
}