#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

//#include <iostream>
#include <memory>
#include <set>

#include "pizzaViewer.h"

class Pizza;

class Controller {
	std::istream& in;
	std::ostream& out;
	/* std::unique_ptr<PizzaViewer> view; */
	PizzaViewer view;
  public:
	Controller(std::istream& in, std::ostream& out);
	Pizza* getSize();
	Pizza* getToppings(Pizza* p);
	Pizza* getAddOns(Pizza* p);
	void displayMenu();
	Pizza* takePizzaOrder();
	void payBill();
	void run();
};

#endif