#include <iomanip>
#include <vector>
#include <string>
#include "pizzaViewer.h"
#include "pizza.h"


using namespace std;

void PizzaViewer::displayToppings(ostream& out) {
    out << "Toppings:" << endl;

    for (int i = 0; i < Pizza::toppingsList.size(); ++i) {
        out << "\t" << (i+1) << ". " << Pizza::toppingsList[i];
    }
}

void PizzaViewer::displayOptions(ostream& out) {
    out << "Add-ons and Extras:" << endl;
    
    for (auto& m : Pizza::addOns) {
        out << "\t" << left << std::setw(20) << m.first << m.second << endl;
    }
}

void displayOrder(ostream& out, float price, string description, vector<int> toppingSelected) {

    out << "You ordered: " << description << endl;
    out << "Toppings: ";
    if (toppingSelected.empty()) {
        out << "No extra toppings selected." << endl;
    } else {
            out << endl;
        for (auto i : toppingSelected) {
            out << "\t" << "- " << toppings[i] << endl;
        }
    }

    out << endl << "Price: $" << price << endl << endl;
}