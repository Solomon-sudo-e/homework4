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

int SStack::size() {
    int count;
    StackNode *Temp = Head;
    while(Temp != nullptr) {
        count++;
        Temp = Temp->Next;
    }
    return count;
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

//Local function used in check_brackets
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}') ||
           (open == '<' && close == '>');
}

bool SStack::check_brackets(StackNode *node) {
    char brackets[4] = {'>',']','}', ')'};
    char closed_brackets[4] = {'<', '[', '{', '('};
    char open[size()];
    char close[size()];
    char limbo[size()];
    int posClose = 0;
    int posLimbo = 0;
    int posOpen = 0;
    int count = 0;

    StackNode *Temp = node;
    //Filling opening, and closing brackets. I do this by iterating through open brackets filling the open in a limbo
    // checking most recent closed to most recent open and removing from limbo and adding to open array to be
    // compared later down the line.
    while(Temp != nullptr) {
        for(int i = 0; i<4; i++) {
            //Checking that character is open and putting in limbo.
            if(node->Character == brackets[i]) {
                limbo[posLimbo] = brackets[i];
                posLimbo++;
            }
            //Checking if closed bracket and inserting into closed array.
            if(node->Character == closed_brackets[i]) {
                close[posClose] = closed_brackets[i];
                posClose++;

                //Matching the opening and closing brackets to find matches and inserting opening match to open array.
                if(isMatchingPair(close[count], limbo[posLimbo-1])) {
                    open[posOpen] = limbo[posLimbo-1];
                    posLimbo--;
                    posOpen++;
                    count++;
                }
            }
        }
        Temp = Temp->Next;
    }

    //Setting size equal to posClose so I can iterate and still keep track of posClose for checking balance at end.
    int size = posClose;
    //Iterating through and comparing each set of brackets, making sure they are matching pairs.
    for(int i = 0; i < size; i++) {
        //calling local function matching pair, if false immediately return false and stop matching.
        if(isMatchingPair(close[i], open[i])) {
            posClose--;
        } else {
            return false;
        }
    }

    //Check to make sure all brackets have been checked.
    if(posClose == 0) {
        return true;
    } else {
        return false;
    }

}

