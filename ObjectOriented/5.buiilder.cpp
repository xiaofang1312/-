#include <iostream>
#include <vector>
#include <map>
using namespace::std;

class Sunneyship
{
public:
    void addParts(string name)
    {
        m_parts.push_back(name);
    }
    void showParts()
    {
        for(const auto& ch:m_parts)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
private:
    vector<string> m_parts;
};

class Merryship
{
public:
    void assemble(string name,string parts)
    {
        m_parts.insert(make_pair(name,parts));
    }
    void showParts()
    {
        for(const auto& item:m_parts)
        {
            cout<<item.first<<" "<<item.second<<" ";
        }
        cout<<endl;
    }
private:
    map<string,string> m_parts;
};

class ShipBuilder
{
public:
    virtual void reset() = 0;
    virtual void buildBody() = 0;
    virtual void buildWeapon() = 0;
    virtual void buildEngine() = 0;
    virtual void buildInterior() = 0;
    virtual ~ShipBuilder() {}
};


class SunnyBuilder : public ShipBuilder
{
public:
    SunnyBuilder()
    {
        reset();
    }
    ~SunnyBuilder()
    {
        if(m_sunny != nullptr)
        {
            delete m_sunny;
            m_sunny = nullptr;
        }
    }
    void reset() override 
    {
        m_sunny = new Sunneyship;
    }
    virtual void buildBody() override 
    {
        m_sunny->addParts("树干");
    }
    virtual void buildWeapon() override 
    {
        m_sunny->addParts("狮吼炮");
    }
    virtual void buildEngine() override 
    {
        m_sunny->addParts("可乐驱动");
    }
    virtual void buildInterior() override 
    {
        m_sunny->addParts("豪华内室精装");
    }

    Sunneyship* getSunny()
    {
        //直接返回m_sunny,m_sunny无法置为nullptr
        Sunneyship* ship = m_sunny;
        m_sunny = nullptr;
        return ship;    
    }

private:
    Sunneyship* m_sunny = nullptr;
};


class MerryBuilder : public ShipBuilder
{
public:
    MerryBuilder()
    {
        reset();
    }
    ~MerryBuilder()
    {
        if(m_merry != nullptr)
        {
            delete m_merry;
            m_merry = nullptr;
        }
    }
    void reset() override 
    {
        m_merry = new Merryship;
    }
    virtual void buildBody() override 
    {
        m_merry->assemble("树干","优质树干");
    }
    virtual void buildWeapon() override 
    {
        m_merry->assemble("狮吼炮","四门大炮");
    }
    virtual void buildEngine() override 
    {
        m_merry->assemble("可乐驱动","蒸汽机");
    }
    virtual void buildInterior() override 
    {
        m_merry->assemble("豪华内室精装","精装修");
    }

    Merryship* getmerry()
    {
        Merryship* ship = m_merry;
        m_merry = nullptr;
        return ship;    
    }

private:
    Merryship* m_merry = nullptr;
};

// 主管类
class Director
{
public:
    void setBuilder(ShipBuilder* builder)
    {
        m_builder = builder;
    }
    // 简约型
    void builderSimpleShip()
    {
        m_builder->buildBody();
        m_builder->buildEngine();
    }
    // 标准型
    void builderStandardShip()
    {
        builderSimpleShip();
        m_builder->buildWeapon();
    }
    // 豪华型
    void builderRegalShip()
    {
        builderStandardShip();
        m_builder->buildInterior();
    }
private:
    ShipBuilder* m_builder = nullptr;
};

// 建造桑尼号
void builderSunny()
{
    Director* director = new Director();
    SunnyBuilder* sunnybuilder = new SunnyBuilder();
    //简约型    
    director->setBuilder(sunnybuilder); //直接赋值？
    director->builderSimpleShip();
    Sunneyship* sunny = sunnybuilder->getSunny();
    sunny->showParts();
    delete sunny;
    //sunny = nullptr;


    
    //标准型
    sunnybuilder->reset();
    director->setBuilder(sunnybuilder);
    director->builderStandardShip();
    sunny = sunnybuilder->getSunny();
    sunny->showParts();
    delete sunny;
    
}

// 建造梅利号
void builderMerry()
{
    Director* director = new Director;
    MerryBuilder* builder = new MerryBuilder;
    // 简约型
    director->setBuilder(builder);
    director->builderSimpleShip();
    Merryship* merry = builder->getmerry();
    merry->showParts();
    delete merry;

    // 标准型
    builder->reset();
    director->setBuilder(builder);
    director->builderStandardShip();
    merry = builder->getmerry();
    merry->showParts();
    delete merry;

    // 豪华型
    builder->reset();
    director->setBuilder(builder);
    director->builderRegalShip();
    merry = builder->getmerry();
    merry->showParts();
    delete merry;
    delete builder;
    delete director;
}

int main()
{
    builderSunny();
    cout << "=====================================" << endl;
    builderMerry();
}

