#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <iostream>
#include <string>

enum PersonType {
    STUDENT,
    PROFESSOR
};

class Person {
  public:
    Person(int id, const std::string &name);
    virtual ~Person() noexcept = default;

    const std::string &getName() const;
    int getId() const;
    void setName(const std::string &name);
    void setId(int id);

    virtual PersonType getPersonType() const = 0;  // pure virtual function

  protected:
    std::string name;
    int id;
};

#endif
