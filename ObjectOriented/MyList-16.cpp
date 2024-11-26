#include "MyList-16.h"
#include "Iterator-16.h"

Node* MyList::insert(Node* node, string name)
{
    Node* item = nullptr;
    if (node == m_head)
    {
        item = pushFront(name);
    }
    else
    {
        item = new Node(name);
        // 1. ��item�������еĽڵ��������
        item->next = node;
        item->prev = node->prev;
        // 2. ��ԭ�������ӶϿ�, ���½�������
        node->prev = item;
        node->prev->next = item;
        m_count++;
    }
    return item;
}

Node* MyList::pushFront(string name)
{
    Node* node = new Node(name);
    if (m_head == nullptr)
    {
        m_head = m_tail = node;
    }
    else
    {
        node->next = m_head;
        m_head->prev = node;
        m_head = node;
    }
    m_count++;
    return node;
}

Node* MyList::pushBack(string name)
{
    Node* node = new Node(name);
    if (m_tail == nullptr)
    {
        m_head = m_tail = node;
    }
    else
    {
        node->prev = m_tail;
        m_tail->next = node;
        m_tail = node;
    }
    m_count++;
    return node;
}

Iterator* MyList::getIterator(bool isReverse)
{
    Iterator* it = nullptr;
    if (isReverse)
    {
        it = new ReverseIterator(this);
    }
    else
    {
        it = new ForwardIterator(this);
    }
    return it;
}
