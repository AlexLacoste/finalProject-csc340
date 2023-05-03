#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <iostream>
#include <string>

class Person {
  public:
    Person(int ID, const std::string &name);
    virtual ~Person() noexcept = default;

    int getID() const;
    const std::string &getName() const;

    void setID(int ID);
    void setName(const std::string &name);

    Person *getNext() const;
    Person *getPrev() const;

    void setNext(Person *next);
    void setPrev(Person *prev);

    void remove(int ID);
    Person *find(int ID);

    Person *getHead();
    void setHead(Person *newHead);

    virtual void displayCourses() const = 0;

  protected:
  private:
    int ID;
    std::string name;
    Person *next;
    Person *prev;
    Person *head;
};

#endif