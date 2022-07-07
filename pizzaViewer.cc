#include <iomanip>
#include <vector>
#include <string>
#include "pizzaViewer.h"
#include "pizza.h"
#include "size.h"


using namespace std;

void PizzaViewer::displayToppings(ostream& out) {
    out << "Toppings:" << endl;

    for (int i = 0; i < Pizza::toppingList.size(); ++i) {
        out << "\t" << right << setw(2) << (i+1) << ". " << Pizza::toppingList[i] << endl;
    }
    out << endl;
}

void PizzaViewer::displaySizes(std::ostream& out) {
    vector<char> sizeAbbs = {'S', 'M', 'L', 'X', 'P'};
    int i = 0;
    out << "Here are the sizes you can choose from:" << endl;
    for (auto& size : PizzaSize::possibleSizes) {
        out << "\t" << "- " << size << " (" << sizeAbbs[i] << ")" << endl;
        ++i;
    }
    out << endl;
}

void PizzaViewer::displayAddOns(ostream& out) {
    vector<char> sizeAbbs = {'G', 'S', 'T', 'V'};
    int i = 0;

    out << "Add-ons and Extras:" << endl;
    
    for (auto& m : Pizza::addOns) {
        out << "\t(" << sizeAbbs[i] << ") " << left << std::setw(20) << m.first << m.second << endl;
        ++i;
    }
    out << endl;
}

void PizzaViewer::displayOptions(ostream& out) {
    out << endl;
    displaySizes(out);
    displayToppings(out);
    displayAddOns(out);
    out << endl;
}

void displayOrder(ostream& out, float price, string description, vector<int> toppingSelected) {

    out << "You ordered: " << description << endl;
    out << "Toppings: ";
    if (toppingSelected.empty()) {
        out << "No extra toppings selected." << endl;
    } else {
            out << endl;
        for (auto i : toppingSelected) {
            out << "\t" << "- " << Pizza::toppingList[i] << endl;
        }
    }

    out << endl << "Price: $" << price << endl << endl;
}