#include <iostream>
#include <vector>
#include <string>

const std::vector<std::string> toppingList = {
	"Anchovies", "Avocado", "Bacon", "Basil", "Black Olives", "Chicken", "Extra Cheese", "Garlic", "Goat Cheese", "Green Olives", "Ham", "Mushroom",
	"Onion", "Pepperoni", "Peppers", "Pineapple", "Prosciutto", "Salami", "Sausage", "Spinach", "Sun-dried Tomatoes"
};

class Pizza { // This is our Pizza superclass that is pure virtual
  protected:
	const float price;
	const std::string description;
  public:
	Pizza(float price, std::string description);
	virtual float getPrice() const = 0;
	virtual std::string getDescription() const = 0;
	virtual ~Pizza();
};


// Maybe make factory method for this (small, medium, large)
class PlainPizza : public Pizza { // A plain pizza which we can build off (i.e., which we can 'decorate')
  public:
	PlainPizza();
	float getPrice() const override;
	std::string getDescription() const override;
};

class Decorator : public Pizza { // This, to, is a pure virtual superclass for Pizza with toppings
  protected:
	Pizza* base; // Our pizza will function as a linked list
  public:
	Decorator (float price, std::string description, Pizza* base);
	float getPrice() const override;
    std::string getDescription() const override;
    virtual ~Decorator() = 0;
};

class GlutenFree : public Decorator {
  public:
	GlutenFree(Pizza* base);
};

class ThinCrust : public Decorator {
  public:
	ThinCrust(Pizza* base);
};

class CheesyCrust : public Decorator {
  public:
    CheesyCrust(Pizza* base);
};

class Topping : public Decorator {
	std::string name;
  public:
	Topping(Pizza* base, std::string name);
};

class Cheese : public Decorator {
	std::string type;
  public:
	Topping(Pizza* base, std::string type);
};