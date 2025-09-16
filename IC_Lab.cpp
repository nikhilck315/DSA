//display a possible subarray of addition od array element is equal to target
//insert element in sorted array


#include <iostream>
using namespace std;

void descending_sort(int arr[], int size);
void ascending_sort(int arr[], int size);
void array_init(int arr[], int &size);
void display_array(int arr[], int size);
void insert_element(int arr[], int size);

int main()
{
    int arr[100], size;
    array_init(arr, size);

    
    descending_sort(arr, size);
    cout << "Array in descending order: ";
    display_array(arr, size);
    if(size >= 3)
        cout << "3rd highest number is: " << arr[2] << endl;

    
    ascending_sort(arr, size);
    cout << "\nArray in ascending order: ";
    display_array(arr, size);
    if(size >= 3)
        cout << "3rd smallest number is: " << arr[2] << endl;

    
    return 0;
}

void array_init(int arr[], int &size){
    cout << "Enter the size of elements: ";
    cin >> size;
    cout << "Enter " << size << " elements: ";
    for (int i=0; i<size ; i++){
        cin >> arr[i];
    } 
}

void descending_sort(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i] < arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
}

void ascending_sort(int arr[], int size){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
}



void display_array(int arr[], int size){
    for(int i=0; i<size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


void insert_element(int arr[], int size){
    int val;
    cout << "Enter val to insert " << endl;
    cin >> val ;

    for (int i = 0; i < size; i++)
    {
        /* code */
    }
    
}