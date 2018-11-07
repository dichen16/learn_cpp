#pragma once
//stack implemented by single linked list

template<typename T>
struct Frame
{
    T m_content;
    Frame * m_next;
};

template<typename T>
class Stack
{
public:
    Stack()
    {
        m_bottom = new Frame<T>;
        m_bottom->m_next = nullptr;
    }
    ~Stack()
    {
        Frame<T> * tmp = m_bottom;
        while (tmp)
        {
            delete tmp;
            tmp = tmp->m_next;
        }
    }

    void push(T &frame)
    {
        if (m_bottom->m_next == nullptr)
        {
            Frame<T> * tmp = new Frame<T>;
            tmp->m_content = frame;
            tmp->m_next = nullptr;
            m_bottom->m_next = tmp;
            std::cout << "1" << std::endl;
        }
        else
        {
            Frame<T> * topFrame = top();
            Frame<T> * tmp = new Frame<T>;
            tmp->m_content = frame;
            tmp->m_next = nullptr;
            topFrame->m_next = tmp;
            std::cout << "2" << std::endl;
        }
        std::cout << "finish push " << frame << std::endl;
    }
    Frame<T> * top()
    {
        Frame<T> * tmp = m_bottom;
        while(tmp->m_next)
        {
            tmp = tmp->m_next;
        }
        return tmp;
    }
    void pop()
    {
        Frame<T> * slow = m_bottom;
        Frame<T> * fast = m_bottom->m_next;
        while (fast->m_next)
        {
            slow = slow->m_next;
            fast = fast->m_next;
        }
        delete fast;
        slow->m_next = nullptr;
       
    }
    int size()
    {
        int length = 0;
        Frame<T> * tmp = m_bottom->m_next;
        if (!tmp)
        {
            return 0;
        }
        else
        {
            while (tmp)
            {
                ++length;
                tmp = tmp->m_next;
            }
        }
        return length;
    }
    //from bottom to top
    void dump()
    {
        Frame<T> * tmp = m_bottom->m_next;
        while (tmp)
        {
            std::cout << tmp->m_content << std::endl;
            tmp = tmp->m_next;
        }
    }
private:
    Frame<T> * m_bottom;

};
