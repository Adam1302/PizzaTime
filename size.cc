#include "size.h"
#include "pizza.h"

const std::vector<std::string> PizzaSize::possibleSizes = {
    "Small", "Medium", "Large", "X-Large", "Party"
};

Pizza* smallPizza::createPizza() {
    Pizza* p = new PlainPizza(6.99, PizzaSize::possibleSizes[0]); // change this to a 'return make_unique' for RAII
    return p;
}

Pizza* mediumPizza::createPizza() {
    Pizza* p = new PlainPizza(10.99, PizzaSize::possibleSizes[1]); // change this to a 'return make_unique' for RAII
    return p;
}

Pizza* largePizza::createPizza() {
    Pizza* p = new PlainPizza(14.99, PizzaSize::possibleSizes[2]); // change this to a 'return make_unique' for RAII
    return p;
}

Pizza* xLargePizza::createPizza() {
    Pizza* p = new PlainPizza(18.99, PizzaSize::possibleSizes[3]); // change this to a 'return make_unique' for RAII
    return p;
}

Pizza* partyPizza::createPizza() {
    Pizza* p = new PlainPizza(24.99, PizzaSize::possibleSizes[4]); // change this to a 'return make_unique' for RAII
    return p;
}