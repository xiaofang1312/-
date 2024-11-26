#include "NewsAgency-19.h"
#include "Observer-19.h"
#include <iostream>
using namespace std;

void NewsAgency::attach(Observer* ob)
{
    m_list.push_back(ob);
}

void NewsAgency::detach(Observer* ob)
{
    m_list.remove(ob);
}

void Morgans::notify(string msg)
{
    cout << "Ħ��˹�����籨ֽ�Ķ�����һ����<" << m_list.size() << ">��" << endl;
    for (const auto& item : m_list)
    {
        // ͨ���۲��߸�������
        item->update(msg);
    }
}

void Gossip::notify(string msg)
{
    cout << "���������籨ֽ�Ķ�����һ����<" << m_list.size() << ">��" << endl;
    for (const auto& item : m_list)
    {
        // ͨ���۲��߸�������
        item->update(msg);
    }
}
