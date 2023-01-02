#ifndef C___2_SEM_MATRIX_H
#define C___2_SEM_MATRIX_H

#include <iostream>
using namespace std;

class matrix {
private:
    int Row, Col;       // ������ � �������
    double **array;     // �������� �������
public:

    matrix(int, int);   //�����������

    friend istream &operator>>(istream &istr, matrix &m);   //���������� ��������� �����
    friend ostream &operator<<(ostream &ostr, matrix &m);   //���������� ��������� ������
    friend matrix operator+(matrix &m1, matrix &m2);        //���������� ��������� ����
    friend matrix operator-(matrix &m1, matrix &m2);        //���������� ��������� �����
    friend matrix operator*(matrix &m1, int x);             //���������� ��������� ��������� �� �����
    friend matrix operator^(matrix &m1, matrix &m2);        //���������� ��������� ������������ ������
    friend bool operator==(matrix &m1, matrix &m2);        //���������� ��������� ���������
    friend bool operator>(matrix &m1, matrix &m2);
    friend bool operator<(matrix &m1, matrix &m2);
    friend bool operator!=(matrix &m1, matrix &m2);
};
#endif
