#include <iostream>
#include <vector>
#include "Algorithms.h"

using namespace std;

template <typename T>
bool predicat(T value) {
    return value > 4;
}

int main() {
    vector<int> arr = {5, 6, 7, 8, 9, 10};
    cout << ((all_of(arr.begin(), arr.end(), predicat<int>)) ? "TRUE" : "FALSE") << endl;
    cout << ((is_partitioned(arr.begin(), arr.end(), predicat<int>)) ? "TRUE" : "FALSE") << endl;
    cout << ((find_backward(arr.begin(), arr.end(), 10))) << endl;
}
