#include <iostream>
#include <list>
#include <algorithm>
/*
 * list����
 * 1. ���캯��
 * 2. ��ֵ�ͽ���
 * 3. ��С����
 * 4. �����ɾ��
 * 5. ���ݴ�ȡ
 * 6. ��ת������
 * 7. ����
 */
using namespace std;
void printList(const list<int>&L) {
    for (list<int>::const_iterator it=L.begin();it!=L.end();it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test01() {
    list<int>L1; //Ĭ�Ϲ���
    //β��
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);
    // ���乹��
    list<int>L2(L1.begin(),L1.end());
    printList(L2);
    list<int>L3(10,100);
    printList(L3);
    list<int>L4(L3);
    printList(L4);
}
void test02() {
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);//10 20 30 40

    // ��ֵ
    list<int>L2;
    L2 = L1;
    printList(L2);//10 20 30 40
    list<int>L3;
    L3.assign(L2.begin(),L2.end());
    printList(L3);//10 20 30 40
    list<int>L4;
    L4.assign(10,100);
    printList(L4);//100 100 100 100 100 100 100 100 100 100
    // ����
    L4.swap(L2);
    cout << "������:" << endl;
    printList(L2);//100 100 100 100 100 100 100 100 100 100
    printList(L4);//10 20 30 40
}
void test03() {
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);//10 20 30 40

    if (empty(L1)) {
        cout << "L1Ϊ��" << endl;
    } else {
        cout << "L1��Ϊ��" << endl;
        cout << "L1��Ԫ�ظ�����" << size(L1) << endl;
    }

    L1.resize(6,1);
    L1.resize(8);
    printList(L1);//10 20 30 40 1 1 0 0
    L1.resize(3);
    printList(L1);//10 20 30
}
void test04() {
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    // ͷ��
    L1.push_front(40);
    L1.push_front(50);
    L1.push_front(60);
    printList(L1);//60 50 40 10 20 30
    // ɾ��
    L1.pop_back();
    printList(L1);//60 50 40 10 20
    L1.pop_front();
    printList(L1);//50 40 10 20
    //����  �ṩ������
    list<int>::iterator it = L1.begin();
    L1.insert(++it,100);
    printList(L1);//50 100 40 10 20
    //ɾ��
    it = L1.begin();
    L1.erase(++it);
    printList(L1);//50 40 10 20
    //�Ƴ�
    L1.remove(10);
    printList(L1);//50 40 20
}
void test05() {
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    cout << "��һ��Ԫ�أ�" << L1.front() << endl;//10
    cout << "���һ��Ԫ�أ�" << L1.back() << endl;//30
}
/// �Ӵ�С����
bool myCompare(int v1,int v2) {
    // ���� �õ�һ����>�ڶ�����
    return v1>v2;
}
void test06() {
    list<int>L1;
    L1.push_back(10);
    L1.push_back(30);
    L1.push_back(20);
    L1.push_back(50);
    L1.push_back(40);
    printList(L1);//10 30 20 50 40
    //��ת
    L1.reverse();
    printList(L1);//40 50 20 30 10
    //����  Ĭ�ϴ�С���� ���в�֧��������ʵ���������֧�ֱ�׼�㷨sort(begin,end)
    L1.sort();
    printList(L1);//10 20 30 40 50
    L1.sort(myCompare);//����
    printList(L1);//50 40 30 20 10
}
/// �����������Զ����������ͽ�������Person�������������䡢���
///     ������������������������ͬ������߽��н���
class Person {
public:
    Person(string name,int age,int height) {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }

    string m_Name;
    int m_Age;
    int m_Height;
};
void printPeoson(list<Person>&L) {
    for (list<Person>::iterator it=L.begin();it!=L.end();it++) {
        cout << "������" << (*it).m_Name << " ���䣺" << it->m_Age << " ���:" << it->m_Height << endl;
    }
}
/// ָ���������
bool comparePerson(Person &p1,Person &p2) {
    // ������������
    if (p1.m_Age == p2.m_Age) {
        // ������ͬ ����߽���
        return p1.m_Height > p2.m_Height;
    } else {
        return p1.m_Age < p2.m_Age;
    }
}
void test07() {
    list<Person>L;// ��������
    Person p1("����",35,175);
    Person p2("�ܲ�",45,180);
    Person p3("��Ȩ",40,170);
    Person p4("����",25,190);
    Person p5("�ŷ�",35,160);
    Person p6("����",35,200);

    //��������
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);
    printPeoson(L);
    //����
    cout << "---------------------" << endl;
    cout << "�����:" << endl;
    L.sort(comparePerson);
    printPeoson(L);
}
int main() {
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
//    test06();
    test07();
}