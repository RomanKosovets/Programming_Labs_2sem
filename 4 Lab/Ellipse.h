#ifndef C___2_SEM_ELLIPSE_H
#define C___2_SEM_ELLIPSE_H

#pragma once

#include "interface.h"


class Figure:
        public IGeoFig,
        public CVector2D,
        public IPhysObject,
        public IPrintable,
        public IgIDialogInitial,
        public BaseCObject{
};


class Ellipse: public Figure {
public:

    Ellipse ();

    double square() const override ;
    double perimeter() const override ;
    virtual double mass() const override ;
    CVector2D position() const override ;
    bool operator== (const IPhysObject&) const override ;
    bool operator< (const IPhysObject&) const override ;
    void draw() const override ;
    void initFromDialog() override ;
    const char* classname() const override ;
    unsigned int size() const override ;

private:
    CVector2D m_center;
    int side_a;
    int side_b;
    int m_mass;
    const char* m_classname;

};

#endif
