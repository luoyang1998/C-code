#include <iostream>
#include <vector>
#include <algorithm>
/*
 * 谓词
 * 1. 一元谓词
 * 2. 二元谓词
 */
using namespace std;
class greaterFive {
public:
    bool operator()(int val) {
        return val>5;
    }
};
void test01() {
    vector<int>v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    // 查找大于5的数字
    // greaterFive()匿名对象
    vector<int>::iterator it = find_if(v.begin(),v.end(),greaterFive());
    if (it == v.end()) {
        cout << "未找到" << endl;
    } else {
        cout << "找到大于5的数字:" << *it << endl;
    }
}
class myCompare {
public:
    bool operator()(int v1,int v2) {
        return v1>v2;
    }
};
void test02() {
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    // 改变排序规则从大到小
    sort(v.begin(),v.end(),myCompare());
    for (vector<int>::iterator it=v.begin();it!=v.end();it++) {
        cout << *it << " ";
    }
}
int main() {
//    test01();
    test02();
}