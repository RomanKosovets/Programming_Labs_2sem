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

matrix::matrix(int row, int col) {
    Row = row;  //переменным Row и Col присваиются вводимые значения числа строк и столбцов матрицы
    Col = col;
    array = new double *[row];  //конструктор создает двумерный динамический массив
    for (int i = 0; i < row; i++) array[i] = new double[col];
}

istream &operator>>(istream &istr, matrix &m) // перегрузка оператора ввода матрицы
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            istr >> m.array[i][j];
    return istr;
}

ostream &operator<<(ostream &ostr, matrix &m) //перегрузка оператора вывода матрицы
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            ostr << m.array[i][j] << "\t";
        ostr << "\n";
    }
    return ostr;
}

matrix operator+(matrix &m1, matrix &m2) //перегрузка оператора плюс
{
    matrix temp(3,3);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp.array[i][j] = m1.array[i][j] + m2.array[i][j];
    return (temp);
}

matrix operator-(matrix &m1, matrix &m2) //перегрузка оператора минус
{
    matrix temp1(3,3);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp1.array[i][j] = m1.array[i][j] - m2.array[i][j];
    return (temp1);
}

matrix operator*(matrix &m1, int x)     //перегрузка оператора умножения на число
{
    matrix temp2(3,3);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp2.array[i][j] = m1.array[i][j] * x;
    return (temp2);
}

matrix operator^(matrix &m1, matrix &m2) //перегрузка оператора произведения матриц
{
    matrix temp(3,3);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp.array[i][j] = m1.array[i][j] * m2.array[i][j];
    return (temp);
}
bool operator==(matrix &m1, matrix &m2)
{
    int d1;
    int d2;

    d1 = m1.array[0][0] * m1.array[1][1] * m1.array[2][2] + m1.array[0][1] * m1.array[1][2] * m1.array[2][0]
         + m1.array[1][0] * m1.array[2][1] * m1.array[0][2] - m1.array[2][0] * m1.array[1][1] * m1.array[0][2] -
         m1.array[2][1] * m1.array[1][2] * m1.array[0][0] - m1.array[1][0] * m1.array[0][1] * m1.array[2][2];

    d2 = m2.array[0][0] * m2.array[1][1] * m2.array[2][2] + m2.array[0][1] * m2.array[1][2] * m2.array[2][0]
         + m2.array[1][0] * m2.array[2][1] * m2.array[0][2] - m2.array[2][0] * m2.array[1][1] * m2.array[0][2] -
         m2.array[2][1] * m2.array[1][2] * m2.array[0][0] - m2.array[1][0] * m2.array[0][1] * m2.array[2][2];


    return d1 == d2;
}

bool operator>(matrix &m1, matrix &m2)
{
    int d1;
    int d2;

    d1 = m1.array[0][0] * m1.array[1][1] * m1.array[2][2] + m1.array[0][1] * m1.array[1][2] * m1.array[2][0]
         + m1.array[1][0] * m1.array[2][1] * m1.array[0][2] - m1.array[2][0] * m1.array[1][1] * m1.array[0][2] -
         m1.array[2][1] * m1.array[1][2] * m1.array[0][0] - m1.array[1][0] * m1.array[0][1] * m1.array[2][2];

    d2 = m2.array[0][0] * m2.array[1][1] * m2.array[2][2] + m2.array[0][1] * m2.array[1][2] * m2.array[2][0]
         + m2.array[1][0] * m2.array[2][1] * m2.array[0][2] - m2.array[2][0] * m2.array[1][1] * m2.array[0][2] -
         m2.array[2][1] * m2.array[1][2] * m2.array[0][0] - m2.array[1][0] * m2.array[0][1] * m2.array[2][2];

    return d1 > d2;
}

bool operator<(matrix &m1, matrix &m2)
{
    int d1;
    int d2;

    d1 = m1.array[0][0] * m1.array[1][1] * m1.array[2][2] + m1.array[0][1] * m1.array[1][2] * m1.array[2][0]
         + m1.array[1][0] * m1.array[2][1] * m1.array[0][2] - m1.array[2][0] * m1.array[1][1] * m1.array[0][2] -
         m1.array[2][1] * m1.array[1][2] * m1.array[0][0] - m1.array[1][0] * m1.array[0][1] * m1.array[2][2];

    d2 = m2.array[0][0] * m2.array[1][1] * m2.array[2][2] + m2.array[0][1] * m2.array[1][2] * m2.array[2][0]
         + m2.array[1][0] * m2.array[2][1] * m2.array[0][2] - m2.array[2][0] * m2.array[1][1] * m2.array[0][2] -
         m2.array[2][1] * m2.array[1][2] * m2.array[0][0] - m2.array[1][0] * m2.array[0][1] * m2.array[2][2];

    return d1 < d2;
}

bool operator!=(matrix &m1, matrix &m2)
{
    int d1;
    int d2;
    d1 = m1.array[0][0] * m1.array[1][1] * m1.array[2][2] + m1.array[0][1] * m1.array[1][2] * m1.array[2][0]
         + m1.array[1][0] * m1.array[2][1] * m1.array[0][2] - m1.array[2][0] * m1.array[1][1] * m1.array[0][2] -
         m1.array[2][1] * m1.array[1][2] * m1.array[0][0] - m1.array[1][0] * m1.array[0][1] * m1.array[2][2];

    d2 = m2.array[0][0] * m2.array[1][1] * m2.array[2][2] + m2.array[0][1] * m2.array[1][2] * m2.array[2][0]
         + m2.array[1][0] * m2.array[2][1] * m2.array[0][2] - m2.array[2][0] * m2.array[1][1] * m2.array[0][2] -
         m2.array[2][1] * m2.array[1][2] * m2.array[0][0] - m2.array[1][0] * m2.array[0][1] * m2.array[2][2];

    return d1 != d2;
}



int main() {
    int m, n, x;
    cout << "Введите размер матрицы: ";
    cin >> m >> n;
    cout << "Введите число на которое хотите умножить матрицу:\n";
    cin >> x;

    matrix a(m, n);
    matrix b(m, n);
    matrix c(m, n);

    cout << "Введите матрицу A:\n";
    cin >> a;
    cout << "Введите матрицу B:\n";
    cin >> b;

    c = a + b;
    cout << "Сумма матриц A и B:\n" << c << endl;

    c = a - b;
    cout << "разность матриц A и B:\n" << c << endl;

    c = a * x;
    cout << "Умножение матрицы А на число x:\n" << c << endl;

    c = a ^ b;
    cout << "Произведение матриц A и В:\n" << c << endl;

    if (a == b)
        cout << "Равны" << endl;

    if (a > b)
        cout << "Матрица А больше матрицы B" << endl;

    if (a < b)
        cout << "Матрица A меньше матрицы В" << endl;

    if (a != b)
        cout << "Не равны" << endl;
    return 0;
}

