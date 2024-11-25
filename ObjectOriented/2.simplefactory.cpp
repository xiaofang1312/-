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

//定义工厂类
enum class Type:char{Sheep,Lion,Bat};
class SmileFactory
{
public:
    AbstractSmile* createSmile(Type type)
    {
        AbstractSmile* ptr;
        switch(type)
        {
            case Type::Sheep:
                ptr = new SheepSmile;
                break;
            case Type::Lion:
                ptr = new LionSmile;
                break;
            case Type::Bat:
                ptr = new BatSmile;
                break;    
            default:
                break;
        }
        return ptr;
    }
};
int main()
{
    SmileFactory* factory = new SmileFactory;
    AbstractSmile* obj = factory->createSmile(Type::Bat);
    obj->transform();
    obj->ability();
    delete obj;
    delete factory;
    return 0;
}