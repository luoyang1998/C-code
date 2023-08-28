#include <iostream>
#include <map>
#include <string>
#include <algorithm>
/*
 * map容器
 * 1. 构造函数 赋值
 * 2. 大小和交换
 * 3. 插入和删除
 * 4. 查找和统计
 * 5. 统计
 */
using namespace std;

void printMap(map<int,int>&m) {
    for (map<int,int>::iterator it = m.begin(); it!=m.end(); it++) {
        cout << "key=" << it->first << " value=" << (*it).second << endl;
    }
    cout << endl;
}
void test01() {
    map<int,int> m;
    // 匿名对组创建map key---1 value--10
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(4,40));
    printMap(m);  // 按照key值进行排序
    // 拷贝构造
    map<int,int>m2(m);
    printMap(m2);
    // 赋值
    map<int,int>m3;
    m3 = m2;
    printMap(m3);
}
void test02() {
    map<int,int>m1;
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    if (m1.empty()) {
        cout << "m为空" << endl;
    } else {
        cout << "m不为空" << endl;
        cout << "m的大小：" << m1.size() << endl;
    }
    // 交换
    map<int,int>m2;
    m2.insert(pair<int,int>(4,10));
    m2.insert(pair<int,int>(5,20));
    m2.insert(pair<int,int>(6,30));
    cout << "交换后：" << endl;
    m1.swap(m2);
    printMap(m1);
    printMap(m2);
}
void test03() {
    map<int,int>m;
    // 插入
    m.insert(pair<int,int>(1,10));
    m.insert(make_pair(2,20));
    m.insert(map<int,int>::value_type(3,30));
    m[4] = 40; // 读取时 确定键值存在 避免访问导致写入
    printMap(m);
    m.erase(m.begin());
    m.erase(3);// 按照key值删除
    printMap(m);
}
class myCompare{
public:
    bool operator()(int v1,int v2) const{
        return v1>v2;
    }
};
void test05() {
    map<int,int,myCompare>m;
    m.insert(make_pair(1,10));
    m.insert(make_pair(2,20));
    m.insert(make_pair(3,30));
    m.insert(make_pair(4,40));
    m.insert(make_pair(5,50));

    for (map<int,int,myCompare>::iterator it = m.begin(); it!=m.end(); it++) {
        cout << "key=" << it->first << " value=" << (*it).second << endl;
    }
    cout << endl;
}
int main() {
//    test01();
//    test02();
//    test03();
    test05();
}
