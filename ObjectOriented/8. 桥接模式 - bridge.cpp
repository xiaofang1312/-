#include <iostream>
#include <map>
using namespace std;

/*
* ����: �Ժ��������е� ������ �� ���� ͨ���Ž�ģʽ���й���
*/
// ��Ա��Ӧ����
struct Person
{
    Person(string name, string job, string ability, string reward, string beizhu)
    {
        this->name = name;
        this->job = job;
        this->ability = ability;
        this->reward = reward;
        this->beizhu = beizhu;
    }
    ~Person()
    {
        cout << name << "��������..." << endl;
    }
    string name;
    string job;
    string ability;
    string reward;
    string beizhu;
};
// ����ʵ�ֲ��� - �Ŷ�
class AbstractTeam
{
public:
    AbstractTeam(string name) : m_name(name) {}
    string getTeamName()
    {
        return m_name;
    }
    void addMember(Person* p)
    {
        m_teamMap.insert(make_pair(p->name, p));
    }
    void show()
    {
        cout << m_name << ": " << endl;
        for (const auto& item : m_teamMap)
        {
            cout << "��name: " << item.second->name
                << "��job: " << item.second->job
                << "��ability: " << item.second->ability
                << "��reward: " << item.second->reward
                << "��beizhu: " << item.second->beizhu
                << "��" << endl;
        }
    }
    virtual ~AbstractTeam()
    {
        for (const auto& item : m_teamMap)
        {
            delete item.second;
        }
    }
    virtual void executeTask() = 0;
protected:
    string m_name;
    map<string, Person*> m_teamMap;
};

// ��ñ
class CaoMaoTeam : public AbstractTeam
{
public:
    using AbstractTeam::AbstractTeam;
    void executeTask() override
    {
        cout << "�ں���ð�գ��ҵ� ONE PIECE ��Ϊ��������" << endl;
    }
    ~CaoMaoTeam()
    {
        cout << "��ñ�����ű�����..." << endl;
    }
};

// ����
class SmokerTeam : public AbstractTeam
{
public:
    using AbstractTeam::AbstractTeam;
    void executeTask() override
    {
        cout << "Ϊ������, �Ƚ���ñһ����!!!" << endl;
    }
    ~SmokerTeam()
    {
        cout << "˹Ħ��ĺ���������..." << endl;
    }
};
// ������󲿷� - ��
class AbstractShip
{
public:
    AbstractShip(AbstractTeam* team) : m_team(team) {}
    void show()
    {
        m_team->show();
        m_team->executeTask();
    }
    virtual string getName() = 0;
    virtual void feature() = 0;
protected:
    AbstractTeam* m_team;
};

class Merry : public AbstractShip
{
public:
    using AbstractShip::AbstractShip;
    string getName() override
    {
        return "ǰ�� - ÷����";
    }
    void feature() override
    {
        cout << getName()
            << " -- ����Ϊ��ͷ, ����������˾�����Ἲ�����˲�ñһ�" << endl;
    }
};

class HaiJunShip : public AbstractShip
{
public:
    using AbstractShip::AbstractShip;
    string getName() override
    {
        return "�޵к�����";
    }
    void feature() override
    {
        cout << getName() << " -- �����ɺ�¥ʯ����, ���Դ����޷���ľ޴��ڽ�!" << endl;
    }
};

#if 0
int main()
{
    AbstractTeam* team = new CaoMaoTeam("��ñ������");
    Person* luffy = new Person("·��", "����", "�𽺹�ʵ������", "30�ڱ���", "������");
    Person* zoro = new Person("��¡", "��ʿ", "������", "11��1100����", "·��");
    Person* sanji = new Person("ɽ��", "��ʦ", "���κ�", "10��3200����", "��ɫ");
    Person* nami = new Person("����", "����ʿ", "����+��˹", "3��6600����", "ϲ��Ǯ");
    team->addMember(luffy);
    team->addMember(zoro);
    team->addMember(sanji);
    team->addMember(nami);

    AbstractShip* ship = new Merry(team);
    ship->show();
    ship->feature();
    delete team;
    delete ship;
    cout << "=======================" << endl;
    // ˹Ħ��Ĵ���
    team = new SmokerTeam("˹Ħ��ĺ�������");
    Person* smoker = new Person("˹Ħ��", "�н�", "ð�̹�ʵ������", "", "������Ѭ����");
    Person* dasiqi = new Person("��˹��", "����", "һ����", "", "����");
    team->addMember(smoker);
    team->addMember(dasiqi);
    ship = new HaiJunShip(team);
    ship->feature();
    ship->show();
    delete team;
    delete ship;

    return 0;
}
#endif