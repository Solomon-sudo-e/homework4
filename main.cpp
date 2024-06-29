#include <iostream>
#include "SStack.h"
#include "SQueue.h"

int go_again() {
    int option;
    cout << "Do you want to go again?" << endl << "1) Yes     2) No" << endl;
    cin >> option;
    while((option != 1) && (option != 2)) {
        if(option == 1) {
            return 1;
        } else if(option == 2) {
            return 2;
        } else {
            cout << "You did not select a valid option, try again!" << endl;
        }
    }
}

void menu() {
    int option;
    string new_string;
    SStack stack;
    SQueue q;
    bool continueMenu = true; // Flag to control the loop

    cout << "Welcome to the brack'n'tag menu!" << endl;

    while (continueMenu) {
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
                    stack.Push(i);

                if (stack.check_brackets(stack.getHead())) {
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

        cout << "Do you want to go again?" << endl;
        cout << "1) Yes     2) No" << endl;

        int goAgainOption;
        cin >> goAgainOption;

        if (goAgainOption != 1) {
            continueMenu = false; // Exit loop
        }
    }

    cout << "Exiting the menu. Goodbye!" << endl;
}

using namespace std;
int main() {

    menu();

    return 0;
}
