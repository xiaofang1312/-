#pragma once
#include <string>
#include <iostream>
#include "NewsAgency-19.h"
using namespace std;

// ����Ĺ۲�����
class Observer
{
public:
    // �ͷ����߽��й��� - ����ͨ�����캯��ʵ��
    Observer(NewsAgency* news, string name) : m_name(name), m_news(news)
    {
        m_news->attach(this);
    }
    // �ͷ����߽������ - ȡ������
    void unsubscribe()
    {
        m_news->detach(this);
    }
    // ������Ϣ
    virtual void update(string msg) = 0;
    virtual ~Observer() {}
protected:
    NewsAgency* m_news; 
    string m_name;
};

// �۲��������� - ��
class Dragon : public Observer
{
public:
    using Observer::Observer;
    // ������Ϣ
    void update(string msg) override
    {
        cout << "@@@·�ɵ��ϰָ��������յ���Ϣ: " << msg << endl;
    }
};

// �۲��������� - ���˹
class Shanks : public Observer
{
public:
    using Observer::Observer;
    // ������Ϣ
    void update(string msg) override
    {
        cout << "@@@·�ɵ���·�˺췢���˹�յ���Ϣ: " << msg << endl;
    }
};

// �۲��������� - �������װ�
class Bartolomeo : public Observer
{
public:
    using Observer::Observer;
    // ������Ϣ
    void update(string msg) override
    {
        cout << "@@@·�ɵ�ͷ�ŷ�˿�������װ��յ���Ϣ: " << msg << endl;
    }
};