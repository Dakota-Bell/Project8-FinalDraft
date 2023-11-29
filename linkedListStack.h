#include <iostream>
using namespace std;

#include "node.h"

template <class t>
class linkedStackType
{
public:
    // constructor
    linkedStackType()
    {
        stackTop = nullptr;
    }
    // destructor
    ~linkedStackType()
    {
        initializeStack();
    }
    // copy constructor
    linkedStackType(const linkedStackType<t>& otherStack)
    {
        stackTop = nullptr;
        copyStack(otherStack);
    }
    // overloaded assignment operator
    const linkedStackType<t>& operator=(const linkedStackType<t>& otherStack)
    {
        if(this != &otherStack)
            copyStack(otherStack);
        return *this;
    }
    bool isEmptyStack() const
    {
        return (stackTop == nullptr);
    }
    bool isFullStack() const
    {
        return false;
    }
    void initializeStack()
    {
        node<t> *temp;

        while(stackTop != nullptr)
        {
            temp = stackTop;
            stackTop = stackTop->link;
            delete temp;
        }
    }
    void push(const t& newItem)
    {
        node<t> * newNode;
        newNode = new node<t>;

        newNode->info = newItem;
        newNode->link = stackTop;
        stackTop = newNode;
    }
    t top() const
    {
        if(!isEmptyStack())
        {
            return stackTop->info;
        }
    }
    void pop()
    {
        node<t> * temp;

        if(stackTop != nullptr)
        {
            temp = stackTop;
            stackTop = stackTop->link;
            delete temp;
        }
        else
            cout << "Cannot remove from an empty stack." << endl;
    }


private:
    node<t> *stackTop;
    
    // copy stack
    void copyStack(const linkedStackType<t>& otherStack)
    {
        node<t> *newNode, * current, *last;

        if(stackTop != nullptr)
            initializeStack();

        if(otherStack.stackTop == nullptr)
            stackTop = nullptr;

        else
        {
            current = otherStack.stackTop;

            stackTop = new node<t>;
            stackTop->info = current->info;
        }

        stackTop->link = nullptr;

        last = stackTop;
        current = current->link;

        while(current != nullptr)
        {
            newNode = new node<t>;
            newNode->info = current->info;
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
        
    }
};