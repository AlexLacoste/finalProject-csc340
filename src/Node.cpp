#include "Node.hpp"

Node::Node(int ID, void *data) : ID(ID), data(data), next(nullptr) {}

int Node::getID() const {
    return ID;
}

Node *Node::getNext() const {
    return next;
}

void *Node::getData() const {
    return data;
}

void Node::setID(int ID) {
    this->ID = ID;
}

void Node::setNext(Node *next) {
    this->next = next;
}

void Node::setData(void *data) {
    this->data = data;
}