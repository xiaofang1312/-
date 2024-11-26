#include <iostream>
using namespace std;

#if 0
class Person
{
public:
    void meeting(string name) 
    {
        cout << "������" << name << endl;
    }
    void getMarried() 
    {
        cout << "����, ������, ôô��!" << endl;
    }
};

class NiuLang : public Person
{
public:
    void searchNiu() 
    {
        cout << "ţ��ȥ��ţ��..." << endl;
    }
    string getNiu() 
    {
        return m_niu;
    }
    string getName()
    {
        return "��ţ";
    }
private:
    string m_niu;
};

class ZhiNv : public Person
{
public:
    void searchFangChe()
    {
        cout << "֯Ůȥ�ҷĳ���..." << endl;
    }
    string getFangChe()
    {
        return m_fangChe;
    }
    string getName()
    {
        return "�ɶ�";
    }
private:
    string m_fangChe;
};

class HongNiang
{
public:
    HongNiang(NiuLang* niuLang, ZhiNv* zhiNv) : 
        m_niuLang(niuLang), m_zhiNv(zhiNv) {}
    void doSomething()
    {
        cout << "ǣţ���ӱ�" << m_niuLang->getNiu() << endl;
        cout << "�ĳ�װţ����" << m_zhiNv->getFangChe() << endl;
    }
    void seekHelp()
    {
        m_niuLang->searchNiu();
        m_zhiNv->searchFangChe();
    }
private:
    NiuLang* m_niuLang = nullptr;
    ZhiNv* m_zhiNv = nullptr;
};

int main()
{
    NiuLang* niuLang = new NiuLang;
    ZhiNv* zhiNv = new ZhiNv;
    HongNiang* hongNiang = new HongNiang(niuLang, zhiNv);
    hongNiang->doSomething();
    hongNiang->seekHelp();
    niuLang->meeting(zhiNv->getName());
    zhiNv->meeting(niuLang->getName());
    niuLang->getMarried();
    zhiNv->getMarried();

    return 0;
}
#endif