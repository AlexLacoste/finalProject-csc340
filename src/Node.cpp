#include "Node.hpp"

/**
 * Constructor for Node class.
 * @param ID The ID of the node.
 * @param data The data stored in the node.
 */
Node::Node(int ID, void *data) : ID(ID), data(data), next(nullptr)
{
}

/**
 * Getter method for retrieving the ID of the node.
 * @return The ID of the node.
 */
int Node::getID() const
{
    return ID;
}

/**
 * Getter method for retrieving the next node.
 * @return Pointer to the next node.
 */
Node *Node::getNext() const
{
    return next;
}

/**
 * Getter method for retrieving the data stored in the node.
 * @return Pointer to the data.
 */
void *Node::getData() const
{
    return data;
}

/**
 * Setter method for updating the ID of the node.
 * @param ID The new ID to set.
 */
void Node::setID(int ID)
{
    this->ID = ID;
}

/**
 * Setter method for updating the next node.
 * @param next Pointer to the next node.
 */
void Node::setNext(Node *next)
{
    this->next = next;
}

/**
 * Setter method for updating the data stored in the node.
 * @param data Pointer to the new data.
 */
void Node::setData(void *data)
{
    this->data = data;
}