#include <iostream>

using namespace std;

template<class T>
class MyArry{
public:
    MyArry(int capacity){
        this->maCapactiy = capacity;
        this->mSize = 0;
        // 申请内存
        this->pAddr = new T[this->maCapactiy];
    }
    MyArry(const MyArry<T>& arr) {
        this->mSize = arr.mSize;
        this->maCapactiy = arr.maCapactiy;
        // 申请内存空间
        this->pAddr = new T[this->maCapactiy];
        // 数据拷贝
        for (int i = 0; i < this->mSize; ++i) {
            this->pAddr[i] = arr.pAddr[i];
        }
    }
    T& operator[](T& index) {
        return this->pAddr[index];
    }
    T& operator=(const MyArry<T>& arr){
        if (this->pAddr != NULL) {
            delete[] this->pAddr;
        }
        this->mSize = arr.mSize;
        this->maCapactiy = arr.maCapactiy;

        // 申请内存空间
        this->pAddr = new T[this->maCapactiy];
        // 数据拷贝
        for (int i = 0; i < this->mSize; ++i) {
            this->pAddr[i] = arr.pAddr[i];
        }

        return  *this;
    }
    void PushBack(T& data){
        // 判断容器中是否有位置
        if (this->mSize >= this->maCapactiy){
            return;
        }

        // 调用拷贝构造函数 =号
        // 1. 随想元素确保可以被拷贝
        // 2. 容器都是值寓意，而不是引用，向容器放入元素，都是进行拷贝
        // 3. 如果元素成员有指针，注意深拷贝和浅拷贝
        this->pAddr[this->mSize] = data;
        this->mSize++;
    }
    // 对右值引用
    void PushBack(T&& data){
        // 判断容器中是否有位置
        if (this->mSize >= this->maCapactiy){
            return;
        }
        this->pAddr[this->mSize] = data;
        this->mSize++;
    }
    ~MyArry(){
        if (this->pAddr != NULL) {
            delete[] this->pAddr;
        }
    }
public:
    // 一共可以容下多少元素
    int maCapactiy;
    // 当前数组多少元素
    int mSize;
    // 保存数据的首地址
    T* pAddr;
};

void test(){
    MyArry<int> marray(20);
    int a = 10,b = 20, c = 30,d = 40;
    marray.PushBack(a);
    marray.PushBack(b);
    marray.PushBack(c);
    marray.PushBack(d);

    // 右值
    marray.PushBack(100);
    marray.PushBack(200);
    marray.PushBack(300);

    for (int i = 0; i < marray.mSize; ++i) {
        cout << marray[i] << " ";
    }
    cout << endl;
};

int main() {
    test();
}
