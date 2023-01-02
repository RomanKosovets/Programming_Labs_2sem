#ifndef C___2_SEM_SEARCHMIN_H
#define C___2_SEM_SEARCHMIN_H
#pragma once

template<typename T>
T SearchMin(T a, T b){
    if( a < b){
        return a;
    }
    return b;
}

#endif
