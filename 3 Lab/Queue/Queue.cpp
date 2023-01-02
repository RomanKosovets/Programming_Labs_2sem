#include "Queue.h"

using namespace std;

void QUEUE::ADD(int a){
    My.push(a);
}

int QUEUE::TAKE(int r){
    r = My.front();
    My.pop();
    return r;
}

void QUEUE::Show(){
    while (!My.empty()){
        cout << My.front() << " ";
        My.pop();
    }
}

QUEUE operator+=(QUEUE &t, int r) {
    t.ADD(r);
    return t;
}

QUEUE  operator-=(QUEUE &t, int r) {
    t.TAKE(r);
    return t;
}