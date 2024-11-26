#pragma once
#include <iostream>
#include "Visitor-23.h"
using namespace std;

// ��Ա��Ļ��� 
class AbstractMember
{
public:
    AbstractMember(string name) : m_name(name) {}
    string getName()
    {
        return m_name;
    }
    virtual void accept(AbstractAction* action) = 0;
    virtual ~AbstractMember() {}
protected:
    string m_name;
};

// ��������
class MaleMember : public AbstractMember
{
public:
    using AbstractMember::AbstractMember;
    void accept(AbstractAction* action) override
    {
        action->maleDoing(this);
    }
};

// Ů������
class FemaleMember : public AbstractMember
{
public:
    using AbstractMember::AbstractMember;
    void accept(AbstractAction* action) override
    {
        action->femaleDoing(this);
    }
};