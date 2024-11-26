#pragma once
#include <string>
#include <list>
using namespace std;

class Observer;
// �����߻���
class NewsAgency
{
public:
    // ��Ӷ�����
    void attach(Observer* ob);
    // ɾ��������
    void detach(Observer* ob);
    // ֪ͨ������
    virtual void notify(string msg) = 0;
    virtual ~NewsAgency() {}
protected:
    list<Observer*> m_list;
};

// ���������� - Ħ��˹
class Morgans : public NewsAgency
{
public:
    // ֪ͨ������
    void notify(string msg) override;
};

// ���������� - ����������
class Gossip : public NewsAgency
{
public:
    // ֪ͨ������
    void notify(string msg) override;
};