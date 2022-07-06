#include "controller.h"
#include "pizza.h"

using namespace std;

Controller::Controller(std::istream& in, std::ostream& out) :
    in{in}, out{out} {}

void Controller::displayMenu() {
    out << "Here is our menu:" << endl;
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