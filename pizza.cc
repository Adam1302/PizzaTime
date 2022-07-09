#include <iostream>
#include <sstream>
#include <iomanip>
#include "pizza.h"

using namespace std;

const map<string, float> Pizza::addOns = {
		{"Stuffed Crust", 2.99}, {"Thin Crust", 0.99},
		{"Gluten-Free", 2.29}, {"Vegan Cheese", 1.99}
	};


const map<char, string> Pizza::addOnMap = {
	{'S', "Stuffed Crust"}, {'T', "Thin Crust"},
	{'G', "Gluten-Free"}, {'V', "Vegan Cheese"}
};

const std::vector<std::string> Pizza::toppingList = {
	"Anchovies", "Avocado", "Bacon", "Basil", "Black Olives", "Chicken", "Extra Cheese", "Garlic", "Goat Cheese", "Green Olives", "Ham", "Mushroom",
	"Onion", "Pepperoni", "Peppers", "Pineapple", "Prosciutto", "Salami", "Sausage", "Spinach", "Sun-dried Tomatoes"
};


Pizza::Pizza(float price, string description) : price{price}, description{description} {}
Pizza::~Pizza() {}

PlainPizza::PlainPizza(float price, string size) : Pizza{price, size + " Pizza:"} {}
float PlainPizza::getPrice() const {
    return price;
}
string PlainPizza::getRepresentation() const {
	ostringstream oss;
	oss << "+ " << description << "... $" << fixed << setprecision(2) << price << endl;
	return oss.str();
}


Decorator::Decorator(float price, string description, Pizza* base) : Pizza{price, description}, base{base} {}
float Decorator::getPrice() const { 
    return base->getPrice() + price;
}
string Decorator::getRepresentation() const {
	ostringstream oss;
	ostringstream oss2;
	oss << base->getRepresentation();
	oss2 << "\t(+ " << description << ")";
	oss << left << setw(24) << oss2.str() << fixed << setprecision(2) << "$" << price << endl;
	return oss.str();
}
Decorator::~Decorator() { delete base; }

GlutenFree::GlutenFree(Pizza* base) : Decorator{addOns.at("Gluten-Free"), "Gluten-free", base} {}

VeganCheese::VeganCheese(Pizza* base) : Decorator{addOns.at("Vegan Cheese"), "Vegan Cheese (soy)", base} {}

ThinCrust::ThinCrust(Pizza* base) : Decorator{addOns.at("Thin Crust"), "Thin Crust", base} {}

StuffedCrust::StuffedCrust(Pizza* base) : Decorator{addOns.at("Stuffed Crust"), "Stuffed Crust", base} {}

Topping::Topping(Pizza* base, string name) : Decorator{0.75, name, base}, name{name} {}
