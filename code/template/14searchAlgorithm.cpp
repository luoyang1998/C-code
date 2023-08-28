#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
/*
 * �����㷨
 * 1. find
 * 2. find_if
 * 3. adjacent_find
 * 4. binary_search
 * 5. count
 * 6. count_if
 */

using namespace std;
class Person {
public:
    Person(string name,int age) {
        this->m_Name = name;
        this->m_Age = age;
    }
    // ����== �ײ�find��ζԱ�Person
    bool operator== (const Person &p) {
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
            return true;
        } else {
            return false;
        }
    }
    string m_Name;
    int m_Age;
};
void test01() {
    /// ������������
    vector<int>v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    // �����Ƿ��� 5 ���Ԫ��
    vector<int>::iterator it = find(v.begin(), v.end(), 5);
    if (it == v.end()) {
        cout << "û���ҵ�" << endl;
    } else {
        cout << "�ҵ���" << *it << endl;
    }
    
    /// �Զ���������
    vector<Person>p;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    vector<Person>::iterator itp = find(p.begin(), p.end(), p2);
    if (itp == p.end()) {
        cout << "û���ҵ�" << endl;
    } else {
        cout << "�ҵ���" << itp->m_Name << endl;
    }
}

class greaterFive {
public:
    bool operator() (int val) {
        return val > 5;
    }
};
class greater20 {
public:
    bool operator() (const Person &p) {
        return p.m_Age > 20;
    }
};
void test02() {
    /// ������������
    vector<int>v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    vector<int>::iterator it = find_if(v.begin(), v.end(), greaterFive());
    if (it == v.end()) {
        cout << "û���ҵ�" << endl;
    } else {
        cout << "�ҵ�>5��" << *it << endl;
    }
    /// �Զ�����������
    vector<Person>p;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);

    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    vector<Person>::iterator itp = find_if(p.begin(), p.end(), greater20());
    if (itp == p.end()) {
        cout << "û���ҵ�" << endl;
    } else {
        cout << "�ҵ�����>20��" << itp->m_Name << endl;
    }
}

void test03() {
    vector<int>v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);
    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if (it == v.end()) {
        cout << "û���ҵ�" << endl;
    } else {
        cout << "�ҵ������ظ�Ԫ�أ�" << *it << endl;
    }
}
void test04() {
    vector<int>v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    // ����Ԫ��9
    bool ret = binary_search(v.begin(), v.end(), 9);
    if (ret) {
        cout << "�ҵ�" << endl;
    } else {
        cout << "û���ҵ�" << endl;
    }
}

class Person05 {
public:
    Person05(string name,int age) {
        this->m_Name = name;
        this->m_Age = age;
    }
    // ����== �ײ�find��ζԱ�Person
    bool operator== (const Person05 &p) {
        if(this->m_Age == p.m_Age) {
            return true;
        } else {
            return false;
        }
    }
    string m_Name;
    int m_Age;
};
void test05() {
    /// ������������
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(40);

    int num = count(v.begin(), v.end(), 40);
    cout << "40��Ԫ�ظ���Ϊ��" << num << endl;

    /// �Զ�����������
    vector<Person05>p;
    Person05 p1("aaa",35);
    Person05 p2("bbb",35);
    Person05 p3("ccc",35);
    Person05 p4("ddd",40);
    Person05 p5("eee",40);
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    p.push_back(p5);

    Person05 p6("fff",35);
    int nump = count(p.begin(),p.end(),p6);
    cout << "��fff������ͬ��������" << nump << endl;
}

class greater30 {
public:
    bool operator() (int val) {
        return val > 20;
    }
};
class ageGreater30 {
public:
    bool operator()(const Person &p) {
        return p.m_Age > 30;
    }
};
void test06() {
    /// ������������
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);

    int num = count_if(v.begin(),v.end(),greater30());
    cout << "����30��Ԫ�ظ�����" << num << endl;

    /// �Զ�����������
    vector<Person>p;
    Person p1("aaa",35);
    Person p2("bbb",35);
    Person p3("ccc",35);
    Person p4("ddd",40);
    Person p5("eee",20);
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    p.push_back(p5);

    int nump = count_if(p.begin(),p.end(),ageGreater30());
    cout << "�������30�ĸ�����" << nump << endl;
}
int main() {
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
    test06();
}
