#ifndef C___2_SEM_QUEUE_H
#define C___2_SEM_QUEUE_H

#pragma once

#include <iostream>
#include <queue>
#include "Exception.h"

template <int N, typename T>
class Queue {
public:

    void pop() {
        if (Q.empty()) {
            throw Exception("The queue is empty");
        }
        Q.pop();
    }

    void push(T number) {
        if (Q.size() == N) {
            throw Exception("Queue overflow");
        }
        Q.push(number);
    }

    T front() {
        if (Q.empty()) {
            throw Exception("The queue is empty");
        }
        return Q.front();
    }

private:
    queue <T> Q;
};
#endif

/*
template<typename Type>
class MyQueue
{
private:
    Type *array;
    int maxCap;
    int front;
    int tail;
    int currEl;

public:
    MyQueue(int size)
    {
        array = new Type[size];
        maxCap = size;
        front = 0;
        tail = 0;
        currEl = 0;

    }
    void pop()
    {
        if (isEmpty())
            throw Exception("The queue is empty, can't pop an element\n");
        Type x = array[front];
        front++;
        currEl--;
    }

    void push(Type data)
    {
        if (isFull())
            throw Exception("The queue is full, can't push an element\n");
        array[tail] = data;
        tail++;
        currEl++;
    }

    int size()
    {
        return currEl;
    }

    bool isEmpty()
    {
        if (currEl == 0)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (currEl == maxCap)
            return true;
        else
            return false;
    }
    Type peek()
    {
        if (currEl == 0)
            throw Exception("The queue is empty, there's nothing to peek at.");
        else
            return array[front];
    }
};
 */