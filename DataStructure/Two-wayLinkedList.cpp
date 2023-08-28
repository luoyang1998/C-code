#include <iostream>
/*
 * 双向链表
 */
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
Node* head;
Node* getNewNode(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}
void isertHead(int x) {
    Node* temp = getNewNode(x);
    if (head == NULL) {
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}
void myPrint() {
    Node* temp = head;
    printf("Forward:");
    while (temp!=NULL) {
        printf(" %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void reversePrint() {
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Backward:");
    while (temp!=NULL) {
        printf(" %d",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
int main() {
    head = NULL;
    isertHead(2);
    isertHead(3);
    isertHead(4);
    myPrint();
    reversePrint();
}
