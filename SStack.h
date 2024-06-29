//
// Created by Solomon's PC on 6/26/2024.
//

#ifndef HOMEWORK4_SSTACK_H
#define HOMEWORK4_SSTACK_H

class StackNode {
public:
    char Character;
    StackNode *Next;
};

class SStack {
public:
    /*
     * constructor
     * copy constructor
     * destructor
     * push
     * pop
     * top
     * isFull
     * isEmpty
     * size
     */
    SStack();
    SStack(const SStack &stack);
    ~SStack();

    void Push(char Character);
    int Pop();
    int Top();
    bool isFull();
    bool isEmpty();
    int size();
    void Print();
    StackNode * getHead();
    bool check_brackets(StackNode *node);

private:
    StackNode *Head;
};


#endif //HOMEWORK4_SSTACK_H
