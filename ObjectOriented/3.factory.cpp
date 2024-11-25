#include <iostream>

using namespace::std;

//产品类的父类
class AbstractSmile
{
public:
    virtual void transform() = 0;
    virtual void ability() = 0;
    virtual ~AbstractSmile(){}
private:
};

class SheepSmile:public AbstractSmile
{
public:
    void transform() override
    {
        cout<<"变成山羊"<<endl;
    }
    void ability() override
    {
        cout<<"山羊能力"<<endl;
    }
};
class LionSmile:public AbstractSmile
{
public:
    void transform() override
    {
        cout<<"变成狮子"<<endl;
    }
    void ability() override
    {
        cout<<"狮子能力"<<endl;
    }
};
class BatSmile:public AbstractSmile
{
public:
    void transform() override
    {
        cout<<"变成蝙蝠"<<endl;
    }
    void ability() override
    {
        cout<<"蝙蝠能力"<<endl;
    }
};

//定义工厂类父类
class AbstractFactory
{
public:
    virtual AbstractSmile* createSmile() = 0;
    virtual ~AbstractFactory() {}
};

//子类工厂
class SheepFactory : public AbstractFactory
{
public:
    AbstractSmile* createSmile() override
    {
        return new SheepSmile;
    }

    ~SheepFactory()
    {
        cout<<"析构了山羊子类"<<endl;
    }

};
class LionFactory : public AbstractFactory
{
public:
    AbstractSmile* createSmile() override
    {
        return new LionSmile;
    }

    ~LionFactory()
    {
        cout<<"析构了狮子子类"<<endl;
    }

};
class BatFactory : public AbstractFactory
{
public:
    AbstractSmile* createSmile() override
    {
        return new BatSmile;
    }

    ~BatFactory()
    {
        cout<<"析构了蝙蝠子类"<<endl;
    }

};

int main()
{
    AbstractFactory* factory = new SheepFactory;
    AbstractSmile* obj = factory->createSmile();
    obj->transform();
    obj->ability();
    delete obj;
    delete factory;
    return 0;
}