#include <iostream>
#include <stack>
#include <cstring>

#define MAX_SIZE 101
/*
 * 通过数组 实现栈
 */
using namespace std;
int A[MAX_SIZE];
int top = -1;
/// 入栈
void Push(int x) {
    // 自溢
    if (top == MAX_SIZE-1) {
        printf("Error:stack overflow\n");
        return;
    }
    A[++top] = x;
//     top++;
//     A[top] = x;
}
/// 出栈
void Pop() {
    if (top == -1) {
        printf("Error:Non element to pop\n");
        return;
    }
    top--;
}
/// 返回栈顶数字
int Top() {
    return A[top];
}
void Print() {
    int i;
    printf("Stack:");
    for (int i = 0; i <= top; ++i) {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void test01() {
    Push(2);Print();
    Push(5);Print();
    Push(10);Print();
    Pop();Print();
    Push(12);Print();
    cout << Top() << endl;
}

//class Stack{
//private:
//    char B[101];
//    int top;
//public:
//    void Push(int x);
//    void Pop();
//    int Top();
//    bool IsEmpty();
//};
void Reverse(char C[],int n) {
    stack<char> S;
    for (int i = 0; i < n; ++i) {
        S.push(C[i]);
    }
    for (int i = 0; i < n; ++i) {
        C[i] = S.top();
        S.pop();
    }
}
/// 反转字符串或链表
void test02() {
    char C[51];
    printf("Enter a string:");
    gets(C);
    Reverse(C,strlen(C));
    printf("Output = %s",C);
}
int main() {
//    test01();
    test02();
}
