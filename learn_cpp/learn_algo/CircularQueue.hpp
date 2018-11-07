#pragma once
#include <iostream>

//Circular queue will waste one element's storage.
class CircularQueue
{
public:
    CircularQueue(int capacity)
        :m_capacity(capacity)
    {
        m_items = new int[capacity];
        m_head = 0;
        m_tail = 0;
    }
    ~CircularQueue()
    {
        delete[] m_items;
    }
    bool enqueue(int item)
    {
        if ((m_tail + 1) % m_capacity == m_head)
        {
            std::cout << "full queue dude!" << std::endl;
            return false;
        }
        else
        {
            m_items[m_tail] = item;
            m_tail = (m_tail + 1) % m_capacity;
            return true;
        }
    }
    int dequeue()
    {
        if (m_head == m_tail)
        {
            std::cout << "empty queue" << std::endl;
            return 0;
        }
        else
        {
            int item = m_items[m_head];
            m_head = (m_head + 1) % m_capacity;
            return item;
        }
    }
    void dump()
    {
        for (int idx = m_head; idx% m_capacity != m_tail; ++idx)
        {
            std::cout << m_items[idx%m_capacity] << std::endl;
        }
    }
private:
    int * m_items;
    int m_capacity;
    int m_head;
    int m_tail;
};
