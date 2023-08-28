#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

/*
 * 两个队列实现一个栈
 *
 */
using namespace std;


class MyStack{
public:
    queue<int> q1;
    queue<int> q2;

    // 判空
    bool isEmpty(){
        return q1.empty();
    }
    // 入栈
    void Push(int val){
        q1.push(val);
    }
    // 出栈
    bool Pop(){
        if (isEmpty()) return false;
        while (q1.size() > 1){
            int temp = q1.front();
            q2.push(temp);
            q1.pop();
        }
        int dei = q1.front(); // 可返回删除元素
        swap(q1,q2); // 交换q1,q2保证每次只需要在q1中操作插入
    }
    // 返回栈顶元素
    int peek(){
        if (isEmpty()) return NULL;
        int val = q1.front();
        return val;
    }

    void myprint(){
        if (isEmpty()){
            cout << "栈为空" << endl;
        } else {
            for (int i = q1.front(); i <= q1.back(); ++i) {
                cout << i << " ";
            }
            cout << endl;
        }

    }
};
int main(){
    MyStack s1;
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    s1.Push(4);
    s1.myprint();
    s1.Pop();
    s1.myprint();
    cout << s1.peek() << endl;
}
