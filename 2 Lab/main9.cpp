#include <iostream>
#include "main9.h"

Set::Set() {                  // конструктор по умолчанию
    size = 0;
    set = new unsigned int[size];
}

Set::Set(int s) {             // конструктор размера
    size = s;
    set = new unsigned int[size];
    for (unsigned i = 0; i < size; i++)
        set[i] = 0;
}

Set::Set(const Set &s) {      // конструктор копии
    size = s.size;
    set = new unsigned int[size];
    for (unsigned int i = 0; i < size; i++)
        set[i] = s.set[i];
}

void Set::Enter() {
    std::cout << "Введите размер: " << std::endl;
    std::cin >> size;
    set = new unsigned int[size];
    for (unsigned int i = 0; i < size; i++) {
        std::cout << "Введите элемент " << i + 1 << ")";
        std::cin >> set[i];
    }
}

void Set::Show() {
    std::cout << "Получилось множество: " << std::endl;
    std::cout << "( ";
    for (unsigned int i = 0; i < size; i++)
        std::cout << set[i] << " ";
    std::cout << ")" << "\n" << std::endl;
}

void Set::Union(Set a, Set b) {         // Объединение
    this->size = a.size + b.size;
    this->set = new unsigned int[size];
    int i, j, count = 0;
    int n = a.size;


    for (i = 0; i < a.size; i++)
        set[i] = a.set[i];

    for (i = 0; i < b.size; i++) {
        for (j = 0; j < a.size; j++)
            if (b.set[i] == a.set[j])
                continue;
            else
                count++;
        if (count == a.size)
            set[n++] = b.set[i];
        count = 0;
    }
    size = n;
}

void Set::intersection(Set a, Set b) {      //Пересечение
    size = a.size + b.size;
    set = new unsigned int[size];
    int i, j, n = 0;

    for (i = 0; i < a.size; i++)
        for (j = 0; j < b.size; j++) {
            if (a.set[i] == b.set[j]) {
                set[n++] = a.set[i];
                continue;
            }
        }
    size = n;
}

void Set::add() {                          // Добавление
    int a[100];
    unsigned int i;
    int element;
    for (i = 0; i < size; i++)
        a[i] = set[i];
    delete[] set;
    size = size + 1;

    std::cout << "Введите новый элемент " << std::endl;
    std::cin >> element;
    a[i] = element;

    set = new unsigned int[size];
    for (i = 0; i < size; i++)
        set[i] = a[i];
}

void Set::Delete() {                       // Удаление
    unsigned int number, n, i, j;
    n = size;
    std::cout << "Введите номер элемента от 0 до " << size - 1 << std::endl;
    std::cin >> number;

    if (number < 0 || number > size)
        std::cout << "Ля ты клоун, условия для кого!? " << std::endl;
    else {
        for (i = 0; i < n; i++) {
            if (i == number) {
                for (j = i; j < n - 1; j++)
                    set[j] = set[j + 1];
                n--;
            }
        }
        size--;
    }
}

void Set::check() {                 // Проверка
    unsigned int element;
    int Flag = 0;
    std::cout << "Введите элемент для проверки " << std::endl;
    std::cin >> element;
    unsigned int i, count = 0;
    for (i = 0; i < size; i++)
        if ((set[i] == element) && (Flag == 0)) {
            std::cout << "Да, такой элемент найден " << "\n" << std::endl;
            Flag = 1;
        }
        count++;

    if (count == size)
        std::cout << "Элемент не найден " << std::endl;
}


int main()
{
    setlocale(0, "rus");
    Set a;
    std::cout << "Введите множество №1:" << std::endl;
    a.Enter();
    a.Show();

    Set b;
    std::cout << "Введите множество №2: " << std::endl;
    b.Enter();
    b.Show();

    Set d;
    d.intersection(a, b);
    std::cout <<  "Пересечение множеств" << std::endl;
    d.Show();

    Set c;
    c.Union(a, b);
    std::cout << "Объединение множеств " << std::endl;
    c.Show();

    std::cout << "Добавка элемента "<< std::endl;
    c.add();
    c.Show();

    std::cout << "Проверка " << std::endl;
    c.check();

    std::cout << "Извлечение " << std::endl;
    c.Delete();
    c.Show();
}