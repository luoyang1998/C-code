#include <iostream>
#include <set>
#include <string>
#include <algorithm>
/*
 * set����
 * 1. ���캯�� ��ֵ
 * 2. ��С�ͽ���
 * 3. �����ɾ��
 * 4. ���Һ�ͳ��
 * 5. ����Ĵ���
 * 6. ����: ���������������
 * 7. ���򣺴���Զ�����������
 */
using namespace std;

void printSet(set<int>&s) {
    for (set<int>::iterator it = s.begin(); it!=s.end(); it++)
        cout << *(it) << " ";

    cout << endl;
}
void test01() {
    set<int>s1;
    // �������� ֻ��insert
    s1.insert(10);
    s1.insert(30);
    s1.insert(40);
    s1.insert(20);
    printSet(s1);//10 20 30 40
    // ��������
    set<int>s2(s1);
    printSet(s2);
    set<int>s3;
    s3 = s2;
    printSet(s3);
}
void test04() {
    // ����
    set<int>s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    set<int>::iterator pos = s1.find(30);
    if (pos != s1.end()) {
        cout << "�ҵ�Ԫ�أ�" << *pos << endl;
    } else {
        cout << "δ�ҵ�Ԫ��" << endl;
    }
    // ͳ��
    int num = s1.count(30);
    cout << "Ԫ�ظ�����" << num << endl;
}
void test05() {
    // set�ײ���ж��Ƿ����ɹ�
    set<int>s;
    pair<set<int>::iterator ,bool> ret = s.insert(10);
    if (ret.second) {
        cout << "����ɹ�" << endl;
    } else {
        cout << "����ʧ��" << endl;
    }

    // ��ʽһ
    pair<string, int>p("Tom",20);
    cout << "������" << p.first << " ���䣺" << p.second << endl;
    // ��ʽ��
    pair<string ,int>p2 = make_pair("Jerry",2);
    cout << "������" << p2.first << " ���䣺" << p2.second << endl;
}
/// �º���
class myCompare {
public:
    bool operator()(int v1,int v2) const {
        return v1>v2;
    }
};
void test06() {
    set<int,myCompare>s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    // ָ���������Ӵ�С ��������ʱ �޸Ĺ���
    for (set<int,myCompare>::iterator it = s.begin(); it!=s.end(); it++) {
        cout << *(it) << " ";
    }
    cout << endl;
}
class Person{
public:
    Person (string name,int age) {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};
class comparePerson {
public:
    bool operator()(const Person& p1,const Person& p2) const {
        // �������� ����
        return p1.m_Age > p2.m_Age;
    }
};
void test07() {
    // �Զ����������� ����Ҫָ���������
    set<Person,comparePerson>s;
    Person p1("����",35);
    Person p2("�ܲ�",45);
    Person p3("��Ȩ",40);
    Person p4("����",25);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    for (set<Person,comparePerson>::iterator it = s.begin(); it!=s.end(); it++) {
        cout << "������" << it->m_Name << " ���䣺" << it->m_Age << endl;
    }
}
int main() {
//    test01();
//    test04();
//    test05();
//    test06();
    test07();
}