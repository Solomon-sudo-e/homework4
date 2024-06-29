#include <iostream>
#include "SStack.h"
#include "SQueue.h"

SStack initialize_stack() {
    SStack s;
    return s;
}

SQueue initialize_Queue() {
    SQueue q;
    return q;
}

int go_again() {
    int option;
    cout << "Do you want to go again?" << endl << "1) Yes     2) No" << endl;
    cin >> option;

    if(option == 1) {
        return 1;
    } else if(option == 2) {
        return 2;
    } else {
        cout << "You did not select a valid option, try again!" << endl;
        go_again();
    }
}

void menu() {
    bool continueMenu = true; // Flag to control the loop

    cout << "Welcome to the brack'n'tag menu!" << endl;

    while (continueMenu) {
        SStack s;
        SQueue q;
        int option;
        string new_string;
        cout << "You have two options:" << endl
             << "1) Check your brackets for balance." << endl
             << "2) Check your tagging on a menu. The rules are: a-->bcc, b-->a#, c-->aaa, until it reaches a '#'!" << endl;
        cout << "What is your option going to be?" << endl;

        cin >> option;

        switch (option) {
            case 1:
                cout << "Please type what you would like to be checked!" << endl;
                cin >> new_string;

                for (char i : new_string)
                    s.Push(i);

                if (s.check_brackets(s.getHead())) {
                    cout << "Your string is balanced!" << endl;
                } else {
                    cout << "Your string is unfortunately not balanced." << endl;
                }

                break;

            case 2:
                cout << "Please type what you would like to tag! Keep in mind only to include 'a', 'b', 'c', and '#'" << endl;
                cin >> new_string;

                for (char c : new_string) {
                    q.Insert(c);
                }
                q.tagger();

                break;

            default:
                cout << "You did not select a valid option! Try again." << endl;
                continue; // Skip go_again prompt
        }

        int goAgainOption = go_again();

        if (goAgainOption == 2) {
            continueMenu = false; // Exit loop
            cout << "Exiting the menu. Goodbye!" << endl;
        }
    }
}

using namespace std;
int main() {

    menu();

    return 0;
}
