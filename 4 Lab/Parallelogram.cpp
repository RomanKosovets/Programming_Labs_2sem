#include "parallelogram.h"
#include <math.h>
#include <iostream>

using namespace std;

Parallelogram::Parallelogram() : m_top1{}, m_top2{}, m_top3{}, m_top4{}, m_mass{}, m_classname("Parallelogram") {}

double Parallelogram::square() const {
    CVector2D a, b;
    a.x = m_top2.x - m_top1.x, a.y = m_top2.y - m_top1.y;
    b.x = m_top3.x - m_top1.x, b.y = m_top3.y - m_top1.y;

    return abs(a.x * b.y - a.y * b.x);
}

double Parallelogram::perimeter() const {
    CVector2D a, b;
    a.x = m_top2.x - m_top1.x, a.y = m_top2.y - m_top1.y;
    b.x = m_top3.x - m_top1.x, b.y = m_top3.y - m_top1.y;

    return 2 * (sqrt(pow(a.x, 2) + pow(a.y, 2)) + sqrt(pow(b.x, 2) + pow(b.y, 2)));
}

double Parallelogram::mass() const {
    return m_mass;
}

CVector2D Parallelogram::position() const {
    CVector2D pos;
    pos = {(m_top4.x - m_top1.x) / 2, (m_top4.y - m_top1.y) / 2};
    return pos;
}

bool Parallelogram::operator==(const IPhysObject &ob) const {
    return this->mass() == ob.mass();
}

bool Parallelogram::operator<(const IPhysObject &ob) const {
    return this->mass() < ob.mass();
}

void Parallelogram::draw() const {
    cout << "/---------DRAW_PARALLELOGRAM---------/\n";
    cout << "Parallelogram:\n";
    cout << "First top = (" << m_top1.x << "," << m_top1.y << ")\n";
    cout << "Second top = (" << m_top2.x << "," << m_top2.y << ")\n";
    cout << "Third top = (" << m_top3.x << "," << m_top3.y << ")\n";
    cout << "Fourth top = (" << m_top4.x << "," << m_top4.y << ")\n";
    cout << "Mass of parallelogram = " << mass() << "\n";
    cout << "Classname is " << m_classname << '\n';
    cout << "Size in bytes = " << size() << '\n';
    cout << "/-----THIS_IS_YOUR_PARALLELOGRAM-----/\n\n";
}

void Parallelogram::initFromDialog() {
    cout << "/---------Initialization_PARALLELOGRAM---------/\n";
    cout << "Enter Parallelogram's first top coordinates:\n";
    cin >> m_top1.x >> m_top1.y;
    cout << "Enter Parallelogram's second top coordinates:\n";
    cin >> m_top2.x >> m_top2.y;
    cout << "Enter Parallelogram's third top coordinates:\n";
    cin >> m_top3.x >> m_top3.y;
    cout << "Enter Parallelogram's fourth top coordinates:\n";
    cin >> m_top4.x >> m_top4.y;
    cout << "Enter Parallelogram's weight:\n";
    cin >> m_mass;
    cout << "\n\n";
}

const char * Parallelogram::classname() const {
    return m_classname;
}

unsigned int Parallelogram::size() const {
    return sizeof(m_top1) * 4 + sizeof(m_mass) + sizeof(m_classname);
}
