#include "Person.hpp"

Person::Person(int ID, const std::string &name) : ID(ID), name(name), next(nullptr), prev(nullptr)
{
}

int Person::getID() const
{
    return ID;
}
const std::string &Person::getName() const
{
    return name;
}

void Person::setID(int ID)
{
    this->ID = ID;
}
void Person::setName(const std::string &name)
{
    this->name = name;
}

Person *Person::getNext() const
{
    return next;
}
Person *Person::getPrev() const
{
    return prev;
}

void Person::setNext(Person *next)
{
    this->next = next;
}
void Person::setPrev(Person *prev)
{
    this->prev = prev;
}

void Person::remove(int ID)
{
    Person *person = find(ID);
    if (!person) {
        return;
    }

    if (person->getPrev()) {
        person->getPrev()->setNext(person->getNext());
    } else {
        head = person->getNext();
    }

    if (person->getNext()) {
        person->getNext()->setPrev(person->getPrev());
    }

    delete person;
}

Person *Person::find(int ID)
{
    Person *current = head;
    while (current) {
        if (current->getID() == ID) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

Person *Person::getHead()
{
    return head;
}

void Person::setHead(Person *newHead)
{
    head = newHead;
}