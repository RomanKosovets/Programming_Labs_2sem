#ifndef C___2_SEM_MATRIX_H
#define C___2_SEM_MATRIX_H

#include <iostream>
using namespace std;

class matrix {
private:
    int Row, Col;       // строки и столбцы
    double **array;     // элементы матрицы
public:

    matrix(int, int);   //конструктор

    friend istream &operator>>(istream &istr, matrix &m);   //перегрузка оператора ввода
    friend ostream &operator<<(ostream &ostr, matrix &m);   //перегрузка оператора вывода
    friend matrix operator+(matrix &m1, matrix &m2);        //перегрузка оператора плюс
    friend matrix operator-(matrix &m1, matrix &m2);        //перегрузка оператора минус
    friend matrix operator*(matrix &m1, int x);             //перегрузка оператора умножения на число
    friend matrix operator^(matrix &m1, matrix &m2);        //перегрузка оператора произведения матриц
    friend bool operator==(matrix &m1, matrix &m2);        //перегрузка оператора сравнения
    friend bool operator>(matrix &m1, matrix &m2);
    friend bool operator<(matrix &m1, matrix &m2);
    friend bool operator!=(matrix &m1, matrix &m2);
};
#endif
