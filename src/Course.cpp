#include "Course.hpp"
#include <iostream>

Course::Course(int ID, const std::string &name, int capacity)
    : ID(ID), name(name), capacity(capacity), next(nullptr), tail(nullptr)
{
}

int Course::getID() const
{
    return ID;
}
const std::string &Course::getName() const
{
    return name;
}
int Course::getCapacity() const
{
    return capacity;
}

void Course::setID(int ID)
{
    this->ID = ID;
}
void Course::setName(const std::string &name)
{
    this->name = name;
}
void Course::setCapacity(int capacity)
{
    this->capacity = capacity;
}

Course *Course::getNext() const
{
    return next;
}
void Course::setNext(Course *next)
{
    this->next = next;
}

void Course::remove(int ID)
{
    Course *current = head;
    Course *prev = nullptr;
    while (current) {
        if (current->getID() == ID) {
            if (prev) {
                prev->setNext(current->getNext());
            } else {
                head = current->getNext();
            }
            if (current == tail) {
                tail = prev;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->getNext();
    }
}

Course *Course::find(int ID)
{
    Course *current = head;
    while (current) {
        if (current->getID() == ID) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

Course *Course::getHead()
{
    return head;
}

void Course::setHead(Course *newHead)
{
    head = newHead;
}

void Course::displayCourses() const
{
    Course *temp = head;
    while (temp) {
        std::cout << "Course ID: " << temp->getID() << ", Course Name: " << temp->getName() << std::endl;
        temp = temp->getNext();
    }
}

Course *Course::getTail()
{
    return tail;
}
void Course::setTail(Course *newTail)
{
    tail = newTail;
}

void Course::add(Course *course)
{
    if (!head) {
        head = course;
        tail = course;
        return;
    }
    tail->setNext(course);
    tail = course;
}