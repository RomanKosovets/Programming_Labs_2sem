#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
vector<int>squares;
vector<int>perimeters;

class IGeoFig {
public:

    virtual int getSquare() = 0;
    virtual int getPerimeter() = 0;

    void SetSide(int a, int b) {
        side1 = a;
        side2 = b;
    }

    void SetHeight(int h) {
        height = h;
    }

protected:
    int side1{};
    int side2{};
    int height{};
};

class IPrintable {
public:
    virtual void draw() = 0;
};

class Sum_Figures {
public:
    virtual int AllSquares() = 0;
    virtual int AllPerimeters() = 0;
};

class Parallelogram : public IGeoFig, IPrintable {
public:

    int getSquare() override {
        squares.push_back(side1 * height);
        return (side1 * height);
    }

    int getPerimeter() override {
        perimeters.push_back((side1 + side2) * 2);
        return ((side1 + side2) * 2);
    }

    void draw() override {
        cout << "side 1 = " << side1 << "\n";
        cout << "side 2 = " << side2 << "\n";
        cout << "Height = " << height << "\n";
    }
};

class Ellipse : public IGeoFig, IPrintable {
public:
    int getSquare() override {
        squares.push_back(side1 * side2 * M_PI);
        return (side1 * side2 * M_PI);
    }

    int getPerimeter() override {
        perimeters.push_back(4 * ((M_PI * side1 * side2 + (side1 - side2)) / (side1 + side2)));
        return (4 * ((M_PI * side1 * side2 + (side1 - side2)) / (side1 + side2)));
    }

    void draw() override {
        cout << "Point A = " << side1 << "\n";
        cout << "Point B = " << side2 << "\n";
    }
};

class Sum : public Sum_Figures {
public:
    int AllSquares() override {
        int S_sum = 0;
        for(int i = 0; i < squares.size(); i++){
            S_sum += squares[i];
        }
        return S_sum;
    }
    int AllPerimeters() override {
        int P_sum = 0;
        for(int i = 0; i < perimeters.size(); i++){
            P_sum += perimeters[i];
        }
        return P_sum;
    }
};
int main() {

    Parallelogram Par;
    Ellipse Ell;
    Sum S;

    vector<int> squares;
    int h, a, b;
    cout << "Enter H, side A, side B to calculate the Square and Perimeter of the Parallelogram:\n ";
    cin >> h >> a >> b;
    Par.SetHeight(h);
    Par.SetSide(a, b);

    cout << "Total Parallelogram square: " << Par.getSquare() << endl;
    cout << "Total Parallelogram perimeter: " << Par.getPerimeter() << "\n" << endl;
    cout << "Figure parameters: " << "\n";
    Par.draw();

    cout << "Enter side A and side B to calculate the Square and Perimeter of the Ellipse:\n ";
    cin >> a >> b;
    Ell.SetSide(a, b);

    cout << "Total Ellipse square: " << Ell.getSquare() << endl;
    cout << "Total Ellipse perimeter: " << Ell.getPerimeter() << "\n" << endl;
    cout << "Figure parameters: " << "\n";
    Ell.draw();

    cout << "Summs Squares: \n" << S.AllSquares() << "\n" << endl;
    cout << "Summs Perimetr: \n" << S.AllPerimeters() << "\n" << endl;
    return 0;
}