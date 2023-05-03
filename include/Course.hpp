#ifndef COURSE_HPP_
#define COURSE_HPP_

#include <string>

class Course {
  public:
    Course(int ID, const std::string &name, int capacity);
    ~Course() noexcept = default;

    void remove(int ID);
    void add(Course *course);
    Course *find(int ID);

    Course *getHead();
    void setHead(Course *newHead);

    Course *getTail();
    void setTail(Course *newHead);

    void displayCourses() const;

    int getID() const;
    const std::string &getName() const;
    int getCapacity() const;

    void setID(int ID);
    void setName(const std::string &name);
    void setCapacity(int capacity);

    Course *getNext() const;
    void setNext(Course *next);

  private:
    int ID;
    std::string name;
    int capacity;
    Course *next;
    Course *head;
    Course *tail;
};

#endif