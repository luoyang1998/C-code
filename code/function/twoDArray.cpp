#include<iostream>
using namespace std;
void fill_arr(int *arr,unsigned int sizex,unsigned int sizey);
void show_arr(int* arr,unsigned int sizex,unsigned int sizey);
// ����һ����ά���飬�����鸳ֵ�������

int main()
{
    unsigned int x{},y{};
    cout << "�����������x,y��" << endl;
    for (int i = 0; i < 2; i++) {
        if (i == 0){
            cin >> x;
        }
        if (i == 1){
            cin >> y;
        }
        if (!cin){
            cin.clear();
            while (cin.get() != '\n'){
                continue;
            }
            cout << "������Ĳ��������������������룡" << endl;
            break;
        }
    }
    int* p = new int[x * y];
    cout << "�����Ѿ�������ϣ��븳ֵ��" << endl;
    fill_arr(p,x,y);
    cout << "д��ɹ�����ʾд�����飺" << endl;
    show_arr(p,x,y);
    return 0;
}
void fill_arr(int* arr,unsigned int sizex,unsigned int sizey)
{
    for (int i = 0; i < sizex; i++) {
        for (int j = 0; j < sizey; j++) {
            cin >> arr[i * sizey + j];
        }
    }
}
void show_arr(int* arr,unsigned int sizex,unsigned int sizey)
{
    for (int i = 0; i < sizex; i++) {
        for (int j = 0; j < sizey; j++) {
            cout << arr[i * sizey + j] << " ";
        }
        cout << endl;
    }
}