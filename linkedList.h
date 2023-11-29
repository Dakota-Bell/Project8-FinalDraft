#ifndef H_LinkedListType
#define H_LinkedListType

#include <iostream>
#include <cassert>

#include "node.h"

using namespace std;

//*****************  class linkedListType   ****************

template <class t>
class linkedListType
{
public:
    const linkedListType& operator=(const linkedListType& otherList)
    {
        if(this != &otherList)
            copyList(otherList);
    }
    void initializeList()
    {
        destroyList();
    }
    bool isEmptyList()
    {
        return (first == nullptr);
    }
    void print()
    {
        int i = 1;
        node<t> *current;

        current = first;
        while (current != nullptr)
        {
            cout << i << ": " << current->info << endl;
            current = current->link;
            i++;
        }
    }
    int length()
    {
        return count;
    }
    void destroyList()
    {
        node<t> *temp;
        while (first != nullptr)
        {
            temp = first;
            first = first->link;
            delete temp;
        }
        last = nullptr;
        count = 0;
    }
    t front()
    {
        assert(first != nullptr);
        return first->info;
    }
    t back()
    {
        assert(last != nullptr);

        return last->info;
    }
    int search(const t& searchItem)
    {
        node<t> *current;
        int i = 0;
        bool found = false;

        for(int i = 0; i < count; i++)
        {
            if(searchItem == current->info)
                return i;
            else
                return -1;
        }

        current = first;

        while (current != nullptr && !found)
        {
            if (current->info == searchItem)
                found = true;
            else
                current = current->link;

        i++;
        }

        return i;
    }

    void insert(const t& item)
    {
        node<t> *newNode;

        newNode = new node<t>;

        newNode->info = item;
        newNode->link = first;
        first = newNode;
        count++;

        if (last == nullptr)
            last = newNode;
    }
    void deleteNode(const t& item)
    {
        node<t> *current;
        node<t> *trailCurrent;
        bool found;

        if (first == nullptr)    //Case 1; the list is empty.
            cout << "Cannot delete from an empty list."
                << endl;
        else
        {
            if (first->info == item)
            {
                current = first;
                first = first->link;
                count--;
                if (first == nullptr)
                    last = nullptr;
                delete current;
            }
            else
            {
                found = false;
                trailCurrent = first;
                current = first->link;

                while (current != nullptr && !found)
                {
                    if (current->info != item)
                    {
                        trailCurrent = current;
                        current = current-> link;
                    }
                    else
                        found = true;
                }

                if (found)
                {
                    trailCurrent->link = current->link;
                    count--;

                    if (last == current)
                        last = trailCurrent; 
                    delete current;
                }
                else
                    cout << "The item to be deleted is not in the list." << endl;
            }//end else
        }//end else
    }
    linkedListType()
    {
        first = nullptr;
        last = nullptr;
    }
    linkedListType(const linkedListType& otherList)
    {
        first = nullptr;
        copyList(otherList);
    }
    ~linkedListType()
    {
        destroyList();
    }
private:
    int count;
    node<t> *first;
    node<t> *last;

    void copyList(const linkedListType& otherList)
    {
        node<t> *newNode;
        node<t> *current;

        if(first != nullptr)
            destroyList();

        if(otherList.first == nullptr)
        {
            first = nullptr;
            last = nullptr;
            count = 0;
        }
        else
        {
            current = otherList.first;
            count = otherList.count;

            first = new node<t>;

            first->info = current->info;
            first->link = nullptr;
            last = first;
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
    }
};

#endif
