#include <iostream>
#include "SStack.h"

using namespace std;
int main() {
    string balance;
    SStack stack;
    cin >> balance;
    for(int i = 0; i<balance.size(); i++) {
        stack.Push(balance[i]);
    }
    stack.Print();
    cout << stack.check_brackets(stack.getHead(), 3, false);

    return 0;
}
