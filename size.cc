#include "size.h"
#include "pizza.h"

Pizza* smallPizza::createPizza() {
    Pizza* p = new PlainPizza(6.99, sizes[0]); // change this to a 'return make_unique' for RAII
}

Pizza* mediumPizza::createPizza() {
    Pizza* p = new PlainPizza(10.99, sizes[1]); // change this to a 'return make_unique' for RAII
}

Pizza* largePizza::createPizza() {
    Pizza* p = new PlainPizza(14.99, sizes[2]); // change this to a 'return make_unique' for RAII
}

Pizza* xLargePizza::createPizza() {
    Pizza* p = new PlainPizza(18.99, sizes[3]); // change this to a 'return make_unique' for RAII
}