#include "cappuccino.h"
#include "sub_ingredients.h"
#include <iostream>
Cappuccino::Cappuccino(){
    this->name = "Cappuccino";

    Ingredient* item1 = new Espresso(2);
    Ingredient* item2 = new Milk(2);
    Ingredient* item3 = new MilkFoam(1);
    this->ingredients.push_back(item1);
    this->ingredients.push_back(item2);
    this->ingredients.push_back(item3);

    this->side_items.clear();
}

/* 
    派生类的复制构造函数很重要，当对派生类复制构造时，需要显示指定基类的构造方式，
    不指定则会用默认基类的构造函数。
*/
Cappuccino::Cappuccino(const Cappuccino& cap) : EspressoBased(cap){
    for(const auto& i : cap.side_items) {
        this->side_items.push_back(i->clone());
    }
}

// 当派生类复制赋值时，发现不会调用基类的构造函数
void Cappuccino::operator=(const Cappuccino& cap) {
    if(this == &cap)    return;
    for(const auto& i : side_items)
        delete i;
    side_items.clear();

    for(const auto& i : cap.side_items) {
        this->side_items.push_back(i->clone());
    }
}

Cappuccino::~Cappuccino() {
    for(const auto& i : side_items)
        delete i;
    side_items.clear();
}

std::string Cappuccino::get_name() {
    return name;
}

double Cappuccino::price() {
    double sum{};
    for(const auto& i : ingredients){
        sum += i->price();
    }
    for(const auto& i : side_items){
        sum += i->price();
    }
    return sum;
}

void Cappuccino::add_side_item(Ingredient* side) {
    side_items.push_back(side);
}

std::vector<Ingredient*>& Cappuccino::get_side_items() {
    return side_items;
}