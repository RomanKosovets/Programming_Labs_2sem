#ifndef C___2_SEM_QUEUE_H
#define C___2_SEM_QUEUE_H

#include "queue"
#include <iostream>

using namespace std;

class QUEUE {
    queue<int> My;

public:

    int TAKE(int r);
    void ADD(int a);
    void Show();

    friend QUEUE operator+=(QUEUE &t, int r);
    friend QUEUE operator-=(QUEUE &t, int r);
};

#endif
