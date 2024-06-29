//
// Created by Solomon's PC on 6/28/2024.
//

#include <iostream>
#include "SQueue.h"
using namespace std;

SQueue::SQueue ()
{
    for(int index=0; index<MAX_SIZE; index++)
        data[index] = 0;
    count = 0;
    end = -1;
    front = 0;
}

SQueue::SQueue (const SQueue & queue)
{
    for (int index=0; index<MAX_SIZE; index++)
        data[index] = queue.data[index];
    count = queue.count;
}

SQueue::~SQueue()
{
   count = 0;
   end = -1;
   front = 0;
   char deleted[MAX_SIZE];
   for(int i = 0; i<MAX_SIZE; i++) {
       data[i] = deleted[i];
   }
}

void SQueue::Insert(const char character)
{
    // Check for full queue
    if (isFull()) return;

    // Save data in queue
    end = (end + 1) % MAX_SIZE;
    data[end] = character;
    count++;
}


void SQueue::Remove(char &character) {
    // Check for empty queue
    if (isEmpty()) {
        cout << "Queue is empty. Cannot remove element." << endl;
        return;
    }

    // Remove front value from queue
    character = data[front];
    front = (front + 1) % MAX_SIZE;
    count--;
}

int SQueue::getCount()
{
    return count;
}

// GetFront method
char SQueue::getFront()
{
    return data[front];
}

bool SQueue::isFull()
{
    return (count == MAX_SIZE);
}

// True if queue is empty
bool SQueue::isEmpty()
{
    return (count == 0);
}

void SQueue::Print()
{
    cout << "Queue: ";
    for (int index=0; index<count; index++)
        cout << data[(front + index) % MAX_SIZE] << ' ';
    cout << endl;
}

void SQueue::tagger() {
    /*
     * a --> bcc
     * b --> a#
     * c --> aaa
     *
     * Check front for symbol or keyword then delete next two and append keyword option.
     * Repeat until reach '#' or 1 symbol remaining.
     */
    char character;
    while(getFront() != '#' || count <= 1) {
        if(isFull()) {
            cout << "Max Size reached" << endl;
            break;
        }
        if(getFront() != 'a' && getFront() != 'b' && getFront() != 'c') {
            cout << "This is an invalid string, try again!" << endl;
            break;
        }

        if(getFront() == 'a') {
            Remove(character);
            Remove(character);
            Insert('b');
            Insert('c');
            Insert('c');
            Print();
        }
        else if(getFront() == 'b') {
            Remove(character);
            Remove(character);
            Insert('a');
            Insert('#');
            Print();
        }
        else if(getFront() == 'c') {
            Remove(character);
            Remove(character);
            Insert('a');
            Insert('a');
            Insert('a');
            Print();
        }
    }
    cout << "Stopping tagging system!" << endl;
    if(getFront() == '#') {
        cout << "'#' was found!";
    } else if(count <= 1)
        cout << "The size was less than 2 and can no longer be checked!" << endl;
}

