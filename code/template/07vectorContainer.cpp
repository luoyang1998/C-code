#include <iostream>
#include <vector>
/*
 * vector容器
 * 1. 构造函数
 * 2. 赋值操作
 * 3. 容量和大小
 * 4. 插入和删除
 * 5. 数据存取
 * 6. 互换容器
 * 7. 预留空间
 */
using namespace std;
/// 打印
void printVector(vector<int> &v) {
    for (vector<int>::iterator it=v.begin();it!=v.end();it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test01() {
    vector<int>v1;  // 默认构造
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    // 通过区间方式
    vector<int>v2(v1.begin(),v1.end());
    printVector(v2);

    // n个elem
    vector<int>v3(10,100);
    printVector(v3);

    // 拷贝构造函数
    vector<int>v4(v3);
    printVector(v4);
}
void test02() {
    vector<int>v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    // 赋值
    vector <int>v2;
    v2 = v1;
    printVector(v2);
    // assign
    vector<int>v3;
    v3.assign(v1.begin(),v1.end());
    printVector(v3);
    // n个elem
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

    if (v1.empty()) { // true为空
        cout << "v1为空" << endl;
    } else {
        cout << "v1不为空" << endl;
        cout << "容量为：" << v1.capacity() << endl;
        cout << "v1元素个数" << v1.size() << endl;
    }
    // 重新指定大小
    v1.resize(15);
    printVector(v1); //默认用0填充新位置
    v1.resize(20,100);
    printVector(v1);
    v1.resize(5);
    printVector(v1); // 0 1 2 3 4
}
void test04() {
    vector<int>v1;
    // 尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printVector(v1); //10 20 30 40 50
    // 尾删
    v1.pop_back();
    printVector(v1);  //10 20 30 40
    // 插入  第一个参数是迭代器
    v1.insert(v1.begin(),100);
    printVector(v1);  //100 10 20 30 40
    v1.insert(v1.begin(),2,10);
    printVector(v1);  //10 10 100 10 20 30 40
    // 删除  第一个参数是迭代器
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
    // 利用[]访问
    for (int j = 0; j < v1.size(); ++j) {
        cout << v1[j] << " ";
    }
    cout << endl;
    // 利用at访问
    for (int j = 0; j < v1.size(); ++j) {
        cout << v1.at(j) << " ";
    }
    cout << endl;
    // 获取第一个元素
    cout << "第一个元素为:" << v1.front() << endl;
    // 获取最后一个元素
    cout << "最后一个元素为:" << v1.back() << endl;
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

    cout << "交换后：" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);

    /// 实际用途 可以收缩内存空间
    vector<int>v;
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
    }
    cout << "v的容量：" << v.capacity() << " v的大小：" << v.size() << endl; //128 100
    v.resize(3);
    cout << "v的容量：" << v.capacity() << " v的大小：" << v.size() << endl; //128 3
    vector<int>(v).swap(v); // 拷贝函数构造匿名对象
    cout << "v的容量：" << v.capacity() << " v的大小：" << v.size() << endl; //3 3
}
void test07() {
    vector<int>v;
    // 利用reserve预留空间
    v.reserve(100);
    int num = 0; //统计开辟内存次数
    int *p = NULL;
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
        if (p != &v[0]) {
            p = &v[0];
            num++;
        }
    }
    cout << num << endl; //8  resever后 1
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