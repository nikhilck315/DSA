/* 
	-------   Practical no 3.2 : Sentinal Search--------------

	Name : Nikheel C Khadakabhavi
	PRN : 202401110020
	Batch : A1

	-----------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

struct Friend {
    string name;
    string mobile;
};

void insertSorted(Friend phoneBook[], int &n, string name, string mobile) {
    int i = n - 1;

    while (i >= 0 && phoneBook[i].name > name) {
        phoneBook[i + 1] = phoneBook[i];
        i--;
    }
    phoneBook[i + 1].name = name;
    phoneBook[i + 1].mobile = mobile;
    n++;
}

int sentinelSearch(Friend phoneBook[], int n, string key, int &comparisons) {
    phoneBook[n].name = key;  // Place sentinel at end
    int i = 0;

    while (phoneBook[i].name != key) {
        i++;
        comparisons++;
    }

    if (i < n) {
        return i; // Found
    }
    return -1; // Not found
}

int main() {
    int n;
    cout << "Enter number of friends: ";
    cin >> n;

    Friend phoneBook[50]; // Max 50 friends for simplicity

    cout << "Enter names and mobile numbers in sorted order:\n";
    for (int i = 0; i < n; i++) {
        cout << "Friend " << i + 1 << " Name: ";
        cin >> phoneBook[i].name;
        cout << "Mobile Number: ";
        cin >> phoneBook[i].mobile;
    }

    string searchName;
    cout << "\nEnter name to search: ";
    cin >> searchName;

    int comparisons = 0;
    int pos = sentinelSearch(phoneBook, n, searchName, comparisons);

    if (pos != -1) {
        cout << "\nFriend Found!\n";
        cout << "Name: " << phoneBook[pos].name << ", Mobile: " << phoneBook[pos].mobile << endl;
    } else {
        cout << "\nFriend not found! Adding to phone book.\n";
        string mobile;
        cout << "Enter mobile number for " << searchName << ": ";
        cin >> mobile;
        insertSorted(phoneBook, n, searchName, mobile);

        cout << "\nUpdated Phone Book:\n";
        for (int i = 0; i < n; i++) {
            cout << phoneBook[i].name << " - " << phoneBook[i].mobile << endl;
        }
    }

    cout << "\nNumber of comparisons made: " << comparisons << endl;

    return 0;
}


/*Output
Enter number of friends: 3
Enter names and mobile numbers in sorted order: 
Friend 1 Name: Nikhil
Mobile Number: 9025216542    
Friend 2 Name: Swapnil
Mobile Number: 7825571785
Friend 3 Name: Vivek
Mobile Number: 8254351267

Enter name to search: narayan
Friend not found! Adding to phone book. 
Enter mobile number for narayan: 7242853562
Updated Phone Book:
Nikhil - 9025216542
Swapnil - 7825571785
Vivek - 8254351267
narayan - 7242853562
Number of comparisons made: 4
*/