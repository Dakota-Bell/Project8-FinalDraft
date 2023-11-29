//Header file linkedQueue.h

#ifndef H_linkedQueue
#define H_linkedQueue
#include "node.h"

#include <iostream>
#include <cassert>

using namespace std;



template <class t>
class linkedQueueType
{
public:
    const linkedQueueType<t>& operator=
                    (const linkedQueueType<t>&);
      //Overload the assignment operator.

    bool isEmptyQueue() const;
      //Function to determine whether the queue is empty.
      //Postcondition: Returns true if the queue is empty,
      //               otherwise returns false.

    bool isFullQueue() const;
      //Function to determine whether the queue is full.
      //Postcondition: Returns true if the queue is full,
      //               otherwise returns false.

    void initializeQueue();
      //Function to initialize the queue to an empty state.
      //Postcondition: queueFront = nullptr; queueRear = nullptr

    t front() const;
      //Function to return the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program
      //               terminates; otherwise, the first
      //               element of the queue is returned.

    t back() const;
      //Function to return the last element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program
      //               terminates; otherwise, the last
      //               element of the queue is returned.

    void addQueue(const t& queueElement);
      //Function to add queueElement to the queue.
      //Precondition: The queue exists and is not full.
      //Postcondition: The queue is changed and queueElement
      //               is added to the queue.

    void deleteQueue();
      //Function  to remove the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: The queue is changed and the first
      //               element is removed from the queue.

    linkedQueueType();
      //Default constructor

    linkedQueueType(const linkedQueueType<t>& otherQueue);
      //Copy constructor

    ~linkedQueueType();
      //Destructor

private:
    node<t> *queueFront; //pointer to the front of
                                //the queue
    node<t> *queueRear;  //pointer to the rear of
                                //the queue
};

    //Default constructor
template <class t>
linkedQueueType<t>::linkedQueueType()
{
    queueFront = nullptr; //set front to nullptr
    queueRear = nullptr;  //set rear to nullptr
} //end default constructor

template <class t>
bool linkedQueueType<t>::isEmptyQueue() const
{
    return (queueFront == nullptr);
} //end isEmptyQueue

template <class t>
bool linkedQueueType<t>::isFullQueue() const
{
    return false;
} //end isFullQueue

template <class t>
void linkedQueueType<t>::initializeQueue()
{
    node<t> *temp;

    while (queueFront!= nullptr)  //while there are elements
                                  //left in the queue
    {
        temp = queueFront;  //set temp to point to the
                            //current node
        queueFront = queueFront->link;  //advance first to
                                        //the next node
        delete temp;    //deallocate memory occupied by temp
    }

    queueRear = nullptr;  //set rear to nullptr
} //end initializeQueue


template <class t>
void linkedQueueType<t>::addQueue(const t& newElement)
{
    node<t> *newNode;

    newNode = new node<t>;   //create the node

    newNode->info = newElement; //store the info
    newNode->link = nullptr;    //initialize the link
                                //field to nullptr

    if (queueFront == nullptr) //if initially the queue is empty
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else        //add newNode at the end
    {
        queueRear->link = newNode;
        queueRear = queueRear->link;
    }
}//end addQueue

template <class t>
t linkedQueueType<t>::front() const
{
    assert(queueFront != nullptr);
    return queueFront->info;
} //end front

template <class t>
t linkedQueueType<t>::back() const
{
    assert(queueRear!= nullptr);
    return queueRear->info;
} //end back

template <class t>
void linkedQueueType<t>::deleteQueue()
{
    node<t> *temp;

    if (!isEmptyQueue())
    {
        temp = queueFront;  //make temp point to the
                            //first node
        queueFront = queueFront->link; //advance queueFront

        delete temp;    //delete the first node

        if (queueFront == nullptr) //if after deletion the
                                   //queue is empty
            queueRear = nullptr;   //set queueRear to nullptr
    }
    else
        cout << "Cannot remove from an empty queue" << endl;
}//end deleteQueue


    //Destructor
template <class t>
linkedQueueType<t>::~linkedQueueType()
{
  deleteQueue();
} //end destructor

template <class t>
const linkedQueueType<t>& linkedQueueType<t>::operator=(const linkedQueueType<t>& otherQueue)
{
  node<t> * temp = otherQueue.queueFront;
  while(temp->link != nullptr)
  {
    queueFront->info = temp->info;
    queueFront->link = new node<t>;
    queueFront = queueFront->link;
    temp = temp->link;
  }
    //Write the definition of to overload the assignment operator

} //end assignment operator

	//copy constructor
template <class t>
linkedQueueType<t>::linkedQueueType(const linkedQueueType<t>& otherQueue)
{
    node<t> * newNode;
    node<t> *current;

    if(queueFront != nullptr)
      deleteQueue();
    if (otherQueue.queueFront == nullptr)
    {
      queueFront = nullptr;
      queueRear = nullptr;
    }
    else
    {
      current = otherQueue.queueFront;

      queueFront = new node<t>;

      queueFront->info = current->info;
      queueFront->link = nullptr;

      queueRear = queueFront;
      
      current = current->link;

      while(current!= nullptr)
      {
        newNode = new node<t>;
        newNode->info = current->info;
        newNode->link = nullptr;

        queueRear->link = newNode;
        queueRear = newNode;

        current = current->link;
      }
    }
    //Write the definition of the copy constructor
}//end copy constructor

#endif
