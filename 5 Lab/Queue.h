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
