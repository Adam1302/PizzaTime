class Pizza;

std::vector<std::string> sizes = {
    "Small", "Medium", "Large", "X-Large"
};

class PizzaSize {
  public:
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