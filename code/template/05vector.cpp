#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
/*
 * 1. vector���������������
 * 2. vector����Զ�����������
 * 3. ����Ƕ������
 */
using namespace std;

void myPrint(int val) {
    cout << val << endl;
}
void test01() {
    // ����vector����������
    vector<int> v;
    // �������� β��
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    // ͨ����������������������
    vector<int>::iterator itBegin = v.begin(); // ��ʼ��������ָ��������һ��Ԫ��
    vector<int>::iterator itEnd = v.end(); // ������������ָ���������һ��Ԫ�ص���һ��λ��

    // ��һ�ֱ�����ʽ
    while (itBegin != itEnd) {
        cout << *itBegin << endl;
        itBegin++;
    }
    // �ڶ��ֱ�����ʽ
    for (vector<int>::iterator it = v.begin();it!=v.end();it++) {
        cout << *it << endl;
    }
    // �����ֱ�����ʽ ����STL�ṩ�����㷨
    for_each(v.begin(),v.end(), myPrint);
}

/// 2. �Զ�����������
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

    // ���������������
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    // ��������
    for (vector<Person>::iterator it=v.begin();it!=v.end();it++) {
        cout << "������" << (*it).m_Name << "  ���䣺" << (*it).m_Age << endl;
    }
}
// ����Զ�������ָ��
void test03() {
    vector<Person*> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);

    // ���������������
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    // ��������
    for (vector<Person*>::iterator it=v.begin();it!=v.end();it++) {
        cout << "������" << (*it)->m_Name << "  ���䣺" << (*it)->m_Age << endl;
    }
}
/// Ƕ������
void test04() {
    vector<vector<int>> v;
    // ����С����
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>v4;
    // С�����������
    for (int i = 0; i < 4; ++i) {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }
    // ��С�������������
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    // ����������
    for (vector<vector<int>>::iterator it=v.begin();it!=v.end();it++) {
        // (*it) ---- ��һ������
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
