#pragma once
#include <string>
using namespace std;

// ������
class Iterator;
// ����һ���ڵ�
struct Node
{
    Node(string n) :name(n) {}
    string name = string();
    Node* next = nullptr;
    Node* prev = nullptr;
};

// ����˫������
class MyList
{
public:
    inline int getCount()
    {
        return m_count;
    }
    inline Node* head()
    {
        return m_head;
    }
    inline Node* tail()
    {
        return m_tail;
    }
    Node* insert(Node* node, string name);
    Node* pushFront(string name);
    Node* pushBack(string name);
    Iterator* getIterator(bool isReverse = true);
private:
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
    int m_count = 0;
};