#include "controller.h"

#include "pizza.h"
#include "size.h"
#include "pizzaViewer.h"
#include <cctype>

using namespace std;

Controller::Controller(std::istream& in, std::ostream& out) :
    //in{in}, out{out}, view{new PizzaViewer()} {}
    in{in}, out{out}, view{} {}

char Controller::getSize() {
    char c;

    view.displaySizes(out);

    out << "What size would you like?" << endl;
    while (in >> c) {
        c = toupper(c);
        if (c == 'S' || c == 'M' || c == 'L' || c == 'X' || c == 'P') break;
    }
    return c;
}


std::set<int> Controller::getToppings() {
    int i;

    view.displayToppings(out);

    out << "When you are finished entering toppings, enter '0'." << endl;

    set<int> toppings;

    while (true) {
        while (true) {
            try {
                out << "Enter the number corresponding to your desired topping: ";
                in >> i;
                if (in.fail()) {
                    throw 1;
                } else if (i < 0 || i > Pizza::toppingList.size()) {
                    throw 2;
                } else {
                    //out << endl;
                    break;
                }
            } catch (int err) {
                if (err == 1) {
                    out << "Please enter an integer" << endl;

                    in.clear();
                    in.ignore(10000, '\n');
                } else {
                    out << "Please enter a valid integer within the toppings range." << endl;
                }
            }
        }
        if (i == 0) break;
        
        out << Pizza::toppingList[i - 1] << " added." << endl << endl;
        toppings.insert(i);
    }
    out << endl << endl;
    return toppings;
}

set<char> Controller::getAddOns() {
    char c;

    view.displayAddOns(out);

    out << "When you are finished entering add ons, enter '0'." << endl;

    set<char> addOnsSelected;

    while (in >> c) {
        c = toupper(c);
        if (c == 'G' || c == 'S' || c == 'T' || c == 'V') {
            addOnsSelected.insert(c);
            out << Pizza::addOnMap.at(c) << " added." << endl << endl;
        } else if (c == '0') {
            break;
        }
    }
    return addOnsSelected;
}

void Controller::displayMenu() {
    out << "Here is our menu:" << endl << endl;

    view.displayOptions(out);
}

void Controller::takeOrder() {
    char size = getSize();
    set<int> toppings = getToppings();
    set<char> extras = getAddOns();
}
void Controller::payBill() {
    out << "Pending implementation." << endl;
}

void Controller::run() {
    out << "Hi! This is PizzaTime, a pizza pop-up shop celebrating the summer." << endl;
    // displayMenu();
    takeOrder();
    payBill();
}