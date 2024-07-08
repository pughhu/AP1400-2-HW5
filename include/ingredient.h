#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <cstddef>
#include <string>
class Ingredient
{
public:
    virtual ~Ingredient() = default;
    virtual Ingredient* clone() = 0;

    double get_price_unit(){
        return price_unit;
    }
    size_t get_units(){
        return units;
    }
    double price(){
        return price_unit * units;
    }
    virtual std::string get_name() = 0;

protected:
    Ingredient(double price_unit, size_t units): 
        price_unit{price_unit}, units{units} {
    }
    double price_unit;
    size_t units;
    std::string name;
};
#endif // INGREDIENT_H