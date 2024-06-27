//
// Created by Solomon's PC on 6/26/2024.
//

#include <iostream>
#include "SStack.h"

using namespace std;
SStack::SStack(): Head(nullptr) {}

SStack::SStack(const SStack &stack) {
    StackNode *copy = new StackNode();
    Head = copy;

    StackNode *ptr = stack.Head;

    while(ptr != nullptr) {
        copy->Next = new StackNode();
        copy = copy->Next;
        copy->Character = ptr->Character;
        copy->Next = nullptr;
        ptr = ptr->Next;
    }

    copy = Head;
    Head = copy->Next;
    delete copy;
}

SStack::~SStack() {
    while(Head != nullptr) {
        StackNode *Temp = Head;
        Head = Head->Next;
        delete Temp;
    }
}

void SStack::Push(char Character) {
    StackNode *Temp = new StackNode;

    Temp->Character = Character;
    Temp->Next = Head;
    Head = Temp;
}

int SStack::Pop() {
    if(isEmpty()) return 0;
    char Character = Head->Character;

    StackNode *Temp = Head;
    Head = Head->Next;
    delete Temp;
    return Character;
}

int SStack::Top() {
    if(isEmpty()) return 0;
    return Head->Character;
}

bool SStack::isFull() {
    return false;
}

bool SStack::isEmpty() {
    return (Head==nullptr);
}

void SStack::Print()
{
    cout << "stack: ";
    StackNode *Temp = Head;
    while (Temp != nullptr)
    {
        cout << Temp->Character << " ";
        Temp = Temp->Next;
    }
    cout << endl;cout << endl;
}

StackNode * SStack::getHead() {
    return Head;
}

bool SStack::check_brackets(StackNode *node, int bracket_type, bool checking_closed) {
    char brackets[4] = {'>',']','}','/'};
    char closed_brackets[3] = {'<', '[', '{'};
    bool checked = false;

    if(node == nullptr && checking_closed) return false;
    if(node == nullptr && !checking_closed) return true;

    if(!checking_closed) {
        for(int i = 0; i<3; i++) {
            if(node->Character == brackets[i]) {
                checked = true;
                std::cout << node->Character << " Open bracket" << endl;
                return check_brackets(node->Next, i, true);
            }
        }
        if(!checked) {
            std::cout << "unchecked";

            return check_brackets(node->Next, 3, false);
        }
    } else if (checking_closed) {
        if(node->Character == closed_brackets[bracket_type]) {
            std::cout << node->Character << " Closed bracket";
            return true;
        }
        for(int i = 0; i<3; i++) {
            if(node->Character == brackets[i]) {
                return check_brackets(node->Next, i, false);
            } else if (node->Character == closed_brackets[i] && (i != bracket_type)) {
                return false;
            }
        }
        return check_brackets(node->Next, bracket_type, true);

    }
    /*
     * Check brackets, if opening bracket move to next node and check
     * for closing bracket. If new opening bracket recursively call to check for true first.
     * To check for true it should look to close the bracket with a matching bracket before
     * seeing a different closing bracket.
     */
}
