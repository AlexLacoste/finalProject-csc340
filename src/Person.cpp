#include "Person.hpp"

/**
 * Constructor for the Person class.
 * @param id The ID of the person.
 * @param name The name of the person.
 */
Person::Person(int id, const std::string &name) : id(id), name(name)
{
}

/**
 * Getter method for retrieving the name of the person.
 * @return The name of the person.
 */
const std::string &Person::getName() const
{
    return name;
}

/**
 * Setter method for updating the name of the person.
 * @param name The new name to set.
 */
void Person::setName(const std::string &name)
{
    this->name = name;
}

/**
 * Getter method for retrieving the ID of the person.
 * @return The ID of the person.
 */
int Person::getId() const
{
    return id;
}

/**
 * Setter method for updating the ID of the person.
 * @param id The new ID to set.
 */
void Person::setId(int id)
{
    this->id = id;
}