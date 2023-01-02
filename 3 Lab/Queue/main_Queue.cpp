#include <iostream>
#include "Queue.h"

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



