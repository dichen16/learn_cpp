#include "LinkedList.hpp"

LinkedList::LinkedList()
{
    m_header = new Node;
    m_header->m_next = nullptr;
}

LinkedList::~LinkedList()
{
    Node * tmp = m_header;
    while (tmp)
    {
        delete tmp;
        tmp = tmp->m_next;
    }
}

void LinkedList::insertAtHead(int data)
{
    Node * newNode = new Node;
    newNode->m_next = nullptr;
    newNode->m_var = data;
    if (m_header->m_next == nullptr)
    {
        m_header->m_next = newNode;
    }
    else
    {
        newNode->m_next = m_header->m_next;
        m_header->m_next = newNode;
    }
}

Node * LinkedList::getNodeFromIndex(int index)
{
    Node * tmp = m_header->m_next;
    for (int count =0; count < index; ++count)
    {
        tmp = tmp->m_next;
    }
    std::cout << "gotcha " << tmp->m_var << std::endl;
    return tmp;
}

Node * LinkedList::getMiddleNode()
{
    Node * slow = m_header;
    Node * fast = m_header;
    while (true)
    {
        if (!fast || !fast->m_next)
        {
            return slow;
        }
        slow = slow->m_next;
        fast = fast->m_next->m_next;
    }
    return nullptr;
}

int LinkedList::getLength()
{
    int length = 0;
    Node * tmp = m_header->m_next;
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

bool LinkedList::isCyclic()
{
    Node * slow = m_header;
    Node * fast = m_header;
    while (slow && fast)
    {
        slow = slow->m_next;
        fast = fast->m_next ? fast->m_next->m_next : fast->m_next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false; 
}

void LinkedList::insertAfterIndex(int index, int data)
{
    Node * prev = getNodeFromIndex(index);
    Node * newNode = new Node;
    newNode->m_next = prev->m_next;
    newNode->m_var = data;
    //middle situation, neither insert at head, nor at end.
    prev->m_next = newNode;


}

void LinkedList::deleteNodeFromIndex(int index)
{
    if (index == 0)
    {
        Node * save = m_header->m_next->m_next;
        delete m_header->m_next;
        m_header->m_next = save;
    }
    else
    {
        //do not concern the overflow situation
        Node * target = getNodeFromIndex(index);
        Node * prev = getNodeFromIndex(index - 1);
        Node * next = getNodeFromIndex(index + 1);
        prev->m_next = next;
        delete target;
    }
    //if the target is the end node, that's easy
}

void LinkedList::dump()
{
    Node * tmp = m_header->m_next;
    while (tmp)
    {
        std::cout << tmp->m_var << std::endl;
        tmp = tmp->m_next;
    }
}

void LinkedList::reverse()
{
    Node *tmp = m_header->m_next;
    Node *prev = nullptr;
    while (tmp)
    {
        Node * next = tmp->m_next;
        tmp->m_next = prev;
        prev = tmp;
        tmp = next;
    }
    m_header->m_next = prev;
}   

