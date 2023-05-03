#include "Student.hpp"

Student::Student(int ID, const std::string &name) : Person(ID, name), enrolledCourses(nullptr)
{
}

void Student::enrollCourse(Course *course)
{
    enrolledCourses->add(course);
}

void Student::dropCourse(int courseID)
{
    enrolledCourses->remove(courseID);
}

void Student::displayCourses() const
{
    std::cout << "Enrolled courses for student " << getName() << " (ID: " << getID() << "):" << std::endl;
    enrolledCourses->displayCourses();
}