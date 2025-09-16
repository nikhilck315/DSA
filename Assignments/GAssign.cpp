#include <iostream>
using namespace std;

const int totalSpots = 10;

struct ParkingSpot {
    int carNumber;
    bool taken;
};

int getSpotNumber(int carNum) {
    return carNum % totalSpots;
}

int findCar(ParkingSpot lot[], int carNum) {
    int spot = getSpotNumber(carNum);
    int startSpot = spot;
    while (lot[spot].taken && lot[spot].carNumber != carNum) {
        spot = (spot + 1) % totalSpots;
        if (spot == startSpot) return -1;
    }
    if (lot[spot].taken && lot[spot].carNumber == carNum)
        return spot;
    return -1;
}

bool parkCar(ParkingSpot lot[], int carNum) {
    int spot = getSpotNumber(carNum);
    int startSpot = spot;
    while (lot[spot].taken) {
        if (lot[spot].carNumber == carNum) {
            cout << "Hey! Your car is already parked at spot " << spot << "\n";
            return false;
        }
        spot = (spot + 1) % totalSpots;
        if (spot == startSpot) {
            cout << "Oops! Parking is full.\n";
            return false;
        }
    }
    lot[spot].carNumber = carNum;
    lot[spot].taken = true;
    cout << "Parked your car at spot " << spot << "\n";
    return true;
}

bool removeCar(ParkingSpot lot[], int carNum) {
    int spot = findCar(lot, carNum);
    if (spot == -1) {
        cout << "Can't find your car here.\n";
        return false;
    }
    lot[spot].taken = false;
    cout << "Removed your car from spot " << spot << "\n";
    return true;
}

void showParking(ParkingSpot lot[]) {
    cout << "\nHere's the parking status:\n";
    for (int i = 0; i < totalSpots; i++) {
        if (lot[i].taken)
            cout << "Spot " << i << ": Car number " << lot[i].carNumber << "\n";
        else
            cout << "Spot " << i << ": Empty\n";
    }
}

int main() {
    ParkingSpot parkingLot[totalSpots];
    for (int i = 0; i < totalSpots; i++) {
        parkingLot[i].taken = false;
        parkingLot[i].carNumber = -1;
    }

    int choice;
    int carNum;

    while (true) {
        cout << "\nWhat do you want to do?\n";
        cout << "1. Park a car\n";
        cout << "2. Find a car\n";
        cout << "3. Remove a car\n";
        cout << "4. See parking spots\n";
        cout << "5. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter your car's number: ";
            cin >> carNum;
            parkCar(parkingLot, carNum);
        } 
        else if (choice == 2) {
            cout << "Enter car number to find: ";
            cin >> carNum;
            int spot = findCar(parkingLot, carNum);
            if (spot == -1)
                cout << "No car with that number found.\n";
            else
                cout << "Your car is parked at spot " << spot << "\n";
        } 
        else if (choice == 3) {
            cout << "Enter car number to remove: ";
            cin >> carNum;
            removeCar(parkingLot, carNum);
        } 
        else if (choice == 4) {
            showParking(parkingLot);
        } 
        else if (choice == 5) {
            cout << "Alright, see ya!\n";
            break;
        } 
        else {
            cout << "Hmm, I didn't get that. Try again.\n";
        }
    }
    return 0;
}