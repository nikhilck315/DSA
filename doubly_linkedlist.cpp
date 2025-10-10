#include<iostream>
using namespace std;

struct Node {
			int data;
			struct Node *prev, *next;
};

struct Node *head;
int val;

void insert(){
			struct Node *ptr, *temp;
			ptr = new Node();
			if(ptr == NULL) {
				cout << "Memory Not Allocated" << endl;
			}
			
			else {
				cout << " Enter Value : " << endl;
				cin >> val;
				if (head == NULL) {
					ptr->data = val;
					ptr->prev = NULL;
					ptr->next = NULL;
					head  = ptr;
				} else {
					temp = head;
					while (temp->next != NULL) {
						temp= temp->next;
					}
					ptr->data = val;
					ptr->prev = temp;
					ptr->next = NULL;
					temp->next = ptr;
				}
				cout<<"Node Inserted" <<endl;
			}
}

void remove_occurence(Node *head) {
	Node *prev = NULL, *curr = head;
	
	while(curr != NULL) {
		int count = 0;
		Node *temp = head;
		Node *prev = NULL;
		
		while(temp != NULL) {
			if (temp->data == curr->data){
				count++;
				if(count == 2){
					if(prev!= NULL){
						prev->next = temp->next;
						free(temp);
						return;
					}
				}
				prev = temp;
				temp = temp->next;
			}
			curr = curr->next;
		}
	}
}



int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


void bubbleSort(Node* head) {
    if (head == NULL)
        return;

    int n = countNodes(head); 

  
    for (int i = 0; i < n - 1; i++) {
        Node* current = head;
        Node* nextNode = head->next;
        bool swapped = false; 

        for (int j = 0; j < n - i - 1; j++) {
            if (current->data > nextNode->data) {
              
                int temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
                swapped = true;
            }
            current = nextNode;
            nextNode = nextNode->next;
        }

        if (!swapped) break; 
    }
}