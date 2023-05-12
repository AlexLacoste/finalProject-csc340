#ifndef PROFESSOR_HPP_
#define PROFESSOR_HPP_

#include "Person.hpp"

class Professor : public Person {
  public:
    Professor(int id, const std::string &name);
    ~Professor() noexcept = default;

    PersonType getPersonType() const override
    {
        return PROFESSOR;
    }
};

#endif