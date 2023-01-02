#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue(int size)
{
    arr = new int[size];
    Max_size = size;
    front = 0;
    back = -1;
    count = 0;
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "The Queue is full\nProgram end\n";
        exit(EXIT_FAILURE);
    }

    int x = arr[front];
    cout << "Number successfully removed from Queue " << endl;

    front = (front + 1) % Max_size;
    count--;

    return x;
}

void Queue::enqueue(int number) {
    if (isFull()) {
        cout << "The Queue is full\nProgram end\n";
        exit(EXIT_FAILURE);
    }

    cout << "Number " << number << " added to the Queue " << endl;

    back = (back + 1) % Max_size;
    arr[back] = number;
    count++;
}

int Queue::size() {
    return count;
}

bool Queue::isEmpty() {
    return (size() == 0);
}

bool Queue::isFull() {
    return (size() == Max_size);
}

Queue operator<<(Queue& a, int number) {
    a.enqueue(number);
    return number;
}
Queue operator>>(Queue& a, int b) {
    a.dequeue();
    return b;
}


int main() {
    Queue Q{5};
    Q << 5;
    Q << 90;
    Q >> 1;
}