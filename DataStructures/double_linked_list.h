/*
Own implementation of doubly linked list
*/
#ifndef double_linked_list

#define double_linked_list

//libraries
#include <bits/stdc++.h>
using namespace std;

// Node class
template <class Key>
class Node
{
public:
    Key data;   // key stored by the current node
    Node *next; // points to next element in list
    Node *prev; // points to prev element in list

    // constructor
    Node(Key key)
    {
        this->data = key;
        this->next = NULL;
        this->prev = NULL;
    }
};

// DoubleLinkedList class
template <class Key>
class DoubleLinkedList
{
private:
    Node<Key> *head; // dummy head
    Node<Key> *tail; // dummy tail

public:
    // constructor
    DoubleLinkedList()
    {
        // head and tail are both dummies
        // both will be NULL always
        head = new Node<Key>(INT_MIN);
        tail = new Node<Key>(INT_MIN);
        head->next = tail;
        tail->prev = head;
    }

    // deletes the given node from the list
    void Delete(Node<Key> *node)
    {
        if (node != NULL)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }

    // adds the given node to the last
    void addNodeLast(Node<Key> *node)
    {
        if (node == NULL)
        {
            return;
        }
        Node<Key> *tailPrev = tail->prev;
        tailPrev->next = node;
        node->next = tail;
        tail->prev = node;
        node->prev = tailPrev;
    }

    // add the given element to the last by creating a node
    Node<Key> *addElementLast(Key data)
    {
        Node<Key> *temp = new Node<Key>(data);
        addNodeLast(temp);
        return temp;
    }

    // return whether the list is empty or not
    // true means list is not empty
    bool isPresent()
    {
        return head->next != tail;
    }

    // returns first node in the list
    Node<Key> *getNodeFirst()
    {
        if (isPresent())
        {
            return head->next;
        }
        else
        {
            return NULL;
        }
    }

    // gets last node in the list
    Node<Key> *getNodeLast()
    {
        if (isPresent())
        {
            return tail->prev;
        }
        else
        {
            return NULL;
        }
    }

    // prints the doubly linked list
    void printList()
    {
        if (isPresent())
        {
            Node<Key> *temp = head->next;
            while (temp != tail)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "Nothing is present.\n";
        }
    }
};

#endif