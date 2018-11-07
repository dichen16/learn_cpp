#pragma once
#include <iostream>


struct Node
{
    int m_var;
    Node * m_next;
};

//Single linked list 
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void insertAtHead(int data);
    void insertAfterIndex(int index, int data);
    void deleteNodeFromIndex(int index);
    void dump();
    void reverse();
    Node * getNodeFromIndex(int index);
    Node * getMiddleNode();
    int getLength();

    bool isCyclic();


private:
    Node * m_header;
};