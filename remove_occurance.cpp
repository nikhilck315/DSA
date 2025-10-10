#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *prev, *next;
};
int val;
struct Node *head;
int menu(){
    cout<<"1.Insert element"<<endl;
    cout<<"2.display sorted linked list"<<endl;
    cout<<"3.remove doble occured element."<<endl;
    cout<<"4.exit"<<endl;
    cout << "ENter your choice : ";
}
void insert_last(){
    struct Node *ptr, *temp;
    ptr = new Node();
    if(ptr == NULL) cout << "Memory is not allocated" <<endl;
    else {
        cout << "Enter value : ";
        cin>>val;
        if(head==NULL){
            ptr->data = val;
            ptr->prev = NULL;
            ptr->next = NULL;
            head = ptr;
        }
        else{
            temp=head;
            while(temp->next!=NULL) temp = temp->next;
            ptr->data=val;
            ptr->next=NULL;
            ptr->prev=temp;
            temp->next=ptr;
        }
        
    }
    cout << "Node is inserted " <<endl;
}

void remove_occur(Node* head)
 {
    Node* prev = NULL;
    Node* curr = head;

    // For every node, check how many times it appears
    while (curr != NULL) {
        int count = 0;
        Node* temp = head;
        Node* prev = NULL;

        // Count occurrences of curr->data
        while (temp != NULL) {
            if (temp->data == curr->data) {
                count++;
                if (count == 2) {  // Found second occurrence
                    if (prev != nullptr)
                        prev->next = temp->next; // unlink node
                    free(temp); // free memory
                    return;      // stop after removing second occurrence
                }
            }
            prev = temp;
            temp = temp->next;
        }
        curr = curr->next;
    }
}

void display(){
    struct Node *temp=head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    int ch;
    do
    {
        ch = menu();
        
    } while (ch!=4);
    

    
    // insert_last();
    display();
    return 0;
}

