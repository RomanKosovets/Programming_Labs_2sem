#include <iostream>
#include <vector>
#include <algorithm>
#include "Ellipse.h"
#include "parallelogram.h"

using namespace std;

unsigned int menu() {

    while (true) {
        cout << "/----------MENU----------/\n\n";
        cout << "1 - Add figure\n";
        cout << "2 - Show all figures\n";
        cout << "3 - Sum all figure's squares\n";
        cout << "4 - Sum all figure's perimeters\n";
        cout << "5 - Show figure's mass' center\n";
        cout << "6 - Show count of memory from all classes\n";
        cout << "7 - Sort all figures by mass\n";
        cout << "8 - Exit from program\n";

        unsigned int action;
        cin >> action;

        return action;
    }
}

unsigned int FigureSELECT() {

    while (true) {
        cout << "/-----Select_figure-----/\n";
        cout << "1 - Ellipse\n";
        cout << "2 - Parallelogram\n";
        unsigned int figure;
        cin >> figure;

        if (figure < 1 || figure > 2) {
            cout << "Error, no such command in list!!!\n";
            continue;
        }
        return figure;
    }
}


int main () {

    vector <Figure*> figures;

    size_t count = 0;
    while (true) {
        unsigned int command = menu();

        switch (command) {
            case 1: {
                unsigned int select = FigureSELECT();
                if (select == 1) {
                    figures.push_back(new Ellipse);
                    figures[count]->initFromDialog();
                    count++;
                    break;
                }
                else {
                    figures.push_back(new Parallelogram);
                    figures[count]->initFromDialog();
                    count++;
                    break;
                }
            }

            case 2: {
                for (int i = 0; i < figures.size(); i++){
                    cout << figures[i]->classname() << "\n";
                    figures[i] -> draw();
                }
                break;
            }

            case 3: {
                double sum = 0;
                for (int i = 0; i < figures.size(); i++)
                    sum += figures[i]->square();
                cout << "Sum all figure's squares = " << sum << '\n';
                break;
            }

            case 4: {
                double sum = 0;
                for (int i = 0; i < figures.size(); i++)
                    sum += figures[i]->perimeter();
                cout << "Sum all figure's perimeters = " << sum << '\n';
                break;

            }

            case 5: {
                double allMX = 0, allMY = 0, allM = 0;
                for (int i = 0; i < figures.size(); i++) {
                    allMX += figures[i]->position().x * figures[i]->mass();
                    allMY += figures[i]->position().y * figures[i]->mass();
                    allM += figures[i]->mass();
                }
                cout << "Center = ( " << allMX / allM << "," << allMY / allM << " )\n";
                break;
            }

            case 6: {
                int sum = 0;
                for (int i = 0; i < figures.size(); i++)
                    sum += figures[i]->size();
                cout << "Count of memory for this system = " << sum << '\n';
                break;
            }

            case 7: {
                sort (figures.begin(), figures.end(),[](Figure* a, Figure* b) {
                    return (a->mass() < b->mass());
                });
                cout << "All figures was sorted\n";
                for (int i = 0; i < figures.size(); i++) {
                    cout << i + 1<< " - " << figures[i] -> classname() << "\n";
                }
                break;
            }

            default:
                cout << "GOODBYE\n";
                return 0;
        }
    }
}

//