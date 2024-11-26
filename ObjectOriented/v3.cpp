#include <iostream>
using namespace std;

#if 0
class Person
{
public:
    void meeting(Person* person)
    {
        // �໥����
        if (m_person == nullptr)
        {
            m_person = person;
            person->meeting(this);
        }
    }
    void getMarried()
    {
        if (m_flag)
        {
            m_flag = false;
            marry();
            m_person->getMarried();
        }
    }
    virtual string getName() = 0;
    virtual void search() = 0;
    virtual string getCaiChan() = 0;
    virtual void marry() = 0;
protected:
    Person* m_person = nullptr;
    bool m_flag = true;
};

class NiuLang : public Person
{
public:
    void search() override
    {
        cout << "�ҵ�ţ����, ��ȥ��ţ..." << endl;
    }
    string getCaiChan() override
    {
        return m_niu;
    }
    string getName() override
    {
        return "��ţ";
    }
    void marry() override
    {
        cout << "��ҪȢ֯Ů�ˣ�û�뵽����Ȣ����ôƯ����ϱ����������" << endl;
    }
private:
    string m_niu = "�����ţ";
};

class ZhiNv : public Person
{
public:
    void search() override
    {
        cout << "�ҵķĳ�����, ��ȥ�ҷĳ�..." << endl;
    }
    string getCaiChan() override
    {
        return m_fangChe;
    }
    string getName() override
    {
        return "�ɶ�";
    }
    void marry() override
    {
        cout << "���������������˸���, ��֪��ʲôʱ�򱻴���ȥ������" << endl;
    }

private:
    string m_fangChe = "�߲ʺ�ĳ�";
};

class HongNiang
{
public:
    HongNiang(Person* niuLang, Person* zhiNv) :
        m_niuLang(niuLang), m_zhiNv(zhiNv) {}
    void doSomething()
    {
        cout << "ǣţ���ӱ�" << m_niuLang->getCaiChan() << endl;
        cout << "�ĳ�װţ����" << m_zhiNv->getCaiChan() << endl;
    }
    void seekHelp()
    {
        m_niuLang->search();
        m_zhiNv->search();
    }
private:
    Person* m_niuLang;
    Person* m_zhiNv;
};

int main()
{
    NiuLang* niuLang = new NiuLang;
    ZhiNv* zhiNv = new ZhiNv;
    HongNiang* hongNiang = new HongNiang(niuLang, zhiNv);
    hongNiang->doSomething();
    hongNiang->seekHelp();
    niuLang->meeting(zhiNv);
    niuLang->getMarried();

    return 0;
}
#endif