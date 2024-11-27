#include <iostream>
#include <memory>
using namespace::std;


enum class Fruittype :char {SheepFruit,LionFruit};

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

class SimleFactory
{
public:
    static AbstractSmile* creat(Fruittype obj)
    {
        AbstractSmile* Smileptr = nullptr;
        switch(obj)
        {
            case Fruittype::SheepFruit:
                Smileptr = new Sheep();
                break;
            case Fruittype::LionFruit:
                Smileptr = new Lion();
                break;
            default:
                break;
        }
        return Smileptr;
    }
};

int main()
{
    //SimleFactory* factory = new SimleFactory;
    AbstractSmile* smile = SimleFactory::creat(Fruittype::LionFruit);
    smile->transform();
    smile->ability();
    //delete factory;
    delete smile;
}