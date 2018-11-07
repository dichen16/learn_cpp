#pragma once
#include <iostream>

template <typename T>
class ArrayQueue
{
public:
    ArrayQueue(int capacity)
        :m_capacity(capacity)
    {
        m_items = new T[capacity];
        m_head = 0;
        m_tail = 0;
    }
    ~ArrayQueue()
    {
        delete[] m_items;
    }
    bool enqueue(T & item)
    {
        if (m_tail == m_capacity)
        {
            if (m_head == 0)
            {
                return false;
            }
            for (int idx = m_head; idx < m_tail; ++idx)
            {
                m_items[idx - m_head] = m_items[idx];
            }
            m_tail = m_tail - m_head;
            m_head = 0;
        }
        m_items[m_tail] = item;
        ++m_tail;
        return true;
    }
    T dequeue()
    {
        if (m_tail == 0)
        {
            return false;
        }
        T item = m_items[m_head];
        ++m_head;
        return item;
    }
    void dump()
    {
        for (int idx = m_head; idx < m_tail; ++idx)
        {
            std::cout << m_items[idx] << std::endl;
        }
    }
    bool isEmpty()
    {
        return m_head == m_tail;
    }
private:
    int m_capacity;
    T * m_items;
    int m_head;
    int m_tail;
};
