#include "size.h"
#include "pizza.h"

const std::vector<std::string> PizzaSize::possibleSizes = {
    "Small", "Medium", "Large", "X-Large", "Party"
};

Pizza* smallPizza::createPizza() {
    Pizza* p = new PlainPizza(6.99, PizzaSize::possibleSizes[0]);
    return p;
}

Pizza* mediumPizza::createPizza() {
    Pizza* p = new PlainPizza(10.99, PizzaSize::possibleSizes[1]);
    return p;
}

Pizza* largePizza::createPizza() {
    Pizza* p = new PlainPizza(14.99, PizzaSize::possibleSizes[2]);
    return p;
}

Pizza* xLargePizza::createPizza() {
    Pizza* p = new PlainPizza(18.99, PizzaSize::possibleSizes[3]);
    return p;
}

Pizza* partyPizza::createPizza() {
    Pizza* p = new PlainPizza(24.99, PizzaSize::possibleSizes[4]);
    return p;
}