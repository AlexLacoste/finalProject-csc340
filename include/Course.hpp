#ifndef COURSE_HPP_
#define COURSE_HPP_

#include <string>
#include <LinkedList.hpp>
#include <Professor.hpp>
#include <Student.hpp>

class Course {
  public:
    Course(int id,const std::string &name, int capacity, const std::string &description);
    ~Course() noexcept = default;

    const std::string &getName() const;
    const std::string &getDescription() const;
    int getCapacity() const;
    Professor *getProfessor() const;
    LinkedList *getStudents() const;
    int getId() const;

    void setName(const std::string &name);
    void setProfessor(Professor *professor);
    void setStudents(LinkedList *studends);
    void setDescription(const std::string &description);
    void setCapacity(int capacity);
    void setId(const int id);

    void addStudents(Student *student);
    void removeStudents(int studentID);

  private:
    std::string name;
    std::string description;
    Professor *professor;
    LinkedList *studends;
    int capacity;
    int id;
};

#endif