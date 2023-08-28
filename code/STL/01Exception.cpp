#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>

using namespace std;
/*
 * 1. C++标准库异常
 * 2. 继承在异常中的应用
 */

class Person{
public:
    Person(){
        mAge = 0;
    }
    void setAge(int age) {
        if (age < 0 || age > 100) {
            throw out_of_range("年龄应该在0-100之间");
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
        // what()返回C风格字符串  const char* 或 string
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
//    virtual const char* what() const{ // 有误
//        return pError;
//    };
    // 非异常覆盖调用
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
    // 调用自己编写的异常out_of_range
    try{
        func02();
    }
    catch (exception &e){
        cout << e.what() << endl;
    }
}
//*******************************
// 异常基类
class BaseMyException{
public:
    virtual void what() = 0;
    virtual ~BaseMyException(){}
};

class TargetSpaceNullException : public BaseMyException{
public:
    virtual void what() {
        cout << "目标空间为空!" << endl;
    }
    ~TargetSpaceNullException(){}
};

class SourceSpaceNullException : public BaseMyException{
public:
    virtual void what() {
        cout << "源空间为空!" << endl;
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