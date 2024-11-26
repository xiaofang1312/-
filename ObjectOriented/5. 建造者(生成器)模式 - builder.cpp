#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
* 1. ���崬��ص���
* 2. ������������ص���
* 3. �������� -> ���첻ͬ���Ĵ�
* 4. ��д���Դ���
*/
// ����ɣ��ŵĴ�
// �洢�Ѿ�����õ��㲿��
class SunnyShip
{
public:
    void addParts(string name)
    {
        m_parts.push_back(name);
    }
    void showParts()
    {
        for (const auto& item : m_parts)
        {
            cout << item << "  ";
        }
        cout << endl;
    }
private:
    vector<string> m_parts;
};

// ����÷���ŵĴ�
class MerryShip
{
public:
    void assemble(string name, string parts)
    {
        m_parts.insert(make_pair(parts, name));
    }
    void showParts()
    {
        for (const auto& item : m_parts)
        {
            cout << item.first << ":" <<item.second;
        }
        cout << endl;
    }
private:
    map<string, string> m_parts;
};

// ������������ - 3
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
    void reset() override
    {
        m_sunny = new SunnyShip;
    }
    SunnyShip* getSunnyShip()
    {
        SunnyShip* ship = m_sunny;
        m_sunny = nullptr;
        return ship;
    }
    void buildBody() override
    {
        m_sunny->addParts("�����������ǵ�");
    }
    void buildWeapon() override
    {
        m_sunny->addParts("ʨ����");
    }
    void buildEngine() override
    {
        m_sunny->addParts("������������ȼ��");
    }
    void buildInterior() override
    {
        m_sunny->addParts("�ǳ�����������װ��");
    }
    ~SunnyBuilder() 
    {
        if (m_sunny)
        {
            delete m_sunny;
        }
    }
private:
    SunnyShip* m_sunny;
};

class MerryBuilder : public ShipBuilder
{
public:
    MerryBuilder()
    {
        reset();
    }
    void reset() override
    {
        m_merry = new MerryShip;
    }
    MerryShip* getMerryShip()
    {
        MerryShip* ship = m_merry;
        m_merry = nullptr;
        return ship;
    }
    void buildBody() override
    {
        m_merry->assemble("����������ľ��", "����");
    }
    void buildWeapon() override
    {
        m_merry->assemble("��ͨ�����Ŵ���", "����ϵͳ");
    }
    void buildEngine() override
    {
        m_merry->assemble("��ú��������", "����ϵͳ");
    }
    void buildInterior() override
    {
        m_merry->assemble("�ǳ�����������װ��", "����");
    }
    ~MerryBuilder()
    {
        if (m_merry)
        {
            delete m_merry;
        }
    }
private:
    MerryShip* m_merry;
};

// ���������
class Director
{
public:
    void setBuilder(ShipBuilder* builder)
    {
        m_builder = builder;
    }

    // ��Լ��
    void buildSimpleShip()
    {
        m_builder->buildBody();
        m_builder->buildEngine();
    }
    // ��׼��
    void buildStandardShip()
    {
        buildSimpleShip();
        m_builder->buildWeapon();
    }

    // ������
    void buildRegalShip()
    {
        buildStandardShip();
        m_builder->buildInterior();
    }

private:
    ShipBuilder* m_builder = nullptr;
};

// ���Դ���
// ����ɣ���
void buildSunnyShip()
{
    Director* director = new Director;
    SunnyBuilder* builder = new SunnyBuilder;

    // ��Լ��
    director->setBuilder(builder);
    director->buildSimpleShip();
    SunnyShip* ship = builder->getSunnyShip();
    ship->showParts();
    delete ship;

    // ��׼��
    builder->reset();
    director->buildStandardShip();
    ship = builder->getSunnyShip();
    ship->showParts();
    delete ship;

    // ������
    builder->reset();
    director->buildRegalShip();
    ship = builder->getSunnyShip();
    ship->showParts();
    delete ship;
    delete builder;
    delete director;
}

// ����÷����
// ����ɣ���
void buildMerryShip()
{
    Director* director = new Director;
    MerryBuilder* builder = new MerryBuilder;

    // ��Լ��
    director->setBuilder(builder);
    director->buildSimpleShip();
    MerryShip* ship = builder->getMerryShip();
    ship->showParts();
    delete ship;

    // ��׼��
    builder->reset();
    director->buildStandardShip();
    ship = builder->getMerryShip();
    ship->showParts();
    delete ship;

    // ������
    builder->reset();
    director->buildRegalShip();
    ship = builder->getMerryShip();
    ship->showParts();
    delete ship;
    delete builder;
    delete director;
}

#if 0
int main()
{
    buildMerryShip();
    cout << "===============================" << endl;
    buildSunnyShip();
    return 0;
}
#endif