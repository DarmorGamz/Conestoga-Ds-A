#include <cstddef>
#include <iostream>


class Node {
    public:
        int data;
        Node* next;
};

Node* InsertFront(Node** head_ref, int new_data) {
    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;

    return new_node;
}

void InsertAfter(Node* prev_node, int new_data) {
    if (prev_node == NULL) return;

    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = prev_node->next;

    prev_node->next = new_node;
}

void Append(Node** head_ref, int new_data) {
    Node* new_node = new Node();

    Node* last = *head_ref;

    new_node->data = new_data;

    new_node->next = NULL;

    if(*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
    return;
}

void DeleteFront(Node** head_ref) {
    Node* temp = *head_ref;
    (*head_ref) = (*head_ref)->next;
    delete(temp);
}

void DeleteEnd(Node** head_ref) {
    Node* end = *head_ref;
    Node* prev = NULL;
    while(end->next) {
        prev = end;
        end = end->next;
    }
    prev->next = NULL;
    delete(end);
}

void DeleteMiddle(Node** node_ref) {
    if ((*node_ref)->next->next == NULL) { DeleteEnd(node_ref); }
    Node* toDelete = (*node_ref)->next;
    Node* next = (*node_ref)->next->next;
    (*node_ref)->next = next;
    delete(toDelete);
}

void printList(Node* node)
{
    while(node != NULL)
    {
        std::cout << " " << node->data;
        node = node->next;
    }
}


int main()
{
    Node* head = NULL;

    Append(&head, 6);

    Node* newNode = InsertFront(&head, 1);
    InsertAfter(newNode, 8);
    InsertAfter(newNode, 8);
    InsertAfter(head->next->next, 9);

    std::cout << "Created Linked list is: ";
    printList(head);
    DeleteFront(&head);
    std::cout << "\nCreated Linked list is: ";
    printList(head);
    DeleteMiddle(&head->next);
    std::cout << "\nCreated Linked list is: ";
    printList(head);



    return 0;
}