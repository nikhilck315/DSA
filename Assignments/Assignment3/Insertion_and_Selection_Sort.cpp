/* 
    -------   Practical no 3.3 : Insertion and Selection Sort--------------
 
    Name : Nikheel C Khadakabhavi
    PRN : 202401110020
    Batch : A1

    -----------------------------------------------
*/

#include <iostream>
using namespace std;

void selectionSort(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        //swap
        double temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(double arr[], int n) {
    for (int i = 1; i < n; i++) {
        double key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// display Top 5 highest salaries
void displayTopFive(double arr[], int n) {
    cout << "\nTop 5 highest salaries:\n";
    int count = (n < 5) ? n : 5;
    for (int i = n - 1; i >= n - count; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    double salaries[100];  // assuming max 100 employees
    cout << "Enter salaries of employees:\n";
    for (int i = 0; i < n; i++) {
        cin >> salaries[i];
    }

    // --- Selection Sort ---
    double selArr[100];
    for (int i = 0; i < n; i++) selArr[i] = salaries[i];

    selectionSort(selArr, n);
    cout << "\nSalaries sorted using Selection Sort:\n";
    for (int i = 0; i < n; i++) cout << selArr[i] << " ";
    cout << endl;
    displayTopFive(selArr, n);

    // --- Insertion Sort ---
    double insArr[100];
    for (int i = 0; i < n; i++) insArr[i] = salaries[i];

    insertionSort(insArr, n);
    cout << "\nSalaries sorted using Insertion Sort:\n";
    for (int i = 0; i < n; i++) cout << insArr[i] << " ";
    cout << endl;
    displayTopFive(insArr, n);

    return 0;
}

/*Output:
    Enter number of employees: 7
    Enter salaries of employees:
    55000
    72000
    48000
    91000
    66000
    83000
    59000

    Salaries sorted using Selection Sort:
    48000 55000 59000 66000 72000 83000 91000

    Top 5 highest salaries:
    91000 83000 72000 66000 59000

    Salaries sorted using Insertion Sort:
    48000 55000 59000 66000 72000 83000 91000

    Top 5 highest salaries:
    91000 83000 72000 66000 59000
*/
