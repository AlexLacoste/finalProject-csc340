#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_

#include <string>
#include <Node.hpp>

class LinkedList {
  public:
    LinkedList();
    ~LinkedList() noexcept = default;

    void setHead(Node *head);

    Node *getHead();

    void remove(Node *,int ID);
    void push_back(void *data, int id);
    int getSize();
    Node *find_by_id(int ID);

  private:
    Node *head;
};

#endif