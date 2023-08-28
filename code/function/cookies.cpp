#include <iostream>
using namespace std;
int sum_arr(const int* begin, const int* end);
//int sum_arr(int* arr,int n);

//  统计总和
int main()
{
    const int ArSize = 8;
    int cookies[ArSize] = {1,2,4,8,16,32,64,128};
    int sum = sum_arr(cookies,cookies+ArSize);  // 传入为指针，输出指针大小为整个数组大小
    cout << "甜饼数：" << sum << endl;
}

int sum_arr(const int* begin, const int* end)
{
    const int* pt;
    int total{0};
    for (pt = begin;  pt != end ; pt++) {
        total = total + *pt;
    }
    return total;
}

//  int arr[]均意味指向一个指针   数组类型为int cookies指针类型为int*
//int sum_arr(int* arr,int n)
//{
//    int total = 0;
//    cout << sizeof(arr) << endl;     // 这里一个指针变量的长度
//    for(int i=0;i<n;i++)
//    {
//        total = total + arr[i];
//    }
//    return total;
//}
