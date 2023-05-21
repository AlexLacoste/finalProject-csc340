#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include "Person.hpp"

class Student : public Person {
  public:
    /**
     * Constructor for the Student class.
     *
     * @param id The ID of the student.
     * @param name The name of the student.
     */
    Student(int id, const std::string &name);

    /**
     * Default destructor for the Student class.
     */
    ~Student() noexcept = default;

    /**
     * Overrides the getPersonType function from the base class.
     * Returns the type of the person as STUDENT.
     *
     * @return The type of the person (STUDENT).
     */
    PersonType getPersonType() const override
    {
        return STUDENT;
    }
};

#endif
