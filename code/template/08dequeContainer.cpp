#include <iostream>
#include <deque>
#include <algorithm>
/*
 * deque容器
 * 1. 构造函数
 * 2. 赋值操作
 * 3. 大小操作
 * 4. 插入和删除
 * 5. 数据存取
 * 6. 排序
 */
using namespace std;
void printDeque(const deque<int>&d) { // 修改为只读迭代器
    for (deque<int>::const_iterator it=d.begin(); it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test01() {
    deque<int>d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int>d2(d1.begin(),d1.end());
    deque<int>d3(10,100);
    deque<int>d4(d3);
}
void test02() {
    deque<int>d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int>d2 = d1;
    printDeque(d2);

    deque<int>d3;
    d3.assign(d1.begin(),d1.end());
    printDeque(d3);

    deque<int>d4;
    d4.assign(10,100);
    printDeque(d4);
}
void test03() {
    deque<int>d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }
    printDeque(d1);

    if (d1.empty()) {
        cout << "d1为空" << endl;
    } else {
        cout << "d1不为空" << endl;
        cout << "d1的大小:" << d1.size() << endl;//10
    }
    // 重新指定大小
    d1.resize(12);
    printDeque(d1);//0 1 2 3 4 5 6 7 8 9 0 0
    d1.resize(15,1);
    printDeque(d1);//0 1 2 3 4 5 6 7 8 9 0 0 1 1 1
    d1.resize(4);
    printDeque(d1);//0 1 2 3
    
}
void test04() {
    deque<int>d1;
    // 尾插
    d1.push_back(10);
    d1.push_back(20);
    // 头插
    d1.push_front(30);
    d1.push_front(40);
    printDeque(d1);//40 30 10 20
    d1.pop_back();
    d1.pop_front();
    printDeque(d1);//30 10

    deque<int>d2;
    d2.push_back(10);
    d2.push_back(20);
    d2.push_front(30);
    d2.push_front(40);
    // insert插入
    d2.insert(d2.begin(),100);
    printDeque(d2);//100 40 30 10 20
    d2.insert(d2.begin(),2,200);
    printDeque(d2);//200 200 100 40 30 10 20
    d2.insert(d2.begin(),d1.begin(),d1.end());
    printDeque(d2);//30 10 200 200 100 40 30 10 20
    //删除
    deque<int>::iterator it = d2.begin();
    it++; // 迭代器第一个位置偏移
    d2.erase(it);
    printDeque(d2);//30 200 200 100 40 30 10 20
    d2.erase(d2.begin(),d2.end());
    printDeque(d2);
    d2.clear();

}
void test05() {
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(30);
    d1.push_front(40);
    for (int i = 0; i < d1.size(); ++i) {
        cout << d1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < d1.size(); ++i) {
        cout << d1.at(i) << " ";
    }
    cout << endl;
    cout << "第一个元素:" << d1.front() << " 最后一个元素：" << d1.back() << endl;
}
void test06() {
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(30);
    d1.push_front(40);// 40 30 10 20
    printDeque(d1);
    // 排序 从小到大
    // 对于支持随机访问的迭代器容器，都可以通过sort进行排序
    sort(d1.begin(),d1.end());
    cout << "排序后：" << endl;
    printDeque(d1);//10 20 30 40
}
int main() {
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
    test06();
}
