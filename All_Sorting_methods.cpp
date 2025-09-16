#include<iostream>
using namespace std;

int arr[100];
int size;


void Menu();
void array_input();
void Quick_sort(int arr[], int first,int last);
void merge_sort(int arr[], int lb, int ub);
void merge(int arr[], int l, int m, int r);
void display_Sorted_arr(int arr[], int size);
int max_value(int arr[], int size);
void counting_sort(int arr[], int size , int max);
void radix_sort(int arr[], int size);
void counting_sort_for_radix_sort(int arr[], int size, int exp);





int main(int argc, char const *argv[])
{
    
    int choice;
    do{
        Menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
        case 1:{
            array_input();
            Quick_sort(arr, 0, size-1);
            display_Sorted_arr(arr, size);
            break;
            }
        case 2:{
            array_input();
            merge_sort(arr, 0, size - 1);
            display_Sorted_arr(arr, size);
            break;
            }
        case 3:{
            array_input();
            int max = max_value(arr, size);
            counting_sort(arr, size, max);
            break;
            }

        case 4:{
            array_input();
            radix_sort(arr, size);
            display_Sorted_arr(arr, size);
            break;
        }
        case 5:{
            cout << "Exiting the program." << endl;
            break;
            }
        default:{
            cout << "Invalid choice. Please try again." << endl;
            break;
            }
        }
    }while(choice != 5);
    return 0;
}

void Menu(){
    cout << "Menu:\n";
    cout << "1. Quick Sort\n";
    cout << "2. Merge Sort\n";
    cout << "3. Counting Sort\n";
    cout << "4. Radix Sort\n";
    cout << "5. Exit\n";
    cout << "-------------------";
}

void array_input(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    
    cout << "Enter the elements of the array: ";
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

}

int max_value(int arr[], int size){
    int max = arr[0];
    for(int i=1; i<size; i++){
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}

void counting_sort(int arr[] , int size , int max){
    int count[max+1] = {0};
    for(int i = 0 ; i < size ; i++){
        count[arr[i]]++;
    }

    for (int i = 0 ; i<=max ; i++){
        count[i]+=count[i-1];
    }

    int b[size] = {0};
    for(int i = size-1 ; i >= 0; i--){
        b[--count[arr[i]]] = arr[i];
    }

    for (int i=0; i<size ; i++){
        arr[i]=b[i];
    }

    //array display (sorted)

    cout << "Array after counting sort : ";
    for (int i=0; i< size; i++){
        cout << arr[i] << " ";
    }
}
    
void radix_sort(int arr[], int size){
    int max = max_value(arr, size);
    for(int exp = 1; max/exp > 0; exp *= 10)
        counting_sort_for_radix_sort(arr, size, exp);
}

void counting_sort_for_radix_sort(int arr[], int size, int exp){
    int output[size];
    int count[10] = {0};

    for(int i=0; i<size; i++)
        count[(arr[i]/exp)%10]++;

    for(int i=1; i<10; i++)
        count[i] += count[i-1];

    for(int i=size-1; i>=0; i--){
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(int i=0; i<size; i++)
        arr[i] = output[i];
}



void display_Sorted_arr(int arr[], int size){
    cout << "Sorted array: \n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void Quick_sort(int arr[], int first,int last){

    int i, j, pivot, temp;
    if(first<last){
        pivot=first;
        i=first;
        j=last;

        while(i<j){
            while(arr[i]<=arr[pivot]&&i<last)
                i++;
            while(arr[j]>arr[pivot])
                j--;
            if(i<j){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }

        temp=arr[pivot];
        arr[pivot]=arr[j];
        arr[j]=temp;
        Quick_sort(arr,first,j-1);
        Quick_sort(arr,j+1,last);
    }
}



void merge_sort(int arr[], int lb, int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        merge_sort(arr,lb,mid);
        merge_sort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i=0; i<n1; i++)
        L[i] = arr[l+i];
    for(j=0; j<n2; j++)
        R[j] = arr[m+1+j];

    i=0;
    j=0;
    k=l;

    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
