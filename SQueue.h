//
// Created by Solomon's PC on 6/28/2024.
//

#ifndef HOMEWORK4_SQUEUE_H
#define HOMEWORK4_SQUEUE_H

#include <string>
#include <vector>

using namespace std;
class SQueue {
    /*
     * constructor
• copy constructor
• destructor
• insert (enqueue) (add an element)
• remove (dequeue) (remove an element)
• front (return the first element without removing it)
• isFull
• isEmpty
• size
• print

     */

public:
    SQueue();
    SQueue(const SQueue &queue);
    ~SQueue();

    void Insert(const char input);
    void Remove(char &character);

    int getCount();
    char getFront();
    bool isFull();
    bool isEmpty();
    int size();
    void Print();
    void tag();
    void tagger();

private:
    static const int MAX_SIZE = 100;
    char data[MAX_SIZE];
    int count;
    int end;
    int front;
};


#endif //HOMEWORK4_SQUEUE_H
