#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <iostream>
#include <string>

enum PersonType { STUDENT, PROFESSOR };

class Person {
  public:
    /**
     * Constructor for the Person class.
     *
     * @param id The ID of the person.
     * @param name The name of the person.
     */
    Person(int id, const std::string &name);

    /**
     * Virtual destructor for the Person class.
     */
    virtual ~Person() noexcept = default;

    /**
     * Retrieves the name of the person.
     *
     * @return The name of the person.
     */
    const std::string &getName() const;

    /**
     * Retrieves the ID of the person.
     *
     * @return The ID of the person.
     */
    int getId() const;

    /**
     * Sets the name of the person.
     *
     * @param name The new name of the person.
     */
    void setName(const std::string &name);

    /**
     * Sets the ID of the person.
     *
     * @param id The new ID of the person.
     */
    void setId(int id);

    /**
     * Pure virtual function to retrieve the type of the person.
     *
     * @return The type of the person (STUDENT or PROFESSOR).
     */
    virtual PersonType getPersonType() const = 0;

  protected:
    std::string name; // The name of the person.
    int id;           // The ID of the person.
};

#endif
