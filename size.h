#ifndef __SIZE_H__
#define __SIZE_H__

#include <vector>
#include <string>

class Pizza;


class PizzaSize {
  public:

    static const std::vector<std::string> possibleSizes;
    virtual Pizza* createPizza() = 0;
};

class smallPizza : public PizzaSize {
  public:
    Pizza* createPizza() override;
};

class mediumPizza : public PizzaSize {
  public:
    Pizza* createPizza() override;
};

class largePizza : public PizzaSize {
  public:
    Pizza* createPizza() override;
};

class xLargePizza : public PizzaSize {
  public:
    Pizza* createPizza() override;
};

class partyPizza : public PizzaSize {
  public:
    Pizza* createPizza() override;
};

#endif