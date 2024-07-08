#include "mocha.h"
#include "sub_ingredients.h"

Mocha::Mocha(){
    this->name = "Mocha";

    Ingredient* item1 = new Espresso(2);
    Ingredient* item2 = new Milk(2);
    Ingredient* item3 = new MilkFoam(1);
    Ingredient* item4 = new Chocolate(1);
    this->ingredients.push_back(item1);
    this->ingredients.push_back(item2);
    this->ingredients.push_back(item3);
    this->ingredients.push_back(item4);

    this->side_items.clear();
}

Mocha::Mocha(const Mocha& cap) : EspressoBased{cap}{
    for(const auto& i : cap.side_items) {
        this->side_items.push_back(i->clone());
    }
}

void Mocha::operator=(const Mocha& cap) {
    if(this == &cap)    return;

    for(const auto& i : side_items)
        delete i;
    side_items.clear();

    for(const auto& i : cap.side_items) {
        this->side_items.push_back(i->clone());
    }
}

Mocha::~Mocha() {
    for(const auto& i : side_items)
        delete i;
    side_items.clear();
}

std::string Mocha::get_name() {
    return name;
}

double Mocha::price() {
    double sum{};
    for(const auto& i : ingredients){
        sum += i->price();
    }
    for(const auto& i : side_items){
        sum += i->price();
    }
    return sum;
}

void Mocha::add_side_item(Ingredient* side) {
    side_items.push_back(side);
}

std::vector<Ingredient*>& Mocha::get_side_items() {
    return side_items;
}