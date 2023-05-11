#ifndef NODE_HPP_
#define NODE_HPP_

#include <string>

class Node {
  public:
    Node(int ID, void *data);
    ~Node() noexcept = default;

    int getID() const;
    Node *getNext() const;
    void *getData() const;

    void setID(int ID);
    void setNext(Node *next);
    void setData(void *data);

  private:
    int ID;
    void *data;
    Node *next;
};

#endif