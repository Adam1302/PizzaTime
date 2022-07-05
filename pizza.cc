#include "pizza.h"

using namespace std;


/*
float PlainPizza::Pizza::price = 8.99; // If this doesn't work, make constructors
string PlainPizza::description = "Cheese Pizza";
float ThinCrust::price = 1.00; // If this doesn't work, make constructors
string ThinCrust::description = " with thin crust";
float CheesyCrust::price = 2.99; // If this doesn't work, make constructors
string CheesyCrust::description = " with stuffed crust";
float Topping::price = 8.99; // If this doesn't work, make constructors
string Topping::description = " with " + name;
*/


Pizza::Pizza(float price, string description) : price{price}, description{description} {}
Pizza::~Pizza() {}

PlainPizza::PlainPizza() : Pizza{8.99, "Pizza"} {}
float PlainPizza::getPrice() const {
    return price;
}
string PlainPizza::getDescription() const {
    return description;
}


Decorator::Decorator(float price, string description, Pizza* base) : Pizza{price, description}, base{base} {}
float Decorator::getPrice() const { 
    return base->getPrice() + price;
}
string Decorator::getDescription() const {
    return base->getDescription() + description;
}
Decorator::~Decorator() { delete base; }


ThinCrust::ThinCrust(Pizza* base) : Decorator{1.00, " with thin crust", base} {}

CheesyCrust::CheesyCrust(Pizza* base) : Decorator{2.99, " with stuffed crust", base} {}

Topping::Topping(Pizza* base, string name) : Decorator{0.75, " with" + name, base}, name{name} {}
