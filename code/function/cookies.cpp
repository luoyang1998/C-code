#include <iostream>
using namespace std;
int sum_arr(const int* begin, const int* end);
//int sum_arr(int* arr,int n);

//  ͳ���ܺ�
int main()
{
    const int ArSize = 8;
    int cookies[ArSize] = {1,2,4,8,16,32,64,128};
    int sum = sum_arr(cookies,cookies+ArSize);  // ����Ϊָ�룬���ָ���СΪ���������С
    cout << "�������" << sum << endl;
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

//  int arr[]����ζָ��һ��ָ��   ��������Ϊint cookiesָ������Ϊint*
//int sum_arr(int* arr,int n)
//{
//    int total = 0;
//    cout << sizeof(arr) << endl;     // ����һ��ָ������ĳ���
//    for(int i=0;i<n;i++)
//    {
//        total = total + arr[i];
//    }
//    return total;
//}
