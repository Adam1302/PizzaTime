#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

//#include <iostream>
#include <memory>
#include <set>

#include "pizzaViewer.h"

class Controller {
	std::istream& in;
	std::ostream& out;
	/* std::unique_ptr<PizzaViewer> view; */
	PizzaViewer view;
  public:
	Controller(std::istream& in, std::ostream& out);
	char getSize();
	std::set<int> getToppings();
	std::set<char> getAddOns();
	void displayMenu();
	Pizza* takePizzaOrder();
	void payBill();
	void run();
};

#endif