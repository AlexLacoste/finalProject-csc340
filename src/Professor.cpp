#include "Professor.hpp"

Professor::Professor(int ID, const std::string &name) : Person(ID, name), teachingCourses(nullptr)
{
}

void Professor::addTeachingCourse(Course *course)
{
    teachingCourses->add(course);
}

void Professor::removeTeachingCourse(int courseID)
{
    teachingCourses->remove(courseID);
}

void Professor::displayCourses() const
{
    std::cout << "Teaching courses for professor " << getName() << " (ID: " << getID() << "):" << std::endl;
    teachingCourses->displayCourses();
}