#include <iostream>
#include <vector>
#include "MyList-16.h"
#include "Iterator-16.h"
using namespace std;

#if 0
int main()
{
    vector<string> nameList{
    "��", "����", "�ܿ�", "���ȡ���", "X�����׿�",
    "��ɫ������", "�Gľ", "��q", "�弪��",
    "һ��", "����", "����", "�Ĺ�", "���",
    "����", "�߹�", "�˲�", "����","ʮ��"
    };
    MyList ls;
    for (int i = 0; i < nameList.size(); ++i)
    {
        ls.pushFront(nameList.at(i));
    }
    // �������
    Iterator* it = ls.getIterator(false);
    cout << "����������Ķ���..." << endl;
    for (auto begin = it->first(); !it->isDone(); it->next())
    {
        cout << "   " << it->current()->name << "say: Ϊ�ϴ����!!! " << endl;
    }
    delete it;
    cout << "===================" << endl;
    // �������
    it = ls.getIterator();
    cout << "����������Ķ���..." << endl;
    for (auto begin = it->first(); !it->isDone(); it->next())
    {
        cout << "   " << it->current()->name << "say: Ϊ�ϴ����!!! " << endl;
    }
    cout << "===================" << endl;

    delete it;

    return 0;
}
#endif