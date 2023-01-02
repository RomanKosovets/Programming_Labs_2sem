#ifndef C___2_SEM_INTERFACE_H
#define C___2_SEM_INTERFACE_H
#pragma once

// интерфейс "Геометрическая фигура"
class IGeoFig {
public:
    virtual double square() const = 0;
    virtual double perimeter() const = 0;
};

class CVector2D {
public:
    double x, y;
};

// интерфейс "Физический объект"
class IPhysObject {
public:
    virtual double mass() const = 0;
    virtual CVector2D position() const = 0;
    virtual bool operator== (const IPhysObject& ob ) const = 0;
    virtual bool operator< (const IPhysObject& ob ) const = 0;
};

// интерфейс "Отображаемый"
class IPrintable {
public:
    virtual void draw() const = 0;
};

// Диалог с пользователем.
class IgIDialogInitial {
public:
    virtual void initFromDialog() = 0;
};

// Интерфейс "Класс"
class BaseCObject {
public:
    virtual const char* classname() const = 0;
    virtual unsigned int size() const = 0;
};
#endif
