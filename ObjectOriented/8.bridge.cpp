#include<iostream>
#include<map>
using namespace::std;

class Person
{
public:
    string m_name,m_job,m_ability,m_reward,m_beizhu;
    Person(string name,string job,string ability,string reward,string beizhu):m_name(name),m_job(job),m_ability(ability),m_reward(reward),m_beizhu(beizhu) {}
    ~Person()
    {
        cout<<"析构person"<<endl;
    }
};

class AbstractTeam
{
public:
    AbstractTeam(string name):m_teamname(name){}
    virtual string getTeamName()
    {
        return m_teamname;
    }

    void addMember(Person* p)
    {
        m_infoMap.insert(make_pair(p->m_name,p));
    }

    void show()
    {
        cout << m_teamname << ": " << endl;
        for (const auto& item : m_infoMap)
        {
            cout << "【Name: " << item.second->m_name
                << ", Job: " << item.second->m_job
                << ", Ability: " << item.second->m_ability
                << ", MoneyReward: " << item.second->m_reward
                << ", BeiZhu: " << item.second->m_beizhu 
                << "】" << endl;
        }
    }

    virtual void executeTeam() = 0;

    virtual ~AbstractTeam()
    {
        for (const auto& item : m_infoMap)
        {
            delete item.second;
        }
    }
private:
    string m_teamname;
    map<string,Person*> m_infoMap;
};

class CaoMaoTeam : public AbstractTeam
{
public:
    using AbstractTeam::AbstractTeam;
    void executeTeam() override
    {
         cout << "在海上冒险，找到 ONE PIECE 成为海贼王！" << endl;
    }
};

class SmokerTeam : public AbstractTeam
{
    using AbstractTeam::AbstractTeam;
public:
    void executeTeam()
    {
        cout << "为了正义, 先将草帽一伙一网打尽!!!" << endl;
    }
};

class AbstractShip
{
public:
    AbstractShip(AbstractTeam* team): m_team(team) {}
    void showTeam()
    {
        m_team->show();
        m_team->executeTeam();
    }
    virtual string getname() = 0;
    virtual void feature() = 0;
    virtual ~AbstractShip() {}
protected:
    AbstractTeam* m_team = nullptr;
};

class MerryShip : public AbstractShip
{
public:
    using AbstractShip::AbstractShip;
    string getname() override
    {
        return string("前进·梅利号");
    }
    void feature() override
    {
        cout << getname()
            << " -- 船首为羊头, 在司法岛化身船精灵舍己救下了草帽一伙！" << endl;
    }
};

class SunnyShip : public AbstractShip
{
public:
    string getname() override
    {
        return string("无敌海军号");
    }
    void feature() override
    {
         cout << getname() << " -- 船底由海楼石建造, 可以穿过无风带的巨大炮舰!" << endl;
    }
};




int main()
{
    AbstractTeam* caomao = new CaoMaoTeam("草帽海贼团");
    //AbstractShip* ship = new MerryShip(caomao);
    Person* luffy = new Person("路飞", "船长", "橡胶果实能力者", "30亿贝里", "爱吃肉");
    Person* zoro = new Person("索隆", "剑士", "三刀流", "11亿1100万贝里", "路痴");
    Person* sanji = new Person("山治", "厨师", "隐形黑", "10亿3200万贝里", "好色");
    Person* nami = new Person("娜美", "航海士", "天候棒+宙斯", "3亿6600万贝里", "喜欢钱");
    caomao->addMember(luffy);
    caomao->addMember(zoro);
    caomao->addMember(sanji);
    caomao->addMember(nami);
    AbstractShip* ship = new MerryShip(caomao);
    ship->feature();
    ship->showTeam();
    delete caomao;
    delete ship;
    return 0;
}