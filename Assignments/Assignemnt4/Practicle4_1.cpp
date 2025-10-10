#include <iostream>
#include <string>
using namespace std;

struct CallLog {
    string name;
    string number;
    CallLog* next;
};

CallLog* head = NULL;


CallLog* createContact(string name, string number) {
    CallLog* newNode = new CallLog;
    newNode->name = name;
    newNode->number = number;
    newNode->next = NULL;
    return newNode;
}


void insertAtBegin(string name, string number) {
    CallLog* newNode = createContact(name, number);
    newNode->next = head;
    head = newNode;
    cout << "Contact inserted at beginning.\n";
}


void insertAtEnd(string name, string number) {
    CallLog* newNode = createContact(name, number);
    if (head == NULL) {
        head = newNode;
    } else {
        CallLog* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Contact inserted at end.\n";
}


void insertAtPosition(string name, string number, int pos) {
    CallLog* newNode = createContact(name, number);
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        cout << "Contact inserted at position " << pos << ".\n";
        return;
    }
    CallLog* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Position out of range.\n";
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Contact inserted at position " << pos << ".\n";
}


void deleteAtBegin() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    CallLog* temp = head;
    head = head->next;
    delete temp;
    cout << "Contact deleted from beginning.\n";
}


void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        CallLog* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }
    cout << "Contact deleted from end.\n";
}


void deleteAtPosition(int pos) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (pos == 1) {
        CallLog* temp = head;
        head = head->next;
        delete temp;
        cout << "Contact deleted from position 1.\n";
        return;
    }
    CallLog* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of range.\n";
        return;
    }
    CallLog* del = temp->next;
    temp->next = del->next;
    delete del;
    cout << "Contact deleted from position " << pos << ".\n";
}


void searchContact(string name) {
    CallLog* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->name == name) {
            cout << "Contact found at position " << pos << ":\n";
            cout << "Name: " << temp->name << " | Number: " << temp->number << "\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Contact not found.\n";
}


void displayLogs() {
    if (head == NULL) {
        cout << "Call log is empty.\n";
        return;
    }
    CallLog* temp = head;
    cout << "\n--- Call Log ---\n";
    while (temp != NULL) {
        cout << "Name: " << temp->name << " | Number: " << temp->number << "\n";
        temp = temp->next;
    }
    cout << "----------------\n";
}


void reverseList() {
    CallLog *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    cout << "Call log reversed.\n";
}


int main() {
    int choice, pos;
    string name, number;

    do {
        cout << "\n===== Call Log Management =====\n";
        cout << "1. Insert Contact at Begin\n";
        cout << "2. Insert Contact at End\n";
        cout << "3. Insert Contact at Position\n";
        cout << "4. Delete Contact at Begin\n";
        cout << "5. Delete Contact at End\n";
        cout << "6. Delete Contact at Position\n";
        cout << "7. Search Contact in Log\n";
        cout << "8. Display Call Log\n";
        cout << "9. Reverse Call Log List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name and number: ";
                cin >> name >> number;
                insertAtBegin(name, number);
                break;
            case 2:
                cout << "Enter name and number: ";
                cin >> name >> number;
                insertAtEnd(name, number);
                break;
            case 3:
                cout << "Enter name, number and position: ";
                cin >> name >> number >> pos;
                insertAtPosition(name, number, pos);
                break;
            case 4:
                deleteAtBegin();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deleteAtPosition(pos);
                break;
            case 7:
                cout << "Enter name to search: ";
                cin >> name;
                searchContact(name);
                break;
            case 8:
                displayLogs();
                break;
            case 9:
                reverseList();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);
    return 0;
}


/* Output :
    ===== Call Log Management =====
    1. Insert Contact at Begin
    2. Insert Contact at End
    3. Insert Contact at Position
    4. Delete Contact at Begin
    5. Delete Contact at End
    6. Delete Contact at Position
    7. Search Contact in Log
    8. Display Call Log
    9. Reverse Call Log List
    0. Exit
    Enter your choice: 1
    Enter name and number: Nikheel 9019309774
    Contact inserted at beginning.

    ===== Call Log Management =====
    1. Insert Contact at Begin
    2. Insert Contact at End
    3. Insert Contact at Position
    4. Delete Contact at Begin
    5. Delete Contact at End
    6. Delete Contact at Position
    7. Search Contact in Log
    8. Display Call Log
    9. Reverse Call Log List
    0. Exit
    Enter your choice: 2
    Enter name and number: Swapnil 7053982734
    Contact inserted at end.

    ===== Call Log Management =====
    1. Insert Contact at Begin
    2. Insert Contact at End
    3. Insert Contact at Position
    4. Delete Contact at Begin
    5. Delete Contact at End
    6. Delete Contact at Position
    7. Search Contact in Log
    8. Display Call Log
    9. Reverse Call Log List
    0. Exit
    Enter your choice: 3
    Enter name, number and position: Vvk 9827635172 1
    Contact inserted at position 1.

    ===== Call Log Management =====
    1. Insert Contact at Begin
    2. Insert Contact at End
    3. Insert Contact at Position
    4. Delete Contact at Begin
    5. Delete Contact at End
    6. Delete Contact at Position
    7. Search Contact in Log
    8. Display Call Log
    9. Reverse Call Log List
    0. Exit
    Enter your choice: 4
    Contact deleted from beginning.

    ===== Call Log Management =====
    1. Insert Contact at Begin
    2. Insert Contact at End
    3. Insert Contact at Position
    4. Delete Contact at Begin
    5. Delete Contact at End
    6. Delete Contact at Position
    7. Search Contact in Log
    8. Display Call Log
    9. Reverse Call Log List
    0. Exit
    Enter your choice: 6
    Enter position: 4
    Position out of range.

    ===== Call Log Management =====
    1. Insert Contact at Begin
    2. Insert Contact at End
    3. Insert Contact at Position
    4. Delete Contact at Begin
    5. Delete Contact at End
    6. Delete Contact at Position
    7. Search Contact in Log
    8. Display Call Log
    9. Reverse Call Log List
    0. Exit
    Enter your choice: 7
    Enter name to search: Vvk
    Contact not found.

    ===== Call Log Management =====
    1. Insert Contact at Begin
    2. Insert Contact at End
    3. Insert Contact at Position
    4. Delete Contact at Begin
    5. Delete Contact at End
    6. Delete Contact at Position
    7. Search Contact in Log
    8. Display Call Log
    9. Reverse Call Log List
    0. Exit
    Enter your choice: 8

    --- Call Log ---
    Name: Nikheel | Number: 9019309774
    Name: Swapnil | Number: 7053982734
    ----------------

    ===== Call Log Management =====
    1. Insert Contact at Begin
    2. Insert Contact at End
    3. Insert Contact at Position
    4. Delete Contact at Begin
    5. Delete Contact at End
    6. Delete Contact at Position
    7. Search Contact in Log
    8. Display Call Log
    9. Reverse Call Log List
    0. Exit
    Enter your choice: 9
    Call log reversed.

    ===== Call Log Management =====
    1. Insert Contact at Begin
    2. Insert Contact at End
    3. Insert Contact at Position
    4. Delete Contact at Begin
    5. Delete Contact at End
    6. Delete Contact at Position
    7. Search Contact in Log
    8. Display Call Log
    9. Reverse Call Log List
    0. Exit
    Enter your choice: 8

    --- Call Log ---
    Name: Swapnil | Number: 7053982734
    Name: Nikheel | Number: 9019309774
    ----------------

    ===== Call Log Management =====
    1. Insert Contact at Begin
    2. Insert Contact at End
    3. Insert Contact at Position
    4. Delete Contact at Begin
    5. Delete Contact at End
    6. Delete Contact at Position
    7. Search Contact in Log
    8. Display Call Log
    9. Reverse Call Log List
    0. Exit
    Enter your choice: 0
    Exiting program...
*/
