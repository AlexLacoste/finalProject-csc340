#include "Person.hpp"

Person::Person(int id, const std::string &name) : id(id), name(name) {}

const std::string &Person::getName() const {
    return name;
}

void Person::setName(const std::string &name) {
    this->name = name;
}

int Person::getId() const {
    return id;
}

void Person::setId(int id) {
    this->id = id;
}