#include "Mediator-17.h"
#include "Country-17.h"
#include <iostream>

void MediatorOrg::addMember(Country* country)
{
    country->setMediator(this);
    m_countryMap.insert(make_pair(country->getName(), country));
}

void WorldGovt::declare(string msg, Country* country, string name)
{
    if (m_countryMap.find(name) != m_countryMap.end())
    {
        string str = msg + "������: " + country->getName() + "��";
        m_countryMap[name]->setMessage(str);
    }
}

void GeMingArmy::declare(string msg, Country* country, string name)
{
    string str = msg + "������: " + country->getName() + "��";
    for (const auto& item : m_countryMap)
    {
        if (item.second == country)
        {
            continue;
        }
        item.second->setMessage(str);
    }
}

#if 0
int main()
{
    // ��������
    WorldGovt* world = new WorldGovt;
    // ���˹�����
    Alabasta* alaba = new Alabasta;
    Dressrosa* dress = new Dressrosa;

    world->addMember(alaba);
    world->addMember(dress);

    alaba->declare("����˹������������, ����ҹ��������, �������˵��!!!", dress->getName());
    dress->declare("�����˶����Ҷล������������, �����ϼ�, ��!!!", alaba->getName());

    // ������
    GeMingArmy* geming = new GeMingArmy;
    // ���˹�����
    Lulusia* lulu = new Lulusia;
    Kamabaka* kama = new Kamabaka;

    geming->addMember(lulu);
    geming->addMember(kama);

    lulu->declare("�Ҳ�, �ҵĹ��ұ���ķ������!!!");

    delete world;
    delete geming;
    delete alaba;
    delete dress;
    delete kama;
    delete lulu;

    return 0;
}
#endif