#ifndef C___2_SEM_CIRCLEBUFFER_H
#define C___2_SEM_CIRCLEBUFFER_H

#pragma once
#include <algorithm>
#include <iterator>
#include <initializer_list>

using namespace std;

template <class T>
class CircleBuffer {
public:
    class iterator : public std::iterator<std::random_access_iterator_tag, T> { // мы определяем, что все типы указателей находятся в категории итераторов произвольного доступа
    public:
        using difference_type = typename std::iterator<std::random_access_iterator_tag, T> ::difference_type; // целочисленный тип со знаком, который можно использовать для определения расстояния между итераторами.

        difference_type operator-(const iterator& obj) const {
            return data - obj.data;
        }
        explicit iterator(T *start) {
            data = start;
        }
        iterator(const iterator& obj) {
            data = obj.data;
        }
        ~iterator() = default;

        T& operator*() {
            return *(data);
        }
        T* operator->() {
            return data;
        }
        iterator operator++() {
            ++data;
            return *this;
        }
        iterator operator--() {
            --data;
            return *this;
        }
        iterator operator+(int value) {
            data = data + value;
            return *this;
        }
        iterator operator-(int value) {
            data = data - value;
            return *this;
        }
        bool operator==(const iterator& it) const {
            return data == it.data;
        }
        bool operator!=(const iterator& it) const {
            return data != it.data;
        }
        bool operator<(const iterator& it) const {
            return data < it.data;
        }
        bool operator<=(const iterator& it) const {
            return data <= it.data;
        }
        bool operator>(const iterator& it) const {
            return data > it.data;
        }
        bool operator>=(const iterator& it) const {
            return data >= it.data;
        }
    private:
        T *data = nullptr;
    };
    
    
    iterator begin() const {
        return iterator(data);
    }
    iterator end() const {
        return iterator(data + size_Cb);
    }
    size_t capacity() const {
        return this->capacity_Cb;
    }
    size_t size() const {
        return this->size_Cb;
    }
    explicit CircleBuffer(size_t capacity){
        capacity_Cb = capacity;
        data = new T[capacity_Cb];
    }

    CircleBuffer(const CircleBuffer& buffer): size_Cb(buffer.size_Cb), capacity_Cb(buffer.capacity_Cb), data(buffer.data){};
    ~CircleBuffer() {
        delete[] data;
    }


    void push_front(T value) {
        if (size_Cb < capacity_Cb) {
            for (int i = size_Cb; i >= 1; i--)
                data[i] = data[i - 1];
            data[0] = value;
            size_Cb++;
        }
        else {
            for (int i = capacity_Cb - 1; i >= 1; i--)
                data[i] = data[i - 1];
            data[0] = value;
        }
    }
    void pop_front() {
        for (int i = 0; i < size_Cb - 1; i++)
            data[i] = data[i + 1];
        size_Cb--;
    }
    void push_back(T value) {
        if (size_Cb < capacity_Cb) {
            data[size_Cb] = value;
            size_Cb++;
        }
        else {
            for (int i = 1; i < capacity_Cb; i++)
                data[i - 1] = data[i];
            data[capacity_Cb - 1] = value;
        }
    }
    void pop_back() {
        if (size_Cb > 0)
            size_Cb--;
    }
    void insert(int it, T value) {
        data[it % capacity_Cb] = value;
    }
    void remove(int it) {
        for (int i = it + 1; i < size_Cb; i++)
            data[(i - 1) % capacity_Cb] = data[i % capacity_Cb];
        size_Cb--;
    }
    void resize(size_t newcapacity_Cb) {
        T* newdata = new T[newcapacity_Cb];
        size_Cb = min(size_Cb, newcapacity_Cb);
        for (size_t i = 0; i < size_Cb; i++)
            newdata[i] = data[i];
        delete data;
        data = newdata;
        capacity_Cb = newcapacity_Cb;
    }

private:
    size_t size_Cb = 0;
    size_t capacity_Cb = 0;
    T* data = nullptr;
};

#endif
