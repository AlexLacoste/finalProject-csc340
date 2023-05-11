#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include "Person.hpp"

class Student : public Person {
  public:
    Student(int id, const std::string &name);
    ~Student() noexcept = default;

    PersonType getPersonType() const override { return STUDENT; }
};

#endif
