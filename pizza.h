#ifndef __PIZZA_H__
#define __PIZZA_H__

#include <iostream>
#include <vector>
#include <string>
#include <map>

class Pizza { // This is our Pizza superclass that is pure virtual
  protected:
	const float price;
	const std::string description;
  public:

  static const std::map<std::string, float> addOns;
  static const std::vector<std::string> toppingList;
  static const std::map<char, std::string> addOnMap;

	Pizza(float price, std::string description);
	virtual float getPrice() const = 0;
	virtual std::string getRepresentation() const = 0;
	virtual ~Pizza();
};


class PlainPizza : public Pizza { // A plain pizza which we can build off (i.e., which we can 'decorate')
  public:
	PlainPizza(float price, std::string size);
	float getPrice() const override;
	std::string getRepresentation() const override;
};

class Decorator : public Pizza { // This, too, is a pure virtual superclass for Pizza with toppings
  protected:
	Pizza* base; // Our pizza will function as a linked list
  public:
	Decorator (float price, std::string description, Pizza* base);
	float getPrice() const override;
	std::string getRepresentation() const override;
    virtual ~Decorator() = 0;
};

class GlutenFree : public Decorator {
  public:
	GlutenFree(Pizza* base);
};

class VeganCheese : public Decorator {
  public:
	VeganCheese(Pizza* base);
};


class ThinCrust : public Decorator {
  public:
	ThinCrust(Pizza* base);
};

class StuffedCrust : public Decorator {
  public:
    StuffedCrust(Pizza* base);
};

class Topping : public Decorator {
	std::string name;
  public:
	Topping(Pizza* base, std::string name);
};

#endif