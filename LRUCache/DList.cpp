/** Doubly Linked List Implementation 
 * 
 * O(1) insertion at last
 * O(1) deletion
 **/


/** Definition of a node for doublylinkedlist **/
class Node
{
private:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int d)
    {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
    int getData()
    {
        return data;
    }

    friend class DList;
};

class DList
{
    Node *first;
    Node *last;
public:
    DList()
    {
        first = last = nullptr;
    }
    
    void insertLast(Node *n)
    {
        if(last == nullptr)
        {
            first = last = n;
            return;
        }

        last->next = n;
        n->prev = last;
        last = n;
    }

    void detachNode(Node *n)
    {
        if(n == first)
        first = first->next;
        if(n == last)
            last = last->prev;

        if(n->prev != nullptr)
        {
            n->prev->next = n->next;
        }

        if(n->next != nullptr)
        {
            n->next->prev = n->prev;
        }

        n->next = nullptr;
        n->prev = nullptr;
    }


    Node *getFirst()
    {
        return first;
    }


    Node *getLast()
    {
        return last;
    }
};

