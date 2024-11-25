#include<iostream>

using namespace::std;

class ShipBody
{
public:
    virtual string getShipBody() = 0;
    virtual ~ShipBody() {}
};

class WoodBody : public ShipBody
{
public:
    string getShipBody() override
    {
        return string("用木头制作");
    }
};

class IronBody : public ShipBody
{
public:
    string getShipBody() override
    {
        return string("用钢铁制作");
    }
};

class MatalBody : public ShipBody
{
public:
    string getShipBody() override
    {
        return string("用合金制作");
    }
};

class Engine
{
public:
    virtual string getEngine() = 0;
    virtual ~Engine() {}
};

class Human : public Engine
{
public:
    string getEngine() override
    {
        return string("使用<人力驱动>...");
    }
};

class Diesel : public Engine
{
public:
    string getEngine() override
    {
        return string("使用<内燃机驱动>...");
    }
};

class Nuclear : public Engine
{
public:
    string getEngine() override
    {
        return string("使用<核能驱动>...");
    }
};

// 武器
class Weapon
{
public:
    virtual string getWeapon() = 0;
    virtual ~Weapon() {}
};

class Gun : public Weapon
{
public:
    string getWeapon() override
    {
        return string("配备的武器是<枪>");
    }
};

class Cannon : public Weapon
{
public:
    string getWeapon() override
    {
        return string("配备的武器是<自动机关炮>");
    }
};

class Laser : public Weapon
{
public:
    string getWeapon() override
    {
        return string("配备的武器是<激光>");
    }
};

class Ship
{
public:
    Ship(ShipBody* body,Weapon* weapon,Engine* engine):m_body(body),m_weapon(weapon),m_engine(engine)
    {        
    }
    string getProperty()
    {
        string info = m_body->getShipBody() + m_weapon->getWeapon() + m_engine->getEngine();
        return info;        
    }
    ~Ship()
    {
        delete m_body;
        delete m_engine;
        delete m_weapon;
    }
private:
    ShipBody* m_body = nullptr;
    Engine* m_engine = nullptr;
    Weapon* m_weapon = nullptr;
};

class AbstractFactory
{
public:
    virtual Ship* createShip() = 0;
    virtual ~AbstractFactory() {}
};

class BasicFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new WoodBody, new Gun, new Human);
        cout << "<基础型>战船生产完毕, 可以下水啦..." << endl;
        return ship;
    }
};

class StandardFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new IronBody, new Cannon, new Diesel);
        cout << "<标准型>战船生产完毕, 可以下水啦..." << endl;
        return ship;
    }
};

class UltimateFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new MatalBody, new Laser, new Nuclear);
        cout << "<旗舰型>战船生产完毕, 可以下水啦..." << endl;
        return ship;
    }
};

int main()
{
    AbstractFactory* factory = new UltimateFactory;
    Ship* ship = factory->createShip();
    cout<<ship->getProperty()<<endl;
    delete ship;
    delete factory;
    return 0;
}