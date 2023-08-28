#include <iostream>

// 简单工厂模式实现 - 人造恶魔果实

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

// 定义工厂类 - 简单工厂模式中 工厂类有且只有一个
enum class Type:char {Sheep, Lion, Bat};
class SmileFactory{
public:
    AbstrsctSmile* createSmile(Type type){
        AbstrsctSmile* ptr = nullptr;
        switch (type){
            case Type::Sheep:
                ptr = new SheepSmile;
            case Type::Lion:
                ptr = new LionSmile;
            case Type::Bat:
                ptr = new BatSmile;
            default:
                break;
        }
        return ptr;
    }

};

int main(){
    SmileFactory* factory = new SmileFactory;
    AbstrsctSmile* obj = factory->createSmile(Type::Lion);
    obj->transform();
    obj->ability();
}