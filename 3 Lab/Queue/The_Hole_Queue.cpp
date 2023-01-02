#include <iostream>
#include <queue>

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

int main()
{

    QUEUE q;
    QUEUE q2;

    cout << "Enter Queue length: ";
    int size;
    cin >> size;

    int number;
    for (int i = 0; i < size; i++){
        cout << "Enter number: ";
        cin >> number;
        q += number;
    }

    int x;
    q2 = q;

    cout << "Enter a number to add to the Queue:\n";
    cin >> x;
    q += x;
    cout << "New Queue:\n";
    q.Show();
    cout << "\n\n";

    cout << "Take the number from first Queue:\n";
    q2 -= x;
    q2.Show();
    return 0;

}

