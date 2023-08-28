#include <iostream>

// 抽象工厂 - 造船
using namespace std;

// 船体
class ShipBody{
public:
    virtual string getBody() = 0;
    virtual ~ShipBody(){}
};
// 三种船体
class WoodBody : public ShipBody {
public:
    string getBody() override{}
};
class IronBody : public ShipBody {
public:
    string getBody() override{}
};
class MetalBody : public ShipBody {
public:
    string getBody() override{}
};

// 引擎
class Engine{
public:
    virtual string getEngine() = 0;
    virtual ~Engine(){}
};
// 三种引擎
class Human : public Engine{
public:
    string getEngine() override{}
};
class Diesel : public Engine{
public:
    string getEngine() override{}
};
class Nuclear : public Engine{
public:
    string getEngine() override{}
};

// 武器
class Weapon{
public:
    virtual string getWeapon(){}
    virtual ~Weapon(){}
};
//
class Gun : public Weapon{
public:
    string getWeapon() override {}
};
class Cannon : public Weapon{
public:
    string getWeapon() override {}
};
class Laser : public Weapon{
public:
    string getWeapon() override {}
};

// 船
class Ship{
public:
    Ship(ShipBody* body, Engine* engine, Weapon* weapon) :
        m_body(body), m_engine(engine), m_weapon(weapon){ }
    ~Ship(){
        delete m_body;
        delete m_engine;
        delete m_weapon;
    }
    string getProperty(){
        string info = m_body->getBody()+m_engine->getEngine()+m_weapon->getWeapon();
        return info;
    }
private:
    ShipBody* m_body;
    Engine* m_engine;
    Weapon* m_weapon;
};

// 工厂类 - 抽象工厂
class AbstractFactory{
public:
    virtual Ship* createShip() = 0;
    virtual ~AbstractFactory(){}
};
class BasicFactory : public AbstractFactory{
public:
    Ship * createShip() override{
        Ship* ship = new Ship(new WoodBody, new Human, new Gun);
        return ship;
    }
};
class StandFactory : public AbstractFactory{
public:
    Ship * createShip() override{
        Ship* ship = new Ship(new IronBody, new Diesel, new Cannon);
        return ship;
    }
};
class UltimataFactory : public AbstractFactory{
public:
    Ship * createShip() override{
        Ship* ship = new Ship(new MetalBody, new Nuclear, new Laser);
        return ship;
    }
};
int main(){
    // 下单为旗舰型
    AbstractFactory* factory = new UltimataFactory;
    Ship* ship = factory->createShip();
    ship->getProperty();

    delete ship;
    delete factory;

}