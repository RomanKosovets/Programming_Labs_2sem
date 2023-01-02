#include <iostream>
#include "main9.h"

Set::Set() {                  // ����������� �� ���������
    size = 0;
    set = new unsigned int[size];
}

Set::Set(int s) {             // ����������� �������
    size = s;
    set = new unsigned int[size];
    for (unsigned i = 0; i < size; i++)
        set[i] = 0;
}

Set::Set(const Set &s) {      // ����������� �����
    size = s.size;
    set = new unsigned int[size];
    for (unsigned int i = 0; i < size; i++)
        set[i] = s.set[i];
}

void Set::Enter() {
    std::cout << "������� ������: " << std::endl;
    std::cin >> size;
    set = new unsigned int[size];
    for (unsigned int i = 0; i < size; i++) {
        std::cout << "������� ������� " << i + 1 << ")";
        std::cin >> set[i];
    }
}

void Set::Show() {
    std::cout << "���������� ���������: " << std::endl;
    std::cout << "( ";
    for (unsigned int i = 0; i < size; i++)
        std::cout << set[i] << " ";
    std::cout << ")" << "\n" << std::endl;
}

void Set::Union(Set a, Set b) {         // �����������
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

void Set::intersection(Set a, Set b) {      //�����������
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

void Set::add() {                          // ����������
    int a[100];
    unsigned int i;
    int element;
    for (i = 0; i < size; i++)
        a[i] = set[i];
    delete[] set;
    size = size + 1;

    std::cout << "������� ����� ������� " << std::endl;
    std::cin >> element;
    a[i] = element;

    set = new unsigned int[size];
    for (i = 0; i < size; i++)
        set[i] = a[i];
}

void Set::Delete() {                       // ��������
    unsigned int number, n, i, j;
    n = size;
    std::cout << "������� ����� �������� �� 0 �� " << size - 1 << std::endl;
    std::cin >> number;

    if (number < 0 || number > size)
        std::cout << "�� �� �����, ������� ��� ����!? " << std::endl;
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

void Set::check() {                 // ��������
    unsigned int element;
    int Flag = 0;
    std::cout << "������� ������� ��� �������� " << std::endl;
    std::cin >> element;
    unsigned int i, count = 0;
    for (i = 0; i < size; i++)
        if ((set[i] == element) && (Flag == 0)) {
            std::cout << "��, ����� ������� ������ " << "\n" << std::endl;
            Flag = 1;
        }
        count++;

    if (count == size)
        std::cout << "������� �� ������ " << std::endl;
}


int main()
{
    setlocale(0, "rus");
    Set a;
    std::cout << "������� ��������� �1:" << std::endl;
    a.Enter();
    a.Show();

    Set b;
    std::cout << "������� ��������� �2: " << std::endl;
    b.Enter();
    b.Show();

    Set d;
    d.intersection(a, b);
    std::cout <<  "����������� ��������" << std::endl;
    d.Show();

    Set c;
    c.Union(a, b);
    std::cout << "����������� �������� " << std::endl;
    c.Show();

    std::cout << "������� �������� "<< std::endl;
    c.add();
    c.Show();

    std::cout << "�������� " << std::endl;
    c.check();

    std::cout << "���������� " << std::endl;
    c.Delete();
    c.Show();
}