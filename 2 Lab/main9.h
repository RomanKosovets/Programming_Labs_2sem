#ifndef C___2_SEM_MAIN9_H
#define C___2_SEM_MAIN9_H
#include <iostream>
using namespace std;

class Set {
private:
    unsigned int size;
    unsigned int *set;
public:
    Set();               // Конструктор по умолчанию

    explicit Set(int s); // Конструктор размера

    Set(const Set &s);   // Конструктор копии

    void Enter();                      // ввод
    void Show();                       // вывод
    void Union(Set, Set);              // объединение
    void intersection(Set, Set);       // пересечение
    void add();                        // добавка элемента
    void Delete();                     // извлечение
    void check();                      // проверка
};

#endif