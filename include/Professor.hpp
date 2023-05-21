#ifndef PROFESSOR_HPP_
#define PROFESSOR_HPP_

#include "Person.hpp"

class Professor : public Person {
  public:
    /**
     * Constructor for the Professor class.
     *
     * @param id The ID of the professor.
     * @param name The name of the professor.
     */
    Professor(int id, const std::string &name);

    /**
     * Default destructor for the Professor class.
     */
    ~Professor() noexcept = default;

    /**
     * Overrides the getPersonType function from the base class.
     * Returns the type of the person as PROFESSOR.
     *
     * @return The type of the person (PROFESSOR).
     */
    PersonType getPersonType() const override
    {
        return PROFESSOR;
    }
};

#endif