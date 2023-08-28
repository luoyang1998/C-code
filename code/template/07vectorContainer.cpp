#include <iostream>
#include <vector>
/*
 * vector����
 * 1. ���캯��
 * 2. ��ֵ����
 * 3. �����ʹ�С
 * 4. �����ɾ��
 * 5. ���ݴ�ȡ
 * 6. ��������
 * 7. Ԥ���ռ�
 */
using namespace std;
/// ��ӡ
void printVector(vector<int> &v) {
    for (vector<int>::iterator it=v.begin();it!=v.end();it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test01() {
    vector<int>v1;  // Ĭ�Ϲ���
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    // ͨ�����䷽ʽ
    vector<int>v2(v1.begin(),v1.end());
    printVector(v2);

    // n��elem
    vector<int>v3(10,100);
    printVector(v3);

    // �������캯��
    vector<int>v4(v3);
    printVector(v4);
}
void test02() {
    vector<int>v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    // ��ֵ
    vector <int>v2;
    v2 = v1;
    printVector(v2);
    // assign
    vector<int>v3;
    v3.assign(v1.begin(),v1.end());
    printVector(v3);
    // n��elem
    vector<int>v4;
    v4.assign(10,100);
    printVector(v4);
}
void test03() {
    vector<int>v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    if (v1.empty()) { // trueΪ��
        cout << "v1Ϊ��" << endl;
    } else {
        cout << "v1��Ϊ��" << endl;
        cout << "����Ϊ��" << v1.capacity() << endl;
        cout << "v1Ԫ�ظ���" << v1.size() << endl;
    }
    // ����ָ����С
    v1.resize(15);
    printVector(v1); //Ĭ����0�����λ��
    v1.resize(20,100);
    printVector(v1);
    v1.resize(5);
    printVector(v1); // 0 1 2 3 4
}
void test04() {
    vector<int>v1;
    // β��
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printVector(v1); //10 20 30 40 50
    // βɾ
    v1.pop_back();
    printVector(v1);  //10 20 30 40
    // ����  ��һ�������ǵ�����
    v1.insert(v1.begin(),100);
    printVector(v1);  //100 10 20 30 40
    v1.insert(v1.begin(),2,10);
    printVector(v1);  //10 10 100 10 20 30 40
    // ɾ��  ��һ�������ǵ�����
    v1.erase(v1.begin());
    printVector(v1);  //10 100 10 20 30 40
    v1.erase(v1.begin(),v1.end());
    printVector(v1);

}
void test05() {
    vector<int>v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    // ����[]����
    for (int j = 0; j < v1.size(); ++j) {
        cout << v1[j] << " ";
    }
    cout << endl;
    // ����at����
    for (int j = 0; j < v1.size(); ++j) {
        cout << v1.at(j) << " ";
    }
    cout << endl;
    // ��ȡ��һ��Ԫ��
    cout << "��һ��Ԫ��Ϊ:" << v1.front() << endl;
    // ��ȡ���һ��Ԫ��
    cout << "���һ��Ԫ��Ϊ:" << v1.back() << endl;
}
void test06() {
    vector<int>v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);
    vector<int>v2;
    for (int i = 10; i > 0; --i) {
        v2.push_back(i);
    }
    printVector(v2);

    cout << "������" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);

    /// ʵ����; ���������ڴ�ռ�
    vector<int>v;
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
    }
    cout << "v��������" << v.capacity() << " v�Ĵ�С��" << v.size() << endl; //128 100
    v.resize(3);
    cout << "v��������" << v.capacity() << " v�Ĵ�С��" << v.size() << endl; //128 3
    vector<int>(v).swap(v); // ��������������������
    cout << "v��������" << v.capacity() << " v�Ĵ�С��" << v.size() << endl; //3 3
}
void test07() {
    vector<int>v;
    // ����reserveԤ���ռ�
    v.reserve(100);
    int num = 0; //ͳ�ƿ����ڴ����
    int *p = NULL;
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
        if (p != &v[0]) {
            p = &v[0];
            num++;
        }
    }
    cout << num << endl; //8  resever�� 1
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