#include <iostream>

class Controller {
	std::istream& in;
	std::ostream& out;
  public:
	Controller(std::istream& in, std::ostream& out);
	void takeOrder();
	void payBill();
	void run();
};
