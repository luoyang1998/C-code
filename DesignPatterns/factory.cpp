#include <iostream>

// 工厂模式实现 - 人造恶魔果实

using namespace std;

class AbstrsctSmile{
public:
    virtual void transform() = 0; // 纯虚函数 必须重写
    virtual void ability() = 0;
    virtual ~AbstrsctSmile() {} // 出现继承并实现多态的情况下 需要虚析构
};

class SheepSmile : public AbstrsctSmile{
public:
    void transform() override{  // override检查重写名字是否正确
    }
    void ability() override{
    }
};
class LionSmile : public AbstrsctSmile{
public:
    void transform() override{
    }
    void ability() override{
    }
};
class BatSmile : public AbstrsctSmile{
public:
    void transform() override{
    }
    void ability() override{
    }
};

// 定义工厂类 - 父类
class AbstractFactory{
public:
    virtual AbstrsctSmile* createSmile() = 0;
    virtual ~AbstractFactory() {}
};
// 生产山羊的恶魔果实
class SheepFactory : public AbstractFactory{
public:
    AbstrsctSmile* createSmile() {
        return new SheepSmile;
    };
    ~SheepFactory() {
        cout << "SheepFactory 被析构了。。。" << endl;
    }
};
class LionFactory : public AbstractFactory{
public:
    AbstrsctSmile* createSmile() {
        return new LionSmile;
    };
    ~LionFactory() {
        cout << "LionFactory 被析构了。。。" << endl;
    }
};
class BatFactory : public AbstractFactory{
public:
    AbstrsctSmile* createSmile() {
        return new BatSmile;
    };
    ~BatFactory() {
        cout << "BatFactory 被析构了。。。" << endl;
    }
};

int main(){
    AbstractFactory* factory = new LionFactory;
    AbstrsctSmile* obj = factory->createSmile();
    obj->transform();
    obj->ability();
    delete obj;
    delete factory;
}