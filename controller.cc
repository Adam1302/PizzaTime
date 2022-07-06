#include "controller.h"

#include "pizza.h"
#include "size.h"
#include "pizzaViewer.h"

using namespace std;

Controller::Controller(std::istream& in, std::ostream& out) :
    //in{in}, out{out}, view{new PizzaViewer()} {}
    in{in}, out{out}, view{} {}

void Controller::displayMenu() {
    out << "Here is our menu:" << endl << endl;

    view.displayOptions(out);
}

void Controller::takeOrder() {
    out << "Pending implementation." << endl;
}
void Controller::payBill() {
    out << "Pending implementation." << endl;
}

void Controller::run() {
    out << "Hi! This is PizzaTime, a pizza pop-up shop celebrating the summer." << endl;
    displayMenu();
    takeOrder();
    payBill();
}