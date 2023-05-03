#ifndef PROFESSOR_HPP_
#define PROFESSOR_HPP_

#include "Course.hpp"
#include "Person.hpp"

class Professor : public Person {
  public:
    Professor(int ID, const std::string &name);
    ~Professor() noexcept = default;

    void addTeachingCourse(Course *course);

    void removeTeachingCourse(int courseID);

    virtual void displayCourses() const;

  private:
    Course *teachingCourses;
};

#endif