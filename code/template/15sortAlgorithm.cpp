#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
/*
 * 排序算法
 * 1. sort
 * 2. random_shuffle
 * 3. merge
 * 4. reverse
 */
using namespace std;
void myPrint(int val) {
    cout << val << " ";
}
void test01() {
    vector<int>v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);
    // 利用sort进行升序
    sort(v.begin(),v.end());
    for_each(v.begin(),v.end(), myPrint);
    cout << endl;
    // 降序
    sort(v.begin(),v.end(),greater<int>());
    for_each(v.begin(),v.end(), myPrint);
}

void test02() {
    srand((unsigned int)time(NULL)); // 随机种子 使每次打乱顺序不同
    vector<int>v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    // 利用洗牌 算法 打乱顺序
    random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(), myPrint);//8 1 9 2 0 5 7 3 4 6
}
void test03() {
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i+1);
    }
    // 目标容器
    vector<int>vTarget;
    vTarget.resize(v1.size()+v2.size());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
    for_each(vTarget.begin(),vTarget.end(), myPrint);
}
void test04() {
    vector<int>v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    reverse(v.begin(),v.end());
    for_each(v.begin(),v.end(), myPrint);//40 20 50 30 10
}
int main() {
//    test01();
//    test02();
//    test03();
    test04();
}