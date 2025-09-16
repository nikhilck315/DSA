/* 
	-------   Practical no 3.1 : Fibonacci Search--------------

	Name : Nikheel C Khadakabhavi
	PRN : 202401110020
	Batch : A1

	-----------------------------------------------
*/

#include <iostream>
using namespace std;

int min(int x, int y){ return (x <= y) ? x : y; }

int fibonacciSearch(int arr[], int n, int key, int &comparisons)
{
    int fib2 = 0;
    int fib1 = 1;
    int fibM = fib2 + fib1;

    // Find the smallest Fibonacci number greater than or equal to n
    while (fibM < n)
    {
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib2 + fib1;
    }

    int offset = -1;

    while (fibM > 1)
    {
        int i = min(offset + fib2, n - 1);

        comparisons++;
        if (arr[i] < key)
        {
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;
            offset = i;
        }
        else if (arr[i] > key)
        {
            fibM = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibM - fib1;
        }
        else
        {
            return i;
        }
    }

    if (fib1 && arr[offset + 1] == key)
    {
        comparisons++;
        return offset + 1;
    }

    return -1;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int comparisons = 0;
    int pos = fibonacciSearch(arr, n, key, comparisons);

    cout << "\nNumber of comparisons made: " << comparisons << endl;

    if (pos != -1)
    {
        cout << "Element found at position (0-based index): " << pos << endl;
        cout << "Element found at position (1-based index): " << pos + 1 << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

/*output

    Enter number of elements: 7
    Enter 7 sorted elements: 10 22 35 40 45 50 80
    Enter element to search: 45

    Number of comparisons made: 3
    Element found at position (0-based index): 4
    Element found at position (1-based index): 5

*/