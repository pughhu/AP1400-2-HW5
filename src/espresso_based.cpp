#include "espresso_based.h"

#include <iostream>
#include <vector>

void EspressoBased::brew() {
    std::cout<<"hello world."<<std::endl;
}

std::vector<Ingredient*>& EspressoBased::get_ingredients(){
    return ingredients;
}

EspressoBased::~EspressoBased()
{
    for(const auto& i : ingredients)
        delete i;
    ingredients.clear();
}

EspressoBased::EspressoBased() {
    // do nothing
    // std::cout<<"EspressoBased() is invoked."<<std::endl;
}

EspressoBased::EspressoBased(const EspressoBased& esp){
    // std::cout<<"EspressBased(const EspressoBased& esp) is invoked."<<std::endl;
    this->name = esp.name;
    for(const auto& i : esp.ingredients) {
        this->ingredients.push_back(i->clone());
    }
}

void EspressoBased::operator=(const EspressoBased& esp){
    // std::cout<<"operator=(const EspressoBased& esp) is invoked."<<std::endl;
    if(this == &esp)    return;

    for(const auto& i : ingredients)
        delete i;
    ingredients.clear();

    this->name = esp.name;
    for(const auto& i : esp.ingredients) {
        this->ingredients.push_back(i->clone());
    }
}