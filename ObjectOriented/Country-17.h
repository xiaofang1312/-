#pragma once
#include <iostream>
#include <string>
#include "Mediator-17.h"
using namespace std;

// ���������Ļ���
class Country
{
public:
    Country() = default;
    Country(MediatorOrg* org) : m_org(org) {}
    void setMediator(MediatorOrg* org)
    {
        m_org = org;
    }
    virtual void declare(string msg, string country = string()) = 0;
    virtual void setMessage(string msg) = 0;
    virtual string getName() = 0;
    virtual ~Country() {}
protected:
    MediatorOrg* m_org;
};

// ������˹̹
class Alabasta : public Country
{
public:
    using Country::Country;
    Alabasta() = default;
    void declare(string msg, string country = string()) override
    {
        cout << "������˹̹��ʼ��������: " << endl;
        m_org->declare(msg, this, country);
    }
    void setMessage(string msg) override
    {
        cout << "������˹̹�õ�����Ϣ: " << msg << endl;
    }
    string getName()
    {
        return "������˹̹";
    }
};

// ����˹����
class Dressrosa : public Country
{
public:
    using Country::Country;
    Dressrosa() = default;
    void declare(string msg, string country = string()) override
    {
        cout << "����˹������ʼ��������: " << endl;
        m_org->declare(msg, this, country);
    }
    void setMessage(string msg) override
    {
        cout << "����˹�����õ�����Ϣ: " << msg << endl;
    }
    string getName()
    {
        return "����˹����";
    }
};

// ¶¶��������
class Lulusia : public Country
{
public:
    using Country::Country;
    Lulusia() = default;
    void declare(string msg, string country = string()) override
    {
        cout << "¶¶����������������: " << endl;
        m_org->declare(msg, this, country);
    }
    void setMessage(string msg) override
    {
        cout << "¶¶���������õ�����Ϣ: " << msg << endl;
    }
    string getName()
    {
        return "¶¶��������";
    }
};

// ����Ϳ�����
class Kamabaka : public Country
{
public:
    using Country::Country;
    Kamabaka() = default;
    void declare(string msg, string country = string()) override
    {
        cout << "����Ϳ�������������: " << endl;
        m_org->declare(msg, this, country);
    }
    void setMessage(string msg) override
    {
        cout << "����Ϳ������õ�����Ϣ: " << msg << endl;
    }
    string getName()
    {
        return "����Ϳ�����";
    }
};