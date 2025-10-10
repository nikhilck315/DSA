#include<iostream>
using namespace std;

struct Node *head = NULL;
// struct Node *ptr, *temp ;
// int val, i, pos, ch;
// int data, val;

void Menu();
void value_init();
void inerst_begin(int val);
void insert_end(int val);
void insert_at_position();
void display(struct Node *head);
void delete_begin();
void delete_end();
struct Node *Reverse();
struct Node *Insert_sort();

struct Node
{
    int data;
    struct Node* next;
};



void Menu(){
    cout << "";
}
void insert_begin(int val){
    struct Node *ptr;
    ptr = new Node();
    if(ptr == NULL){
        cout << "Memory not allocated"<<endl;
        return;
    }
    ptr->data = val;
    ptr->next = head;
    head = ptr;
    cout << "New node is created at begining" << endl;
}

void value_init(){
    int data;
    while (true){
        cout << "Enter the data : ";
        cin >> data;
        if(data == -1){
            break;
        }
        // insert_end(data);
        insert_begin(data);
    }
}


void insert_end(int val){
    struct Node  *ptr, *temp;
    ptr = new Node();
    if(ptr == NULL){
        cout << "Memory is not allocated" <<endl;
    }else if(head == NULL){
            ptr->data = val;
            ptr->next = NULL;
            head = ptr;
            cout << "Node is created at end" <<endl;
        }else{
            ptr->data = val;
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            cout << "Node is created at end"<<endl;
        }
}



void insert_at_position(){
    struct Node *temp , *ptr;
    int val;
    ptr = new Node();
    if(ptr == NULL){
        cout << "Linked list is Empty "<< endl;
    }else{
        int pos;
        cout << "Enter the position : ";
        cin>>pos;
        cout << "Enter Value to insert at " << pos << " : ";
        cin>>val;
        temp = head;
        for(int i=0;i<pos-1;i++){
            temp = temp->next;
            if(temp->next == NULL){
                cout << "Can't insert"<<endl;
            }
        }    
        
    }
    ptr->data = val;
    ptr->next = temp->next;
    temp->next = ptr;

}

struct Node *Reverse(struct Node *head){
    struct Node *prev = NULL , *curr, *nextnode;
    curr = head;
    while(curr != NULL){
        nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }
    return prev;
}

struct Node *Insert_sort(struct Node *head){
    struct Node *ptr,*temp;
    int value;
    ptr = new Node();
    if(ptr == NULL){
        cout << "Memory is not allocated." <<endl;
    }else{
        cout << "ENter the value : " << endl;
        cin>>value;  
        temp = head;
        if(head == NULL){
            ptr->data = value;
            ptr->next = NULL;
            head = ptr;
        }else if(temp->data > value){
            ptr->data = value;
            ptr->next = head;
            head = ptr;
        }else{
            while(temp->next!=NULL && temp->next->data < value){
                temp = temp->next;
            }
            ptr->data = value;
            ptr->next = temp->next;
            temp->next = ptr;
        }
    }
    return head;

}
void display(struct Node *head){
    struct Node *temp;
    cout << "Linked list"<<endl;
    temp = head;
    while (temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" <<endl;
}

int main(){
    int data;
    
    while (true){
        cout << "Enter the data : ";
        cin >> data;
        if(data == -1){
            break;
        }
        // insert_end(data);
        insert_begin(data);
    }
    display(head);
    //display(
    display(Insert_sort(head));

    



    // do {
    //     Menu();
    //     cout << 
    // }
    return 0;
}
