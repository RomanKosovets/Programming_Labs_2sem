#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    int m, n, x;
    cout << "Enter matrix size: ";
    cin >> m >> n;
    cout << "Enter the number which you want to multiply the matrix:\n";
    cin >> x;

    matrix a(m, n);
    matrix b(m, n);
    matrix c(m, n);

    cout << "Enter matrix A:\n";
    cin >> a;
    cout << "Enter matrix B:\n";
    cin >> b;

    c = a + b;
    cout << "Sum of matrices A and B:\n" << c << endl;

    c = a - b;
    cout << "Difference of matrices A and B:\n" << c << endl;

    c = a * x;
    cout << "Multiplication of matrix A by a number x:\n" << c << endl;

    c = a ^ b;
    cout << "Matrix product A and ‚:\n" << c << endl;

    if (a == b)
        cout << "Equal" << endl;

    if (a > b)
        cout << "Matrix A more than matrix B" << endl;

    if (a < b)
        cout << "Matrix A less than matrix B" << endl;

    if (a != b)
        cout << "Not equal" << endl;
    return 0;
}

//"3 Lab/Matrix/Matrix.cpp" "3 Lab/Matrix/Matrix.h" "3 Lab/Matrix/main_Matrix.h"
