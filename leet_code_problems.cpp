#include <iostream>
using namespace std;

int arr[100];
/*



Problem 48:
    You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
    You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
    1 2 3        7 4 1
    4 5 6    ->  8 5 2
    7 8 9        9 6 3


*/

void Rotate_image(int mat[50][50], int n);
int Remove_element(int arr[], int size);
void display_arr(int arr[], int size);
void Menu();
void array_input();

void array_input()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

}
void matrix_input()
{
    int n;
    cout << " Enter the size of Square matrix(n x n) : ";
    cin >> n;

    int mat[50][50];

    // matrix init
    cout << "Enter the elements of the matrix: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << "\nOrignal matrix : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    
}
int main(int argc, char const *argv[])
{
    Menu();
    return 0;
}

void Menu()
{
    int choice;
    do
    {
        cout << "Menu:\n";
        cout << "1. Remove Element from Array\n";
        cout << "2. Rotate Image (Matrix)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Problem 27: \n";
            cout << " Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.Return k." << endl;
            array_input();
            int size;
            
            int n = Remove_element(arr, size);
            cout << "After removing duplicates: \n";
            display_arr(arr, n);
            break;
        }
        case 2:
        {
            cout << "Problem 48: \n";
            cout << " You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise). You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.\n" << endl;
            int n;
            cout << " Enter the size of Square matrix(n x n) : ";
            cin >> n;

            int mat[50][50];

            // matrix init
            cout << "Enter the elements of the matrix: ";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cin >> mat[i][j];
                }
            }

            cout << "\nOrignal matrix : \n";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }

            Rotate_image(mat, n);
            break;
        }
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

void Rotate_image(int mat[50][50], int n)
{
    // transpose array
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // reverse
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            swap(mat[i][j], mat[i][n - 1 - j]);
        }
    }

    // display matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}



int Remove_element(int arr[], int size)
{
    // time complexity: O(n^2)
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }

        if (count == 1)
        {
            arr[k] = arr[i];
            k++;
        }
    }

    return k;
}

void display_arr(int arr[], int k)
{
    cout << "array: \n";
    for (int i = 0; i < k; i++)
        cout << arr[i] << " ";
    cout << endl;
}
