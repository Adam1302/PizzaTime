#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__


#include "pizzaViewer.h"
#include <vector>

class Pizza;

class Controller {
	std::istream& in;
	std::ostream& out;
	PizzaViewer view;
  public:
	Controller(std::istream& in, std::ostream& out);
	Pizza* getSize();
	Pizza* getToppings(Pizza* p);
	Pizza* getAddOns(Pizza* p);
	void displayMenu();
	Pizza* takePizzaOrder();
	void payBill(std::vector<Pizza*> order);
	void run();
};

#endif