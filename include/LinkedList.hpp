#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_

#include <Node.hpp>
#include <string>

class LinkedList {
  public:
    /**
     * Constructor for the LinkedList class.
     */
    LinkedList();

    /**
     * Default destructor for the LinkedList class.
     */
    ~LinkedList() noexcept = default;

    /**
     * Sets the head of the linked list.
     *
     * @param head A pointer to the Node object representing the new head of the linked list.
     */
    void setHead(Node *head);

    /**
     * Retrieves the head of the linked list.
     *
     * @return A pointer to the Node object representing the head of the linked list.
     */
    Node *getHead();

    /**
     * Removes a node from the linked list based on the provided ID.
     *
     * @param ID The ID of the node to be removed.
     */
    void remove(int ID);

    /**
     * Adds a new node to the end of the linked list.
     *
     * @param data A pointer to the data to be stored in the new node.
     * @param id The ID of the new node.
     */
    void push_back(void *data, int id);

    /**
     * Retrieves the size of the linked list.
     *
     * @return The size of the linked list.
     */
    int getSize();

    /**
     * Finds a node in the linked list based on the provided ID.
     *
     * @param ID The ID of the node to find.
     * @return A pointer to the Node object representing the found node, or nullptr if not found.
     */
    Node *findByID(int ID);

  private:
    Node *head; // The head of the linked list.
};

#endif