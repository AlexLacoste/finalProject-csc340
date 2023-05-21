#include "LinkedList.hpp"

LinkedList::LinkedList() : head(nullptr)
{
    /* Constructor for the LinkedList class.
     * Initializes the head pointer to nullptr.
     */
}

void LinkedList::setHead(Node *head)
{
    /* Sets the head of the linked list.
     *
     * @param head A pointer to the Node object representing the new head of the linked list.
     */
    this->head = head;
}

Node *LinkedList::getHead()
{
    /* Retrieves the head of the linked list.
     *
     * @return A pointer to the Node object representing the head of the linked list.
     */
    return head;
}

void LinkedList::push_back(void *data, int id)
{
    /* Adds a new node to the end of the linked list.
     *
     * @param data A pointer to the data to be stored in the new node.
     * @param id The ID of the new node.
     */
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

void LinkedList::remove(int ID)
{
    /* Removes a node from the linked list based on the provided ID.
     *
     * @param ID The ID of the node to be removed.
     */
    Node *current = head;
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

Node *LinkedList::findByID(int ID)
{
    /* Finds a node in the linked list based on the provided ID.
     *
     * @param ID The ID of the node to find.
     * @return A pointer to the Node object representing the found node, or nullptr if not found.
     */
    Node *current = head;
    while (current) {
        if (current->getID() == ID) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

int LinkedList::getSize()
{
    /* Retrieves the size of the linked list.
     *
     * @return The size of the linked list.
     */
    int count = 0;
    Node *current = head;
    while (current) {
        count++;
        current = current->getNext();
    }
    return count;
}