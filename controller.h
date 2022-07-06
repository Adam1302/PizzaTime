#include <iostream>

class Controller {
	std::istream& in;
	std::ostream& out;
  public:
	Controller(std::istream& in, std::ostream& out);
	void displayMenu();
	void takeOrder();
	void payBill();
	void run();
};
