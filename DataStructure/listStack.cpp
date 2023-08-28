#include <iostream>
#include <string>
#include <cstring>
#include <stack>
/*
 * 通过链表 实现栈
 * 头部为栈顶
 */
using namespace std;
struct Node {
    char data;
    Node *link;
};
Node* top = NULL;

void Push(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->link = top;
    top = temp;
}
void Pop() {
    Node* temp;
    if (top == NULL) return;
    temp = top;
    top = temp->link;
    free(temp);
}
/// 反转一个链表
void Reverse() {
    if (top == NULL) {
        stack<Node*> S;
        Node* temp = top;
        while (temp!=NULL) {
            S.push(temp);
            temp = temp->link;
        }
        temp = S.top();
        top = temp;
        S.top();
        while (!S.empty()) {
            temp->link = S.top();
            S.pop();
            temp = temp->link;
        }
        temp->link = NULL;
    }
}
/// 检查括号匹配性
void test01() {

}

int main() {
    test01();
}