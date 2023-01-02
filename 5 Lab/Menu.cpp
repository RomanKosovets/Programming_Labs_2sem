#include <iostream>
#include "Menu.h"
#include "SearchMin.h"

void menu::getAction() {
    cout << "Choose:\n";
    cout << "1. Search minimum of two numbers\n";
    cout << "2. Queue\n";
    cout << "3. Exit\n";

    unsigned int command;
    try {
        cin >> command;
        if (command < 1 || command > 3) {
            throw ("Something is wrong. Try again\n");
        }
    }

    catch (const char *message) {
        cout << message;
        getAction();
    }

    switch (command) {
        case 1: {
            SearchMinAction();
            break;
        }
        case 2: {
            queueAction();
            break;
        }
        default:
            cout << "-_-_-_-Bye Bro-_-_-_-\n";
            exit(0);
    }
}

void printError(Exception &exception) {
    cout << "ERROR: " << exception.what();
    exit(3);
}

void menu::queueAction() {
    cout << "Choose:\n";
    cout << "1. Show front element\n";
    cout << "2. Pop element\n";
    cout << "3. Push element\n";

    int command = 0;
    try {
        cin >> command;
        if (command < 1 || command > 3) {
            throw ("Something is wrong. Try again\n");
        }
    }

    catch (const char *message) {
        cout << message;
        getAction();
    }

    switch (command) {
        case SHOW_TOP: {
            try {
                cout << "Top = " << Q.front() << "\n\n";
                getAction();
                break;
            }
            catch (Exception &exception) {
                printError(exception);
            }
        }

        case POP_ELEMENT: {
            try {
                Q.pop();
                cout << "\n";
                getAction();
                break;
            }
            catch (Exception &exception) {
                printError(exception);
            }
        }

        case PUSH_ELEMENT: {
            try {
                cout << "Enter number: ";
                char number;
                cin >> number;
                Q.push(number);
                cout << "\n";
                getAction();
            }
            catch (Exception &exception) {
                printError(exception);
            }
        }
    }
}


void menu::SearchMinAction()  {
    try {
        float a, b;
        cout << "Enter two numbers: ";
        cin >> a >> b;
        cout << "\nMinimum = " << SearchMin(a, b) << "\n" << endl;
        getAction();
    }

    catch (const char *message) {
        cout << message;
        getAction();
    }
}

