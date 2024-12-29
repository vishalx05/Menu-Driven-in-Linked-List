#include <bits/stdc++.h>
using namespace std;
#include <conio.h>

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int d) {
        value = d;
        next = nullptr;
        prev = nullptr;
    }
};

void forwardTraversal(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " <--> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void backward(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    while (temp) {
        cout << temp->value << " <--> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

void insertAtEnd(Node*& head, int val) {
    Node* newnode = new Node(val);
    if (head == nullptr) {
        head = newnode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void insertAtStart(Node*& head, int val) {
    Node* newnode = new Node(val);
    if (head == nullptr) {
        head = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insertk(Node*& head, int val, int k) {
    if (k == 1) {
        insertAtStart(head, val);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < k - 1; i++) {
        if (temp == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        temp = temp->next;
    }
    Node* newnode = new Node(val);
    if (temp->next) {
        temp->next->prev = newnode;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}

void deleteHead(Node*& head) {
    if (head == nullptr) {
        cout << "List is already empty." << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* newhead = head;
    head = head->next;
    head->prev = nullptr;
    delete newhead;
}

void deleteLast(Node*& head) {
    if (head == nullptr) {
        cout << "List is already empty." << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    Node* newlast = temp->prev;
    newlast->next = nullptr;
    delete temp;
}

void deleteMiddle(Node*& head, int k) {
    if (k == 1) {
        deleteHead(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < k - 1; i++) {
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        temp = temp->next;
    }
    Node* delnode = temp->next;
    temp->next = delnode->next;
    if (delnode->next) {
        delnode->next->prev = temp;
    }
    delete delnode;
}

void reverse2(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    Node* current = head;
    Node* back = nullptr;
    while (current) {
        back = current->prev;
        current->prev = current->next;
        current->next = back;
        current = current->prev;
    }
    head = back->prev;
}

void heading() {
    system("cls");

    cout << "\n";
    for (int i = 0; i < 60; i++) {
        cout << "=";
    }
    cout << endl;
    cout << "                 DOUBLE LINKED LIST ";
    cout << "\n";
    for (int i = 0; i < 60; i++) {
        cout << "=";
    }
    cout << endl;
}

int main() {
    system("cls");
    Node* head = nullptr;

    p:
    heading();
    cout << "\n1.INSERTION \n";
    cout << "2.DELETION \n";
    cout << "3.FORWARD TRAVERSAL \n";
    cout << "4.BACKWARD TRAVERSAL \n";
    cout << "5.REVERSE \n";
    cout << "6.EXIT \n";

    int choice;
    cout << "ENTER YOUR CHOICE: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "\nINSERTION: \n";
            cout << "a. Insert at Start\n";
            cout << "b. Insert at End\n";
            cout << "c. Insert at Position\n";
            char subch;
            cin >> subch;
            int val;
            cout << "Enter the value: ";
            cin >> val;

            if (subch == 'a') {
                insertAtStart(head, val);
            } else if (subch == 'b') {
                insertAtEnd(head, val);
            } else if (subch == 'c') {
                int k;
                cout << "Enter the position: ";
                cin >> k;
                insertk(head, val, k);
            } else {
                cout << "INVALID CHOICE.\n";
            }
            break;
        }

        case 2: {
            cout << "\nDELETION: \n";
            cout << "a. Delete Head\n";
            cout << "b. Delete Last\n";
            cout << "c. Delete at Position\n";
            char subch;
            cin >> subch;

            if (subch == 'a') {
                deleteHead(head);
            } else if (subch == 'b') {
                deleteLast(head);
            } else if (subch == 'c') {
                int k;
                cout << "Enter the position: ";
                cin >> k;
                deleteMiddle(head, k);
            } else {
                cout << "INVALID CHOICE.\n";
            }
            break;
        }

        case 3:
            cout << "FORWARD LINKED LIST:\n";
            forwardTraversal(head);
            break;

        case 4:
            cout << "BACKWARD LINKED LIST:\n";
            backward(head);
            break;

        case 5:
            cout << "REVERSE LINKED LIST:\n";
            reverse2(head);
            break;

        case 6:
            exit(0);

        default:
            cout << "INVALID OPTION.\n";
            break;
    }

    getch();
    goto p;
}





