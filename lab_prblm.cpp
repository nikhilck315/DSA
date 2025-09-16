#include<iostream>
using namespace std;

int arr[100];
int size;

/*  
    - sort array
    - move the zeros to end of an array 
*/

void sort_ending_with_zero(int arr[], int size);
void insertion_sort(int arr[], int size);
void display_Sorted_arr(int arr[], int size);
void array_input();
void prime_factors();


int main(int argc, char const *argv[])
{
    array_input();
    sort_ending_with_zero(arr, size);
    display_Sorted_arr(arr, size);
    return 0;
}

void prime_factors(){
    int n;
    cout << "Enter the number: ";
    cin>>n;

    // check the n is divided by 2
    // then remaing n will be odd 
    // write the condition for odd number (for 3, 5, )
    // if still n > 2 then it is prime


}

void array_input()
{
    cout << "Enter the size of the array: ";
    cin >> size;
    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

}

void sort_ending_with_zero(int arr[], int size){
    insertion_sort(arr, size);
    //now move all zeros to end 
    int count = 0;
    for(int i=0; i<size; i++){
        if(arr[i] != 0){
            arr[count++] = arr[i];
        }
    }
    while(count < size){
        arr[count++] = 0;
    }

}

void insertion_sort(int arr[], int size){
    int key, j;
    for(int i=1; i<size; i++){
        key = arr[i];
        j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

}

void display_Sorted_arr(int arr[], int size){
    cout << "Sorted array: \n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}