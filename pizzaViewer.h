#ifndef __PIZZA_VIEWER_H__
#define __PIZZA_VIEWER_H__

#include <iostream>

class PizzaViewer {
  public:
    void displayToppings(std::ostream& out);
    void displaySizes(std::ostream& out);
    void displayAddOns(std::ostream& out);
    void displayOptions(std::ostream& out);
    void displayOrder(std::ostream& out, float price, std::string description);
};

#endif