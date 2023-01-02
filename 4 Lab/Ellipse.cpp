#include "Ellipse.h"
#include <math.h>
#include <iostream>

using namespace std;

Ellipse::Ellipse():
        side_a{}, side_b{}, m_mass{}, m_classname("Ellipse"){
}

double Ellipse::square() const {
    return side_a * side_b * M_PI;
}

double Ellipse::perimeter() const {
    return (4 * ((M_PI * side_a * side_b + (side_a - side_b)) / (side_a + side_b)));
}

double Ellipse::mass() const {
    return m_mass;
}

CVector2D Ellipse::position() const {
    CVector2D pos{m_center.x, m_center.y};
    return pos;
}

bool Ellipse::operator==(const IPhysObject &ob) const {
    return this->mass() == ob.mass();
}

bool Ellipse::operator<(const IPhysObject &ob) const {
    return this->mass() < ob.mass();
}

void Ellipse::draw() const {
    cout << "/---------DRAW_Ellipse---------/\n";
    cout << "Ellipse:\n";
    cout << "Center = (" << m_center.x << "," << m_center.y << ")\n";
    cout << "Side a = (0," << side_a << ")\n";
    cout << "Side b = (" << side_b << ",0)\n";
    cout << "Mass of Ellipse = " << mass() << "\n";
    cout << "Classname is " << m_classname << '\n';
    cout << "Size in bytes = " << size() << '\n';
    cout << "/-----THIS_IS_YOUR_ELLIPSE-----/\n\n";
}

void Ellipse::initFromDialog() {
    cout << "/---------Initialization_Ellipse---------/\n";
    cout << "Enter Ellipse's center coordinates\n";
    cin >> m_center.x >> m_center.y;
    cout << "Enter Ellipse's side_a on OY\n";
    cin >> side_a;
    cout << "Enter Ellipse's side_b on OX\n";
    cin >> side_b;
    cout << "Enter Ellipse's weight\n";
    cin >> m_mass;
    cout << "\n\n";
}

const char * Ellipse::classname() const {
    return m_classname;
}

unsigned int Ellipse::size() const {
    return sizeof(m_center) + sizeof(side_a) + sizeof(side_b) + sizeof(m_mass) + sizeof(m_classname);
}

