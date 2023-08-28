#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
/*
 * 内建函数对象
 * 1. 算数仿函数
 * 2. 关系仿函数
 * 3. 逻辑仿函数
 */
using namespace std;
void test01() {
    // negate 一元仿函数 取反
    negate<int>n;
    cout << n(50) << endl; //-50
    // plus 二元仿函数 加法
    plus<int>p;   // 默认两个元素 数据类型相同
    cout << p(10,20) << endl;//30
}
void test02() {
    // 大于 greater
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    // 降序
    // sort(v.begin(),v.end(),myCompare());
    sort(v.begin(),v.end(),greater<int>());
    for (vector<int>::iterator it=v.begin();it!=v.end();it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test03() {
    // 逻辑非 logical_not
    vector<bool>v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    for (vector<bool>::iterator it=v.begin();it!=v.end();it++) {
        cout << *it << " ";
    }
    cout << endl;
    // 利用逻辑非 v -> v2并取反
    vector<bool>v2;
    v2.resize(v.size());
    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());
    for (vector<bool>::iterator it=v2.begin();it!=v2.end();it++) {
        cout << *it << " ";
    }
    cout << endl; // 0101
}
int main() {
//    test01();
//    test02();
    test03();
}