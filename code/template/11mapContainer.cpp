#include <iostream>
#include <map>
#include <string>
#include <algorithm>
/*
 * map����
 * 1. ���캯�� ��ֵ
 * 2. ��С�ͽ���
 * 3. �����ɾ��
 * 4. ���Һ�ͳ��
 * 5. ͳ��
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
    // �������鴴��map key---1 value--10
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(4,40));
    printMap(m);  // ����keyֵ��������
    // ��������
    map<int,int>m2(m);
    printMap(m2);
    // ��ֵ
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
        cout << "mΪ��" << endl;
    } else {
        cout << "m��Ϊ��" << endl;
        cout << "m�Ĵ�С��" << m1.size() << endl;
    }
    // ����
    map<int,int>m2;
    m2.insert(pair<int,int>(4,10));
    m2.insert(pair<int,int>(5,20));
    m2.insert(pair<int,int>(6,30));
    cout << "������" << endl;
    m1.swap(m2);
    printMap(m1);
    printMap(m2);
}
void test03() {
    map<int,int>m;
    // ����
    m.insert(pair<int,int>(1,10));
    m.insert(make_pair(2,20));
    m.insert(map<int,int>::value_type(3,30));
    m[4] = 40; // ��ȡʱ ȷ����ֵ���� ������ʵ���д��
    printMap(m);
    m.erase(m.begin());
    m.erase(3);// ����keyֵɾ��
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
