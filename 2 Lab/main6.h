#ifndef C___2_SEM_MAIN6_H
#define C___2_SEM_MAIN6_H

#pragma once

using namespace std;
#define DEFSET 100 // Размер множества по умолчанию

template<class T>
class Set {
    T *Setnumbers;      // Указатель на члены множества
    int Size;           // Размер памяти, выделенный множеству
    int NumMembers;     // Количество элементов множества
public:
    Set();

    explicit Set(int size);

    Set(const Set &ob);

// закрытые функции:
    void insert(T member); // добавление элемента
    void remove(T member); // удаление элемента
    int ismember (T member); //проверка, является ли элемент членом множества

//Операторные функции:
    Set<T> &operator+(T member);           //Добавление нового элемента
    Set<T> &operator+(Set &ob);            //Создание объединения
    Set<T> operator-(T member);            //Удаление элемента
};


/*
    Set();//Конструктор по умолчанию

    Set(const Set&); // конструктор копирования

    explicit Set(int size); // конструктор макс. длины

    static Set ElementIN(const Set &a, const Set &b);        // Проверка на содержание во множестве элемента.

    static Set ElementPlus(int number);                      //Добавление элемента во множество.

    static Set ElementDel(int number);                       //Изъятие элемента из множества.

    static Set PeresechenieS1_S2(const Set &a, const Set &b);//Вычисление пересечения с другим множеством.

    static Set ObedinenieS1_S2(const Set &a, const Set &b);  //Вычисление объединения с другим множеством.
                                                             //Добавление/изъятие всех элементов, содержащихся в другом множестве.

};
*/
#endif


