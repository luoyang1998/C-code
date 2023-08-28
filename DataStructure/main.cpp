#include <iostream>

using namespace std;

// 定义节点结构体
struct Node {
    int data;
    Node* next;
};
// 定义头指针
Node* head;
// 在头节点后插入
void myInsert(int x) {
    // 创建节点
    //    Node* temp = (Node*) malloc(sizeof(Node));
    //    (*temp).data = 2;
    //    (*temp).link = NULL;

    Node* temp = new Node();
    temp->data = x;
//    temp->next = NULL;

    // 插入节点 地址指向下一个地址
//    if (head != NULL)
    temp->next = head;
    // 头节点指向插入节点地址
    head = temp;
}
void myPrint() {
    Node* temp = head;
    printf("List is:");
    while (temp!=NULL) {
        printf(" %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
//////// 在头部插入节点
void test01() {
    head = NULL; // 空指针
    // 输入节点数字
    int n,x;
    printf("How many numbers?\n");
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        printf("Enter the number: \n");
        scanf("%d",&x);
        myInsert(x);
        myPrint();
    }
}


// 在任意节点后插入，在n-1位置插入data
void myInsert(int data,int n) {
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;

    if (n==1) {
        temp1->next = head;
        head = temp1;
        return;
    }
    // 插入节点 地址指向下一个地址  temp2指向temp1
    Node* temp2 = head;
    for (int i = 0; i < n-2; ++i) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}
//////// 在任意位置插入节点
void test02() {
    head = NULL;
    myInsert(2,1);
    myInsert(3,2);
    myInsert(4,3);
    myInsert(5,4);
    myPrint();
}


// 在最后插入节点
void myInsertBack(int data) {
    Node* temp1 = new Node();
    temp1->data = data;

    if (head == NULL) {
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    // 插入尾部节点 地址指向下一个地址  temp2指向temp1
    while(temp2->next!=NULL) {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
//    temp2->next = temp1;
}
// 删除位置n的节点
void myDelete(int n) {
    // 寻找节点
    Node* temp1 = head;
    if (n==1) {
        head = temp1->next;
        free(temp1);
        return;
    }
    // 要删除节点前一个temp1,删除temp2
    for (int i = 0; i < n-2; ++i) {
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2); // delect(temp2)
}


/////// 删除节点
void test03() {
    head = NULL;
    myInsertBack(2);
    myInsertBack(3);
    myInsertBack(4);
    myInsertBack(5);
    myPrint();

    int n;
    printf("Enter a position: \n");
    scanf("%d",&n);
    myInsertBack(n);
    myDelete(n);
    myPrint();
}


void Reverse() {
    Node *current,*next,*prev;
    current = head;
    prev = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
//    return head;
}
void recurReverse(Node *p) {
    if (p->next == NULL) {
        head = p;
        return;
    }
    recurReverse(p->next);
    Node *q = p->next;
    q->next = p;
    p->next = NULL;
}
//////// 反转链表
void test04(){
    myInsertBack(2);
    myInsertBack(3);
    myInsertBack(4);
    myInsertBack(5);
    myPrint();

    Reverse();
    myPrint();
    printf("\n");
    recurReverse(head);
    myPrint();
}


void Print(Node* p) {
    if (p == NULL) return;
    printf("%d ",p->data);
    Print(p->next);
}void reversePrint(Node* p) {
    if (p == NULL) return;
    reversePrint(p->next);
    printf("%d ",p->data);
}
/////// 递归打印列表
void test05(){
    myInsertBack(2); // 尾部插入不会修改头节点地址
    myInsertBack(3);
    myInsertBack(4);
    myInsertBack(5);
    myPrint();

    Print(head);
    reversePrint(head);
}
int main() {
//    test01();
//    test02();
//    test03();
    test04();
//    test05();
}