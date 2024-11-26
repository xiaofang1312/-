#include "Visitor-23.h"
#include "Member-23.h"
#include <iostream>
#include <list>
#include <vector>
using namespace std;

void Anger::maleDoing(MaleMember* male)
{
    cout << "���ǲ�ñ�����ŵ�" << male->getName() << endl;
    fight();
}

void Anger::fight()
{
    cout << "ֻҪ�����ž͵ø���һ�Ѫս����!!!" << endl;
}

void Anger::femaleDoing(FemaleMember* female)
{
    cout << "���ǲ�ñ�����ŵ�" << female->getName() << endl;
    warning();
}

void Anger::warning()
{
    cout << "��ҿ��ӣ��ҿ춥��ס��, ��Ҫ����!!!" << endl;
}

void Horror::maleDoing(MaleMember* male)
{
    cout << "���ǲ�ñ�����ŵ�" << male->getName() << endl;
    thinking();
}

void Horror::thinking()
{
    cout << "�ø���ͬ����һ�鹥������һ�, ��Ȼ�����򲻹�ѽ!!!" << endl;
}

void Horror::femaleDoing(FemaleMember* female)
{
    cout << "���ǲ�ñ�����ŵ�" << female->getName() << endl;
    help();
}

void Horror::help()
{
    cout << "�������̫����, ̫������, ��Ⱦ��ҡ�����" << endl;
}

// ����һ�����ڲ��Ե���
class CaoMaoTeam
{
public:
    CaoMaoTeam()
    {
        m_actions.push_back(new Anger);
        m_actions.push_back(new Horror);
    }
    void add(AbstractMember* member)
    {
        m_members.push_back(member);
    }
    void remove(AbstractMember* member)
    {
        m_members.remove(member);
    }
    void display()
    {
        for (const auto& item : m_members)
        {
            int index = rand() % 2;
            item->accept(m_actions.at(index));
        }
    }
    ~CaoMaoTeam()
    {
        for (const auto& item : m_members)
        {
            delete item;
        }
        for (const auto& item : m_actions)
        {
            delete item;
        }
    }
private:
    list<AbstractMember*> m_members;
    vector<AbstractAction*> m_actions;
};

int main()
{
    srand(time(NULL));
    vector<string> names{
    "·��", "��¡","ɽ��", "�ǰ�", "������", "������", "��³��"
    };
    CaoMaoTeam* team = new CaoMaoTeam;
    for (const auto& item : names)
    {
        team->add(new MaleMember(item));
    }
    team->add(new FemaleMember("����"));
    team->add(new FemaleMember("�ޱ�"));

    team->display();

    delete team;

    return 0;
}

