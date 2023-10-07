#include <iostream>
using namespace std;

// CREATING STRUCTURE OF CIRCULAR LINKED LIST
struct NODE {
    int data;
    NODE* next;
};

// CREATING TAIL POINTER THAT WILL STORE LAST NODE
NODE* tail = NULL;

// GLOBALLY STORE THE SIZE OF NODES
int count = 0;

// Structure for a circular linked list
struct CircularLinkedList {
    NODE* head = NULL;

    // Insert a node at the end of the list
    void insert_end(int x) {
        NODE* new_node = new NODE();
        new_node->data = x;

        if (head == NULL) {
            new_node->next = new_node;
            head = new_node;
        }
        else {
            NODE* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = head;
        }
    }

    // Display the circular linked list
    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        NODE* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    // Insert some nodes into the circular linked list
    for (int i = 1; i <= 6; ++i) {
        insert_end(i);
    }

    // Check if the total nodes are even
    bool isEven = (count % 2 == 0);

    if (isEven) {
        // Split the circular linked list into two lists (even number of nodes)
        CircularLinkedList list1, list2;
        NODE* current = tail->next;
        for (int i = 0; i < count / 2; ++i) {
            list1.insert_end(current->data);
            current = current->next;
        }
        for (int i = count / 2; i < count; ++i) {
            list2.insert_end(current->data);
            current = current->next;
        }

        // Display the two split lists
        cout << "First List: ";
        list1.display();
        cout << "Second List: ";
        list2.display();
    }
    else {
        // Handle odd number of nodes (not implemented in this example)
        cout << "Odd number of nodes. Logic for odd nodes not implemented." << endl;
    }

    return 0;
}

