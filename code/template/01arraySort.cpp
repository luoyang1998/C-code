#include <iostream>
/*
 * 1.利用函数模板封装一个排序的函数，对不同数据类型数组进行排序
 * 2.排序规则从大到小，排序算法为选择排序
 */

using namespace std;
// 交换
template<typename T>
void mySwap( T &a, T &b ) {
    T temp = a;
    a = b;
    b = temp;
}
// 排序
template<class T>
void mySort(T arr[],int len) {
    for (int i = 0; i < len; i++) {
        int max = i;
        for (int j = i+1; j < len; j++) {
            if (arr[max] < arr[j]) {
                max = j;
            }
        }
        if (max!=i) {
            // 交换max i 元素
            mySwap(arr[max],arr[i]);
        }
    }
}
// 打印
template<class T>
void myPrint(T arr[], int len) {
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
}
void test01() {
    char charArray[] = "badcfe";
    int num = sizeof(charArray) / sizeof(char);
    mySort(charArray ,num);
    myPrint(charArray,num);
}
void test02() {
    int arr[] = {2,5,8,4,32};
    int num = sizeof(arr) / sizeof(int);
    mySort(arr,num);
    myPrint(arr,num);
}
int main() {
    test01();
//    test02();
}
