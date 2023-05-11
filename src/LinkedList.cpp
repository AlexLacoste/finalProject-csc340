#include "LinkedList.hpp"

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::setHead(Node *head) {
    this->head = head;
}

Node *LinkedList::getHead() {
    return head;
}

void LinkedList::push_back(void *data, int id) {
    if (!head) {
        head = new Node(id, data);
    } else {
        Node *current = head;
        while (current->getNext()) {
            current = current->getNext();
        }
        current->setNext(new Node(id, data));
    }
}

void LinkedList::remove(Node *node, int ID) {
    Node *current = node;
    Node *prev = nullptr;
    while (current) {
        if (current->getID() == ID) {
            if (prev) {
                prev->setNext(current->getNext());
            } else {
                head = current->getNext();
            }
            delete current;
            return;
        }
        prev = current;
        current = current->getNext();
    }
}

Node *LinkedList::find_by_id(int ID) {
    Node *current = head;
    while (current) {
        if (current->getID() == ID) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

int LinkedList::getSize() {
    int count = 0;
    Node *current = head;
    while (current) {
        count++;
        current = current->getNext();
    }
    return count;
}
