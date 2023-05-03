#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include "Course.hpp"
#include "Person.hpp"

class Student : public Person {
  public:
    Student(int ID, const std::string &name);
    ~Student() noexcept = default;

    void enrollCourse(Course *course);

    void dropCourse(int courseID);

    virtual void displayCourses() const;

  private:
    Course *enrolledCourses;
};

#endif
