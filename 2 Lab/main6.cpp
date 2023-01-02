#include <iostream>
#include <conio.h>
#include <windows.h>
#include "main6.h"
#include "../3 Lab/main.h"


using namespace std;
template<class T>
Set<T>::Set() // конструктор по умолчанию
{
    Setnumbers = new T[DEFSET]; // используем размер по умолчанию
    NumMembers = 0; // множество пока пустое
    Size = DEFSET;
}

template<class T>      //основной конструктор (создает пустое множество c областью памяти заданного размера)
Set<T>::Set(int size) {
    Setnumbers = new T[size];
    NumMembers = 0;
    Size = size;
}

template<class T>     // конструктор копирования:
Set<T>::Set(const Set<T> &ob) {
    Size = ob.Size;
    Setnumbers = new T[Size];            // выделяем память для копии
    NumMembers = ob.NumMembers;
    for (int i = 0; i < NumMembers; i++) // копируем элементы множества
        Setnumbers[i] = ob.Setnumbers[i];
}

// функция проверяет, входит ли элемент во множество:
template <class T>
int Set <T> :: ismember(T member)
{
    if (find(member) != -1) return 1;
    else return 0;
}

// Основная функция, которая добавляет элемент во множество:
template <class T> void Set <T> :: insert(T member)
{
    if (! ismember(member)) // если элемент еще не входит во множество
    {
        int i=0;
// находим для него место:
        while (i<NumMembers && Setnumbers[i]<member) i++;
// сдвигаем элементы от этого места вправо:
        for (int j = NumMembers-1; j>=i; j--)
            Setnumbers[j+1] = Setnumbers[j];
        Setnumbers[i] = member; // вставляем элемент
        NumMembers++;
    }
}

// функция удаляет заданный элемент:
template <class T>
void Set<T> :: remove(T member)
{
    int loc = find(member); // определяеи номер этого элемента
    if ( loc != -1) // эсли элемент входит во множество
    { //
        for(; loc<NumMembers-1; loc++)
            Setnumbers[loc] = Setnumbers[loc+1]; // сдвигаем элементы влево
        NumMembers--;
    }
}


// операция добавления элемента к множеству:
template<class T>
Set<T> &Set<T>::operator+(T member) {
    insert(member);
    return *this;
}

template<class T>
Set<T> &Set<T>::operator+(Set<T>&ob) //Объединение множеств
{
// создаем временный объект с достаточным объемом памяти:
    Set<T> temp(Size + ob.Size);
    for (int i = 0;i<NumMembers;i++)
// копируем элементы первого множества
        temp.insert(Setnumbers[i]);
    for (int i = 0;i<ob.NumMembers;i++)
// копируем элементы второго множества
        temp.insert(ob.Setnumbers[i]);
    return temp;
}

// Оператор, который удаляет заданный элемент из множества:
template<class T>
Set<T> Set<T>::operator-(T member) {
    Set < T > temp(*this);
    temp.remove(member);
    return temp;
}
int main()
{
    setlocale(LC_ALL, "rus");

    Set <int> s;
    cin >> reinterpret_cast<bool &>(s);
    cout << s;

    s = s + 1 + 3 + -1;
    cout << "Добавили 1, 3, -1: \n";
    cout << s;

    s = s - (-1);
    cout << "Удалили -1:\n";
    cout << s;

    Set<int> ss;
    ss = ss + 1 + 5 + 10;
    cout << "Второе множество:";
    cout << "ss = " << ss;

    Set<int> s2 = s + ss;
    cout << "Объединение множеств:\n";
    cout << "s2 = " << s2;

    cout << "Размер объединения: ";
    cout << int(s2) << endl;
    return 0;
}


bool Set::In(int number) const {
    return false;
}
