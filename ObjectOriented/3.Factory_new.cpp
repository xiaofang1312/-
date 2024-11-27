#include <iostream>
#include <memory>
using namespace::std;

class AbstractSmile
{
public:
    virtual void transform() = 0;
    virtual void ability() = 0;
    virtual ~AbstractSmile() {}
};

class Sheep: public AbstractSmile
{
public:
    virtual void transform() override
    {
        cout<<"羊果实"<<endl;
    }
    virtual void ability() override
    {
        cout<<"羊的能力"<<endl;
    }   
};

class Lion: public AbstractSmile
{
public:
    virtual void transform() override
    {
        cout<<"狮子果实"<<endl;
    }
    virtual void ability() override
    {
        cout<<"狮子的能力"<<endl;
    }   
};

class Factory
{
public:
    virtual AbstractSmile* creat() {}
    virtual ~Factory() {}
};

class SheepFactory : public Factory
{
    AbstractSmile* creat() override
    {
        return new Sheep;
    }
};

class LionFactory : public Factory
{
    AbstractSmile* creat() override
    {
        return new Lion;
    }
};

int main()
{
    Factory* factory = new SheepFactory;
    AbstractSmile* smile = factory->creat();
    smile->transform();
    smile->ability();
    delete factory;
    delete smile;
}