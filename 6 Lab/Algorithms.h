#ifndef C___2_SEM_ALGORITHMS_H
#define C___2_SEM_ALGORITHMS_H
#include <iterator>
#pragma once

using namespace std;

template <typename iterator, typename object>
bool all_of(const iterator begin, const iterator end, bool (&func)(object)) {
    for (auto it = begin; it != end; it = next(it))
        if (!func(*it))
            return false;
    return true;
}


template <typename iterator, typename object>
bool is_partitioned (const iterator begin, const iterator end, bool (&func)(object)) {
    for (auto it = begin; it != end; it++) {
        if (*it > func(*it))
            return false;
    }
    return true;
}


template <typename iterator, typename object>
object find_backward (const iterator begin, const iterator end, const object x){
    for (auto it = end; it != begin; it--){
        if (*it == x) {
            return x;
        }
    }
    return object();
}
#endif
