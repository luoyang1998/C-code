#include <iostream>
#include <vector>
#include <algorithm>
/*
 * �����㷨
 * 1. set_intersection
 * 2. set_union
 * 3. set_difference
 */
using namespace std;
void myPrint(int val) {
    cout << val << " ";
}
void test01() {
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i); // 0-9
        v2.push_back(i+5); // 5-14
    }

    vector<int>vTarget;
    // ��ǰ���ٿռ�
    vTarget.resize(min(v1.size(),v2.size())); // ����������С����
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    // ���õ������end ȷ��������ݸ�����ͬ
    for_each(vTarget.begin(),itEnd, myPrint); // 5 6 7 8 9
}
void test02() {
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i); // 0-9
        v2.push_back(i+5); // 5-14
    }

    vector<int>vTarget;
    // ��ǰ���ٿռ�
    vTarget.resize(v1.size()+v2.size());
    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    // ���õ������end ȷ��������ݸ�����ͬ
    for_each(vTarget.begin(),itEnd, myPrint); //0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
}
void test03() {
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i); // 0-9
        v2.push_back(i+5); // 5-14
    }

    vector<int>vTarget;
    // ��ǰ���ٿռ�
    vTarget.resize(max(v1.size(),v2.size()));
    vector<int>::iterator itEnd1 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    cout << "v1��v2�Ĳ" << endl;
    for_each(vTarget.begin(),itEnd1, myPrint); //0 1 2 3 4

    cout << "------------------" << endl;
    vector<int>::iterator itEnd2 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
    cout << "v2��v1�Ĳ" << endl;
    for_each(vTarget.begin(),itEnd2, myPrint); //10 11 12 13 14
}
int main() {
//    test01();
//    test02();
    test03();
}