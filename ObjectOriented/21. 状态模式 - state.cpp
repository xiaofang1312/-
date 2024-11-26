#include <iostream>
#include "State-21.h"
#include "Sanji-21.h"
#include <vector>
using namespace std;

void ForenoonState::working(SanJi* sanji)
{
    // �õ���ǰ��time
    int time = sanji->getClock();
    // �ж�ʱ���
    if (time < 8)
    {
        cout << "��ǰʱ��<" << time << ">��, ׼�����, ��³�˵ö�ȵ�ţ��..." << endl;
    }
    else if (time > 8 && time < 11)
    {
        cout << "��ǰʱ��<" << time << ">��, ȥ��ͷ����, ����ʳ��..." << endl;
    }
    else
    {
        // �л�����һ��״̬
        sanji->setState(new NoonState);
        sanji->working();
    }
}

void NoonState::working(SanJi* sanji)
{
    // �õ���ǰ��time
    int time = sanji->getClock();
    // �ж�ʱ���
    if (time < 13)
    {
        cout << "��ǰʱ��<" << time << ">��, ȥ�������緹, ��·�ɶ�������..." << endl;
    }
    else
    {
        // �л�����һ��״̬
        sanji->setState(new AfternoonState);
        sanji->working();
    }
}

void AfternoonState::working(SanJi* sanji)
{
    // �õ���ǰ��time
    int time = sanji->getClock();
    // �ж�ʱ���
    if (time < 15)
    {
        cout << "��ǰʱ��<" << time << ">��, ׼�������, ���ޱ������������������..." << endl;
    }
    else if (time > 15 && time < 18)
    {
        cout << "��ǰʱ��<" << time << ">��, ���ǰ�ȥ��β����, ����ʳ��..." << endl;
    }
    else
    {
        // �л�����һ��״̬
        sanji->setState(new EveningState);
        sanji->working();
    }
}

void EveningState::working(SanJi* sanji)
{
    // �õ���ǰ��time
    int time = sanji->getClock();
    // �ж�ʱ���
    if (time < 19)
    {
        cout << "��ǰʱ��<" << time << ">��, ȥ��������, ����¡��ȵ���..." << endl;
    }
    else
    {
        cout << "��ǰʱ��<" << time << ">��, ������úܸ���, ����˯����..." << endl;
    }
}

#if 0
int main()
{
    SanJi* sanji = new SanJi;
    vector<int> data{ 7, 10, 12, 14, 16, 18, 22 };
    for (auto item : data)
    {
        sanji->setClock(item);
        sanji->working();
    }
    delete sanji;
    return 0;
}
#endif