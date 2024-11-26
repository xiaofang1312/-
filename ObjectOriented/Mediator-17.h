#pragma once
#include <string>
#include <map>
using namespace std;

class Country;
// �н�����Ļ���
class MediatorOrg
{
public:
    void addMember(Country* country);
    virtual void declare(string msg, Country* country, string name) = 0;
    virtual ~MediatorOrg() {}
protected:
    map<string, Country*> m_countryMap;
};

// ��������
class WorldGovt : public MediatorOrg
{
public:
    void declare(string msg, Country* country, string name) override;
};

// ������
class GeMingArmy : public MediatorOrg
{
public:
    void declare(string msg, Country* country, string name) override;
};
