#ifndef NODE_HPP_
#define NODE_HPP_

#include <string>

class Node {
  public:
    /**
     * Constructor for the Node class.
     *
     * @param ID The ID of the node.
     * @param data A pointer to the data stored in the node.
     */
    Node(int ID, void *data);

    /**
     * Default destructor for the Node class.
     */
    ~Node() noexcept = default;

    /**
     * Retrieves the ID of the node.
     *
     * @return The ID of the node.
     */
    int getID() const;

    /**
     * Retrieves the next node in the linked list.
     *
     * @return A pointer to the next node.
     */
    Node *getNext() const;

    /**
     * Retrieves the data stored in the node.
     *
     * @return A pointer to the data stored in the node.
     */
    void *getData() const;

    /**
     * Sets the ID of the node.
     *
     * @param ID The new ID of the node.
     */
    void setID(int ID);

    /**
     * Sets the next node in the linked list.
     *
     * @param next A pointer to the next node.
     */
    void setNext(Node *next);

    /**
     * Sets the data stored in the node.
     *
     * @param data A pointer to the new data to be stored in the node.
     */
    void setData(void *data);

  private:
    int ID;     // The ID of the node.
    void *data; // The data stored in the node.
    Node *next; // A pointer to the next node in the linked list.
};

#endif