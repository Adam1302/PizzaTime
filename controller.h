#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

//#include <iostream>
#include <memory>

#include "pizzaViewer.h"

class Controller {
	std::istream& in;
	std::ostream& out;
	/* std::unique_ptr<PizzaViewer> view; */
	PizzaViewer view;
  public:
	Controller(std::istream& in, std::ostream& out);
	void displayMenu();
	void takeOrder();
	void payBill();
	void run();
};

#endif