#include <iostream>
#include "NewsAgency-19.h"
#include "Observer-19.h"
using namespace std;

#if 0
int main()
{
    // ������
    NewsAgency* news1 = new Morgans;
    NewsAgency* news2 = new Gossip;
    // �۲���(������)
    Dragon* dragon = new Dragon(news1, "���桤D����");
    Shanks* shanks = new Shanks(news1, "���˹");
    Bartolomeo* barto = new Bartolomeo(news2, "�������װ�");
    // �ɷ�����������Ϣ
    news1->notify("���桤D��·�ɳ�Ϊ��������µ��Ļ�֮һ, �ͽ�30�ڱ���!!!");
    cout << "=====================" << endl;
    news2->notify("Ů�ۺ������Ҫ�޸�·��, ��·��������, ������...");

    delete news1;
    delete news2;
    delete dragon;
    delete shanks;
    delete barto;

    return 0;
}
#endif