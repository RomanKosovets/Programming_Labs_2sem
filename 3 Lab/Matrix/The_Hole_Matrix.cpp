#include <iostream>

using namespace std;


class matrix {
private:
    int Row, Col;       // ��ப� � �⮫���
    double **array;     // ������ ������
public:

    matrix(int, int);   //���������


    friend istream &operator>>(istream &istr, matrix &m);   //��ॣ�㧪� ������ �����
    friend ostream &operator<<(ostream &ostr, matrix &m);   //��ॣ�㧪� ������ �뢮��
    friend matrix operator+(matrix &m1, matrix &m2);        //��ॣ�㧪� ������ ����
    friend matrix operator-(matrix &m1, matrix &m2);        //��ॣ�㧪� ������ �����
    friend matrix operator*(matrix &m1, int x);             //��ॣ�㧪� ������ 㬭������ �� �᫮
    friend matrix operator^(matrix &m1, matrix &m2);        //��ॣ�㧪� ������ �ந�������� �����
    friend bool operator==(matrix &m1, matrix &m2);        //��ॣ�㧪� ������ �ࠢ�����
    friend bool operator>(matrix &m1, matrix &m2);
    friend bool operator<(matrix &m1, matrix &m2);
    friend bool operator!=(matrix &m1, matrix &m2);
};

matrix::matrix(int row, int col) {
    Row = row;  //��६���� Row � Col ��ᢠ����� ������� ���祭�� �᫠ ��ப � �⮫�殢 ������
    Col = col;
    array = new double *[row];  //��������� ᮧ���� ��㬥�� �������᪨� ���ᨢ
    for (int i = 0; i < row; i++) array[i] = new double[col];
}

istream &operator>>(istream &istr, matrix &m) // ��ॣ�㧪� ������ ����� ������
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            istr >> m.array[i][j];
    return istr;
}

ostream &operator<<(ostream &ostr, matrix &m) //��ॣ�㧪� ������ �뢮�� ������
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            ostr << m.array[i][j] << "\t";
        ostr << "\n";
    }
    return ostr;
}

matrix operator+(matrix &m1, matrix &m2) //��ॣ�㧪� ������ ����
{
    matrix temp(3,3);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp.array[i][j] = m1.array[i][j] + m2.array[i][j];
    return (temp);
}

matrix operator-(matrix &m1, matrix &m2) //��ॣ�㧪� ������ �����
{
    matrix temp1(3,3);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp1.array[i][j] = m1.array[i][j] - m2.array[i][j];
    return (temp1);
}

matrix operator*(matrix &m1, int x)     //��ॣ�㧪� ������ 㬭������ �� �᫮
{
    matrix temp2(3,3);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp2.array[i][j] = m1.array[i][j] * x;
    return (temp2);
}

matrix operator^(matrix &m1, matrix &m2) //��ॣ�㧪� ������ �ந�������� �����
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
    cout << "������ ࠧ��� ������: ";
    cin >> m >> n;
    cout << "������ �᫮ �� ���஥ ��� 㬭����� ������:\n";
    cin >> x;

    matrix a(m, n);
    matrix b(m, n);
    matrix c(m, n);

    cout << "������ ������ A:\n";
    cin >> a;
    cout << "������ ������ B:\n";
    cin >> b;

    c = a + b;
    cout << "�㬬� ����� A � B:\n" << c << endl;

    c = a - b;
    cout << "ࠧ����� ����� A � B:\n" << c << endl;

    c = a * x;
    cout << "��������� ������ � �� �᫮ x:\n" << c << endl;

    c = a ^ b;
    cout << "�ந�������� ����� A � �:\n" << c << endl;

    if (a == b)
        cout << "�����" << endl;

    if (a > b)
        cout << "����� � ����� ������ B" << endl;

    if (a < b)
        cout << "����� A ����� ������ �" << endl;

    if (a != b)
        cout << "�� ࠢ��" << endl;
    return 0;
}

