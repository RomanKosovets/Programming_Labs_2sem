#ifndef C___2_SEM_MENU_H
#define C___2_SEM_MENU_H

#pragma once

#include "Queue.h"
#include "Exception.h"
#include <vector>

using namespace std;

enum QueueCommands {
    SHOW_TOP = 1,
    POP_ELEMENT,
    PUSH_ELEMENT
};

class menu {
public:
    void getAction();
    void queueAction();
    void SearchMinAction();

private:
    Queue <5, char> Q;
};

#endif
