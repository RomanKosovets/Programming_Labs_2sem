#include <iostream>
#include "CircleBuffer.h"

using namespace std;

template <class T>
void Information(const CircleBuffer<T>& v) {
    cout << "Capacity: " << v.capacity() << "\n";
    cout << "Size: " << v.size() << "\n";
    cout << "Elements: ";
    for (auto it : v)
        cout << it << ' ';
    cout << "\n";
}

int main() {
    CircleBuffer<int> test(5);

    test.push_front(1);
    test.push_back(78);
    test.push_back(90);
    test.push_front(100);

    Information(test);
    cout << "\n";

    test.resize(100);
    test.pop_back();
    test.pop_front();
    test.insert(1, 91);
    test.remove(0);
    Information(test);
    return 0;
}
