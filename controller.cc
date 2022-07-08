#include "controller.h"

#include "pizza.h"
#include "size.h"
#include "pizzaViewer.h"
#include <cctype>

using namespace std;

Controller::Controller(std::istream& in, std::ostream& out) :
    //in{in}, out{out}, view{new PizzaViewer()} {}
    in{in}, out{out}, view{} {}

Pizza* Controller::getSize() {
    char c;

    view.displaySizes(out);

    out << "What size would you like?" << endl;
    while (in >> c) {
        c = toupper(c);
        if (c == 'S' || c == 'M' || c == 'L' || c == 'X' || c == 'P') break;
    }
    

    Pizza* p = NULL;

    // Getting the size
    if (c == 'S') {
        PizzaSize* s = new smallPizza;
        p = s->createPizza();
    } else if (c == 'M') {
        PizzaSize* s = new mediumPizza;
        p = s->createPizza();
    } else if (c == 'L') {
        PizzaSize* s = new largePizza;
        p = s->createPizza();
    } else if (c == 'X') {
        PizzaSize* s = new xLargePizza;
        p = s->createPizza();
    } else {
        PizzaSize* s = new partyPizza;
        p = s->createPizza();
    }

    return p;
}


Pizza* Controller::getToppings(Pizza* p) {
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

    // Getting the toppings
    for (auto i : toppings) {
        p = new Topping(p, Pizza::toppingList[i - 1]);
    }

    return p;
}

Pizza* Controller::getAddOns(Pizza* p) {
    char c;

    view.displayAddOns(out);

    out << "When you are finished entering add ons, enter '0'." << endl;

    set<char> addOnsSelected;
    out << "Enter the number corresponding to your desired topping: ";

    while (in >> c) {
        c = toupper(c);
        if (c == 'G' || c == 'S' || c == 'T' || c == 'V') {
            addOnsSelected.insert(c);
            out << Pizza::addOnMap.at(c) << " added." << endl << endl;
        } else if (c == '0') {
            break;
        }
        out << "Enter the number corresponding to your desired topping: ";
    }
    return p;
}

void Controller::displayMenu() {
    out << "Here is our menu:" << endl << endl;

    view.displayOptions(out);
}

Pizza* Controller::takePizzaOrder() {
    Pizza* p = getSize();
    p = getToppings(p);
    p = getAddOns(p);

    out << endl << "Your order: " << p->getDescription() << endl << endl;

    return p;
}
    
void Controller::payBill() {
    out << "Pending implementation." << endl;
}

void Controller::run() {
    out << "Hi! This is PizzaTime, a pizza pop-up shop celebrating the summer." << endl;
    // displayMenu();
    Pizza* p = NULL;
    //do {
        p = takePizzaOrder();
    //} while(...);


    payBill();
}