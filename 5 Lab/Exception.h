#ifndef C___2_SEM_EXCEPTION_H
#define C___2_SEM_EXCEPTION_H

#pragma once

#include <exception>
#include <string>

using namespace std;

class Exception : public exception {
public:
    Exception(string error_message):
            error_message_(error_message){};

    virtual const char * what() const noexcept override{
        return error_message_.c_str();
    }
private:
    string error_message_;
};

#endif
