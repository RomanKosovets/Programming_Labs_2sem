#ifndef C___2_SEM_QUEUE_H
#define C___2_SEM_QUEUE_H

#include <fstream>
#pragma once

class Queue
{
    int *arr;
    int Max_size;
    int front;
    int back;
    int count;

public:

    Queue(int size = 100);

    int dequeue();
    void enqueue(int x);
    int size();
    bool isEmpty();
    bool isFull();

    friend Queue operator>>(Queue &, int i);
    friend Queue operator<<(Queue &, int i);
};
#endif
