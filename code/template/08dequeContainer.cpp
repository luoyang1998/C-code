#include <iostream>
#include <deque>
#include <algorithm>
/*
 * deque����
 * 1. ���캯��
 * 2. ��ֵ����
 * 3. ��С����
 * 4. �����ɾ��
 * 5. ���ݴ�ȡ
 * 6. ����
 */
using namespace std;
void printDeque(const deque<int>&d) { // �޸�Ϊֻ��������
    for (deque<int>::const_iterator it=d.begin(); it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test01() {
    deque<int>d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int>d2(d1.begin(),d1.end());
    deque<int>d3(10,100);
    deque<int>d4(d3);
}
void test02() {
    deque<int>d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int>d2 = d1;
    printDeque(d2);

    deque<int>d3;
    d3.assign(d1.begin(),d1.end());
    printDeque(d3);

    deque<int>d4;
    d4.assign(10,100);
    printDeque(d4);
}
void test03() {
    deque<int>d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }
    printDeque(d1);

    if (d1.empty()) {
        cout << "d1Ϊ��" << endl;
    } else {
        cout << "d1��Ϊ��" << endl;
        cout << "d1�Ĵ�С:" << d1.size() << endl;//10
    }
    // ����ָ����С
    d1.resize(12);
    printDeque(d1);//0 1 2 3 4 5 6 7 8 9 0 0
    d1.resize(15,1);
    printDeque(d1);//0 1 2 3 4 5 6 7 8 9 0 0 1 1 1
    d1.resize(4);
    printDeque(d1);//0 1 2 3
    
}
void test04() {
    deque<int>d1;
    // β��
    d1.push_back(10);
    d1.push_back(20);
    // ͷ��
    d1.push_front(30);
    d1.push_front(40);
    printDeque(d1);//40 30 10 20
    d1.pop_back();
    d1.pop_front();
    printDeque(d1);//30 10

    deque<int>d2;
    d2.push_back(10);
    d2.push_back(20);
    d2.push_front(30);
    d2.push_front(40);
    // insert����
    d2.insert(d2.begin(),100);
    printDeque(d2);//100 40 30 10 20
    d2.insert(d2.begin(),2,200);
    printDeque(d2);//200 200 100 40 30 10 20
    d2.insert(d2.begin(),d1.begin(),d1.end());
    printDeque(d2);//30 10 200 200 100 40 30 10 20
    //ɾ��
    deque<int>::iterator it = d2.begin();
    it++; // ��������һ��λ��ƫ��
    d2.erase(it);
    printDeque(d2);//30 200 200 100 40 30 10 20
    d2.erase(d2.begin(),d2.end());
    printDeque(d2);
    d2.clear();

}
void test05() {
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(30);
    d1.push_front(40);
    for (int i = 0; i < d1.size(); ++i) {
        cout << d1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < d1.size(); ++i) {
        cout << d1.at(i) << " ";
    }
    cout << endl;
    cout << "��һ��Ԫ��:" << d1.front() << " ���һ��Ԫ�أ�" << d1.back() << endl;
}
void test06() {
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(30);
    d1.push_front(40);// 40 30 10 20
    printDeque(d1);
    // ���� ��С����
    // ����֧��������ʵĵ�����������������ͨ��sort��������
    sort(d1.begin(),d1.end());
    cout << "�����" << endl;
    printDeque(d1);//10 20 30 40
}
int main() {
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
    test06();
}
