#include <iostream>
#include <vector>
#include <algorithm>
/*
 * ν��
 * 1. һԪν��
 * 2. ��Ԫν��
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
    // ���Ҵ���5������
    // greaterFive()��������
    vector<int>::iterator it = find_if(v.begin(),v.end(),greaterFive());
    if (it == v.end()) {
        cout << "δ�ҵ�" << endl;
    } else {
        cout << "�ҵ�����5������:" << *it << endl;
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
    // �ı��������Ӵ�С
    sort(v.begin(),v.end(),myCompare());
    for (vector<int>::iterator it=v.begin();it!=v.end();it++) {
        cout << *it << " ";
    }
}
int main() {
//    test01();
    test02();
}