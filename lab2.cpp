#include<iostream>
#define size 7
using namespace std;

//with using hashing technique
//menu
//insertion array
// deletion array
//search value

int arr[size];


void menu(){
    cout << "-------Hashing Method--------" << endl;
    cout << "1. Insert value " << endl;
    cout << "2. delete value " << endl;
    cout << "3. search value "<< endl;
    cout << "4. display " << endl;
    cout << "5. Exit." << endl;
    cout << "-----------------------------" << endl;

    cout << "enter your choice : ";
}

void Array_init(){
    for (int i=0 ; i< size ; i++){
        arr[i] = -1;
    }

    // cout << "Array : " << arr;

}

void insertion(){
    int val;
    cout << "Enter value to insert : ";
    cin >> val;

    int key = val % size;

    if(arr[key] == -1){
        arr[key] = val;
        cout << "the "<< val <<" is inserted at index " << key <<endl;

    }else{
        cout << "at index " << key << "already value "<< arr[key] << "is stored" << endl;
        

        while (arr[(key + 1)%size] != -1 && ((key + 1)%size) != (val %size))
        {
            key++;
        }

        if (((key + 1)%size) == (val %size)){
            cout << "Table is full ->" << endl;;
        }else{
            arr[key + 1] = val;
            cout << "the "<< val <<" is inserted at index " << key + 1 <<endl;
        }
    }

}

void deletion(){


}

void display(){

}

void search_value(){

}

int main()
{
    int ch;
    Array_init();
    do
    {
        menu();
        cin>>ch;
        switch (ch)
        {
        case 1:
            insertion();
            break;

        case 2:
            deletion();
            break;

        case 3:
            search_value();
            break;

        case 4:
            display();
            break;

        case 5:
            cout << " -- Thank you --" << endl;
            break;
        
        default:
            cout << "Invalid choice .... " << endl;
            break;
        }
    } while (ch!=5);
    
    


}