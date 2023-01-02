#include <iostream>
#include "fun.h"


int main() {

    //std::setlocale(LC_ALL, "Russian");
    int a = 1, b = 2;
    std::cout << "Задание №1" << "\n";
    fun::swap1(&a, &b);
    fun::swap2(a, b);
    if ((a == 1) && (b == 2))
    {
        std::cout << "Yes, №1 is right\n" << std::endl;
    }
    std::cout << "адресс " << &a << std::endl;
    std::cout << "адресс " << &b << "\n" << std::endl;

    std::cout << "Задание №6" << "\n";
    float n = 1.789;
    int x;
    fun::rounding1(&n, &x);
    fun::rounding2(n, x);
    if (x == 2)
    {
        std::cout << "Yes, №6 is right\n" << std::endl;
    }
    std::cout << "адресс " << &n << "\n" << std::endl;

    std::cout << "Задание №9\n";
    float z_re = 2.0;
    float z_im = 3.0;
    float num = 5.0;
    fun::complexnumber1(&z_re, &z_im, &num);
    fun::complexnumber2(z_re, z_im, num);
    if (z_re == 50 && z_im == 75)
    {
        std::cout << "Yes, №9 is right\n" << std::endl;
    }
    std::cout << "адресс " << &z_re << std::endl;
    std::cout << "адресс " << &z_im << std::endl;
    std::cout << "адресс " << &num << "\n" << std::endl;

    std::cout << "Задание №14\n";
    int i, j;
    int matrix[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
    int matrixTest[3][3] = {{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};
    fun::trans_matrix1(matrix);
    fun::trans_matrix2(matrix);
    int flag = 0;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (matrixTest[i][j] == matrix[i][j]){
                flag += 1;
            }
        }
        if (flag == 9){
            std::cout << "Yes, №14 is right\n" << std::endl;
        }
    }
    std::cout << "адресс " << &matrix << std::endl;
    std::cout << "адресс " << &matrixTest << "\n" << std::endl;
}
