#include "controller.h"

#include "pizza.h"
#include "size.h"
#include "pizzaViewer.h"
#include <set>
#include <cctype>
#include <iomanip>

using namespace std;

Controller::Controller(std::istream& in, std::ostream& out) :
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
    PizzaSize* s = NULL;

    // Getting the size
    if (c == 'S') {
        s = new smallPizza;
        p = s->createPizza();
    } else if (c == 'M') {
        s = new mediumPizza;
        p = s->createPizza();
    } else if (c == 'L') {
        s = new largePizza;
        p = s->createPizza();
    } else if (c == 'X') {
        s = new xLargePizza;
        p = s->createPizza();
    } else {
        s = new partyPizza;
        p = s->createPizza();
    }

    delete s;

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

    for (auto c : addOnsSelected) {
        if (c == 'G') {
            p = new GlutenFree(p);
        } else if (c == 'S') {
            p = new StuffedCrust(p);
        } else if (c == 'T') {
            p = new ThinCrust(p);
        } else {
            p = new VeganCheese(p);
        }
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

    out << endl << "Your order: " << endl << "  " << p->getRepresentation() << endl << endl;

    return p;
}
    
void Controller::payBill(vector<Pizza*> order) {
    float tipPercentage = 0;
    float totalPrice = 0;
    float price;

    out << "Your order:" << endl;

    for (auto p : order) {
        price = p->getPrice();
        totalPrice += price;
        out << p->getRepresentation() << endl;
    }
        
    out << "Your total price is: $" << fixed << setprecision(2) << totalPrice << endl;

    out << endl << "Ontario Tax Rate is 13%: $" << fixed << setprecision(2) << totalPrice*0.13 << endl;
	totalPrice *= 1.13;

	out << "Total Price: $" << fixed << setprecision(2) << totalPrice << endl << endl;

	while (true) {
			try {
				out << "Enter your tip percentage (in %): ";
				in >> tipPercentage;
				if (in.fail()) {
					throw 1;
				} else if (tipPercentage < 0) {
					throw 2;
				} else {
					break;
				}
			} catch (int err) {
				if (err == 1) {
					out << "You must enter a number. Try again." << endl;
					cin.clear();
					cin.ignore(10000, '\n');
				} else {
					out << "You must enter a positive number. Try again." << endl;
				}
			}
		}

	out << "Tip is " << tipPercentage << "%: $" << totalPrice*tipPercentage/100 << endl << endl;
	if (tipPercentage > 0) { out << "Thank you for the tip!" << endl; }

	totalPrice *= (1 + tipPercentage/100);

	out << "Total Price: $" << fixed << setprecision(2) << totalPrice << endl;
}

bool another(istream& in, ostream&out) {
    bool anotherOne = false;
    char c;

    while (true) {
        out << "Would you like to order another? ('Y'/'N'): ";
        in >> c;
        c = toupper(c);
        if (c == 'Y') {
            anotherOne = true;
            break;
        } else if (c == 'N') {
            break;
        } else {
            out << "Invalid input. ";
			cin.clear();
			cin.ignore(10000, '\n');
        }
    }
    out << endl;
    return anotherOne;
}

void Controller::run() {
    out << "Hi! This is PizzaTime, a pizza pop-up shop celebrating the summer." << endl;
    
    vector<Pizza*> order;
    Pizza* p = NULL;

    do {
        p = takePizzaOrder();
        order.emplace_back(p);
    } while (another(in, out));

    payBill(order);

    for (auto& a : order) { delete a; }
}