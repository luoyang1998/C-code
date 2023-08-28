#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>

using namespace std;
/*
 * 1. C++��׼���쳣
 * 2. �̳����쳣�е�Ӧ��
 */

class Person{
public:
    Person(){
        mAge = 0;
    }
    void setAge(int age) {
        if (age < 0 || age > 100) {
            throw out_of_range("����Ӧ����0-100֮��");
        }
        this->mAge = age;
    }

public:
    int mAge;
};

void test01(){
    Person p;
    try{
        p.setAge(1000);
    }
//    catch (out_of_range e) {
    catch (exception e){
        // what()����C����ַ���  const char* �� string
        cout << e.what() << endl;
    }
}

class MyOutOfRange : public exception{
public:
    MyOutOfRange(char* error){
        pError = new char[strlen(error) + 1];
        strcpy(pError, error);
    }
    ~MyOutOfRange(){
        if (pError != NULL){
            delete[] pError;
        }
    }
//    virtual const char* what() const{ // ����
//        return pError;
//    };
    // ���쳣���ǵ���
//    const char *what() const noexcept override{
//        return pError;
//    }
    virtual const char *what() const throw(){
        return pError;
    }
public:
    char* pError;
};

void func02(){
    throw MyOutOfRange("My out_of_range");
}

void test02(){
    // �����Լ���д���쳣out_of_range
    try{
        func02();
    }
    catch (exception &e){
        cout << e.what() << endl;
    }
}
//*******************************
// �쳣����
class BaseMyException{
public:
    virtual void what() = 0;
    virtual ~BaseMyException(){}
};

class TargetSpaceNullException : public BaseMyException{
public:
    virtual void what() {
        cout << "Ŀ��ռ�Ϊ��!" << endl;
    }
    ~TargetSpaceNullException(){}
};

class SourceSpaceNullException : public BaseMyException{
public:
    virtual void what() {
        cout << "Դ�ռ�Ϊ��!" << endl;
    }
    ~SourceSpaceNullException(){};
};

void copyStr(char* taget, char* source){
    if (taget == NULL) {
        throw TargetSpaceNullException();
    }
    if (source == NULL) {
        throw SourceSpaceNullException();
    }

    int len = strlen(source) + 1;
    while(*source != '\0'){
        *taget = *source;
        taget++;
        source++;
    }
}
void test03(){
    char* source = "abcdef";
    char buf[1024];

    try {
        copyStr(NULL, source);
    }
    catch (BaseMyException& ex){
        ex.what();
    }
    cout << buf << endl;
}

int main() {
//    test01();
//    test02();
    test03();
}